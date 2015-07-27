//
// Created by strohhalm on 17.06.15.
//

#include "NServiceProvider.h"
#include <nservice/config/NServiceConfigFile.h>
#include <nservice/config/NServiceFactoryConfigFile.h>

using namespace nox::resource;
using namespace nox::service::configuration;

namespace nox
{
    namespace service
    {
        NServiceProvider::NServiceProvider() : INSingleton<NServiceProvider>()
        {
            m_PluginMap = new NMap<NString, NPlugin *>();
            m_FactoryMap = new NMap<NString, IINServiceFactory *>();
            m_ServiceMap = new NMap<NString, INService *>();

            m_FactoryConfigCache = new NServiceFactoryConfigCache();
            m_ServiceConfigCache = new NServiceConfigCache();

            init();
        }

        NServiceProvider::~NServiceProvider()
        {
            if (m_ServiceMap != NULL)
            {
                INList<NString> * keyList = m_ServiceMap->getKeyList();
                for (int i = 0; i < keyList->getSize(); i++)
                {
                    if (m_ServiceMap->get(keyList->get(i)) != NULL)
                        delete m_ServiceMap->get(keyList->get(i));
                }
                delete m_ServiceMap;
            }
            if (m_FactoryMap != NULL)
            {
                INList<NString> * keyList = m_FactoryMap->getKeyList();
                for (int i = 0; i < keyList->getSize(); i++)
                {
                    NServiceFactoryConfig * config = m_FactoryConfigCache->get(keyList->get(i));
                    if (config != NULL)
                    {
                        NPlugin * plugin = m_PluginMap->get(config->getLibrary());
                        if (plugin != NULL)
                        {
                            try
                            {
                                plugin->executeFunction<void, IINServiceFactory *>("destroyServiceFactory",
                                                                                   m_FactoryMap->get(keyList->get(i)));
                            }
                            catch (NException & exp)
                            {
                                if (m_FactoryMap->get(keyList->get(i)) != NULL)
                                    delete m_FactoryMap->get(keyList->get(i));
                            }
                        }
                        else
                        {
                            if (m_FactoryMap->get(keyList->get(i)) != NULL)
                                delete m_FactoryMap->get(keyList->get(i));
                        }
                    }
                }
                delete m_FactoryMap;
            }
            if (m_PluginMap != NULL)
            {
                INList<NString> * keyList = m_PluginMap->getKeyList();
                for (int i = 0; i < keyList->getSize(); i++)
                {
                    if (m_PluginMap->get(keyList->get(i)) != NULL)
                        delete m_PluginMap->get(keyList->get(i));
                }
                delete m_PluginMap;
            }
            if (m_FactoryConfigCache != NULL)
                delete m_FactoryConfigCache;
            if (m_ServiceConfigCache != NULL)
                delete m_ServiceConfigCache;
        }

        void NServiceProvider::init()
        {
            loadFactories();
            loadServices();
        }

        void NServiceProvider::run()
        {
            INList<NString> * keyList = m_ServiceMap->getKeyList();
            if (keyList != NULL)
            {
                for (int i = 0; i < keyList->getSize(); i++)
                {
                    if (m_ServiceMap->get(keyList->get(i)) != NULL)
                        m_ServiceMap->get(keyList->get(i))->listen();
                }
            }
        }

        void NServiceProvider::loadFactories()
        {
            INList<NServiceFactoryConfig *> * configList = m_FactoryConfigCache->getAll();
            if (configList != NULL)
            {
                NServiceFactoryConfig * config = NULL;
                for (int i = 0; i < configList->getSize(); i++)
                {
                    config = configList->get(i);
                    if (config != NULL)
                    {
                        NPlugin * plugin = loadPlugin(config->getLibrary());
                        if (plugin != NULL)
                        {
                            IINServiceFactory * factory = NULL;
                            try
                            {
                                factory = plugin->executeFunction<IINServiceFactory *, const NString &>(
                                        "createServiceFactory", config->getFactory());
                            }
                            catch (NException &)
                            {
                                factory = NULL;
                            }
                            if (factory != NULL)
                            {
                                m_FactoryMap->add(config->getFactory(), factory);
                            }
                            else
                            {
                                throw NRuntimeException("Could not create factory");
                            }
                        }
                        else
                        {
                            throw NRuntimeException("Could not load Plugin");
                        }
                    }
                }
            }
        }

        void NServiceProvider::loadServices()
        {
            INList<NServiceConfig *> * configList = m_ServiceConfigCache->getAll();

            if (configList != NULL)
            {
                NServiceConfig * config = NULL;
                for (int i = 0; i < configList->getSize(); i++)
                {
                    config = configList->get(i);
                    if (config != NULL)
                    {
                        IINServiceFactory * factory = m_FactoryMap->get(config->getFactory());
                        if (factory != NULL)
                        {
                            INService * socket = factory->createService(*config);
                            if (socket != NULL)
                            {
                                m_ServiceMap->add(config->getService(), socket);
                            }
                            else
                            {
                                throw NRuntimeException("Could not create service");
                            }
                        }
                        else
                        {
                            throw NRuntimeException("No factory found for service");
                        }
                    }
                }
            }
        }

        NPlugin * NServiceProvider::loadPlugin(const NString & libName)
        {
            if (!m_PluginMap->contains(libName))
            {
                NPlugin * plugin = NResourcePool::getResource<NPlugin>(libName);
                if (plugin != NULL)
                {
                    m_PluginMap->add(libName, plugin);
                }
            }
            return m_PluginMap->get(libName);
        }

        nint NServiceProvider::compareTo(const INObject * other) const
        {
            if (this == other)
                return 0;
            try
            {
                const NServiceProvider * obj = dynamic_cast<const NServiceProvider *>(other);

                if (obj != NULL)
                {
                    if (this > obj)
                        return 1;
                    return -1;
                }
                else
                {
                    return 1;
                }
            }
            catch (bad_cast &)
            {
                return 1;
            }
        }
    }
}
