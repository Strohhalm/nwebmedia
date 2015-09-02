//
// Created by strohhalm on 29.06.15.
//

#include "NViewProvider.h"
#include "INMasterView.h"

namespace nox
{
    namespace web
    {
        NViewProvider::NViewProvider() : INSingleton<NViewProvider>()
        {
            m_PluginMap = new NMap<NString, NPlugin *>();
            m_FactoryMap = new NMap<NString, INViewFactory *>();

            m_FactoryConfigCache = new NViewFactoryConfigCache();
            m_ViewConfigCache = new NViewConfigCache();

            init();
        }

        NViewProvider::~NViewProvider()
        {
            if (m_FactoryMap != NULL)
            {
                INList<NString> * keyList = m_FactoryMap->getKeyList();
                for (int i = 0; i < keyList->getSize(); i++)
                {
                    NViewFactoryConfig * config = m_FactoryConfigCache->get(keyList->get(i));
                    if (config != NULL)
                    {
                        NPlugin * plugin = m_PluginMap->get(config->getLibrary());
                        if (plugin != NULL)
                        {
                            try
                            {
                                plugin->executeFunction<void, INViewFactory *>("destroyViewFactory", m_FactoryMap->get(keyList->get(i)));
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
                    else
                    {
                        if (m_FactoryMap->get(keyList->get(i)) != NULL)
                            delete m_FactoryMap->get(keyList->get(i));
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
            if (m_ViewConfigCache != NULL)
                delete m_ViewConfigCache;
        }

        void NViewProvider::init()
        {
            INList<NViewFactoryConfig *> * configList = m_FactoryConfigCache->getAll();

            if (configList != NULL)
            {
                NViewFactoryConfig * config = NULL;
                for (int i = 0; i < configList->getSize(); i++)
                {
                    config = configList->get(i);
                    if (config != NULL)
                    {
                        NPlugin * plugin = loadPlugin(config->getLibrary());
                        if (plugin != NULL)
                        {
                            INViewFactory * factory = NULL;
                            try
                            {
                                factory = plugin->executeFunction<INViewFactory *, const NString &>("createViewFactory", config->getFactory());
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
                            throw NRuntimeException("Could not load Plugin");
                        }
                    }
                }
            }
        }

        NPlugin * NViewProvider::loadPlugin(const NString & libName)
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

        INView * NViewProvider::getView(const NString & viewName)
        {
            NViewConfig * config = m_ViewConfigCache->get(viewName);
            if (config != NULL)
            {
                INViewFactory * factory = m_FactoryMap->get(config->getFactory());
                if (factory != NULL)
                {
                    INView * view = factory->createView(config->getView());

                    view->setViewName(config->getName());
                    if (view != NULL)
                        view->initialize();

                    return view;
                }
            }
            return NULL;
        }

        nint NViewProvider::compareTo(const INObject * other) const
        {
            if (this == other)
                return 0;
            try
            {
                const NViewProvider * obj = dynamic_cast<const NViewProvider *>(other);

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