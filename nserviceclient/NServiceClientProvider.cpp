//
// Created by strohhalm on 28.06.15.
//

#include "NServiceClientProvider.h"

namespace nox
{
    namespace service
    {
        namespace client
        {
            NServiceClientProvider::NServiceClientProvider() : INSingleton<NServiceClientProvider>()
            {
                m_FactoryMap = new NMap<NString, INServiceClientFactory *>();
                m_PluginMap = new NMap<NString, NPlugin *>();
                m_ServiceConfigCache = new NServiceClientConfigCache();
                m_FactoryConfigCache = new NServiceClientFactoryConfigCache();
                try
                {
                    this->init();
                }
                catch (...)
                {
                    if (m_FactoryMap != NULL)
                    {
                        INList<NString> * keyList = m_FactoryMap->getKeyList();
                        for (int i = 0; i < keyList->getSize(); i++)
                        {
                            NServiceClientFactoryConfig * config = m_FactoryConfigCache->get(keyList->get(i));
                            if (config != NULL)
                            {
                                NPlugin * plugin = m_PluginMap->get(config->getLibrary());
                                if (plugin != NULL)
                                {
                                    try
                                    {
                                        plugin->executeFunction<void, INServiceClientFactory *>(
                                                "destroyServiceClientFactory", m_FactoryMap->get(keyList->get(i)));
                                    }
                                    catch (NException & exp)
                                    {
                                        if (m_FactoryMap->get(keyList->get(i)) != NULL)
                                            delete m_FactoryMap->get(keyList->get(i));
                                    }
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
            }

            NServiceClientProvider::~NServiceClientProvider()
            {
                if (m_FactoryMap != NULL)
                {
                    INList<NString> * keyList = m_FactoryMap->getKeyList();
                    for (int i = 0; i < keyList->getSize(); i++)
                    {
                        NServiceClientFactoryConfig * config = m_FactoryConfigCache->get(keyList->get(i));
                        if (config != NULL)
                        {
                            NPlugin * plugin = m_PluginMap->get(config->getLibrary());
                            if (plugin != NULL)
                            {
                                try
                                {
                                    plugin->executeFunction<void, INServiceClientFactory *>(
                                            "destroyServiceClientFactory", m_FactoryMap->get(keyList->get(i)));
                                }
                                catch (NException & exp)
                                {
                                    if (m_FactoryMap->get(keyList->get(i)) != NULL)
                                        delete m_FactoryMap->get(keyList->get(i));
                                }
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

            void NServiceClientProvider::init()
            {
                if (m_FactoryConfigCache != NULL)
                {
                    INList<NServiceClientFactoryConfig *> * configList = m_FactoryConfigCache->getAll();
                    if (configList != NULL)
                    {
                        NServiceClientFactoryConfig * config = NULL;
                        for (int i = 0; i < configList->getSize(); i++)
                        {
                            config = configList->get(i);
                            if (config != NULL)
                            {
                                NPlugin * plugin = loadPlugin(config->getLibrary());
                                if (plugin != NULL)
                                {
                                    INServiceClientFactory * factory = NULL;
                                    try
                                    {
                                        factory = plugin->executeFunction<INServiceClientFactory *, const NString &>(
                                                "createServiceClientFactory", config->getFactory());
                                    }
                                    catch (NException & exp)
                                    {
                                        factory = NULL;
                                    }
                                    if (factory != NULL)
                                    {
                                        m_FactoryMap->add(config->getName(), factory);
                                    }
                                    else
                                    {
                                        throw NRuntimeException("Could not create Factory");
                                    }
                                }
                                else
                                {
                                    throw NRuntimeException("Could not create Plugin");
                                }
                            }
                        }
                    }
                }
            }

            NPlugin * NServiceClientProvider::loadPlugin(const NString & libName)
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

            INServiceClient* NServiceClientProvider::loadServiceClient(const NString & serviceClientName)
            {
                NServiceClientConfig * config = m_ServiceConfigCache->get(serviceClientName);
                if (config != NULL)
                {
                    if (m_FactoryMap->contains(config->getFactory()))
                    {
                        INServiceClientFactory * factory = m_FactoryMap->get(config->getFactory());
                        if (factory != NULL)
                        {
                            if (config->getHost().length() > 0)
                                return factory->createServiceClient(config->getServiceClient(), config->getProtocol(), config->getHost(), config->getPort().toString());
                            return factory->createServiceClient(config->getServiceClient(), config->getProtocol(), config->getPort().toString());
                        }
                    }
                }
                return NULL;
            }

            nint NServiceClientProvider::compareTo(const INObject * other) const
            {
                if (this == other)
                    return 0;
                try
                {
                    const NServiceClientProvider * obj = dynamic_cast<const NServiceClientProvider *>(other);
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
}