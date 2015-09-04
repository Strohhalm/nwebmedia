//
// Created by strohhalm on 04.09.15.
//

#include <nweb/NWidgetProvider.h>

namespace nox
{
    namespace web
    {
        NWidgetProvider::NWidgetProvider() : INSingleton<NWidgetProvider>()
        {
            m_PluginMap = new NMap<NString, NPlugin *>();
            m_FactoryMap = new NMap<NString, INWidgetFactory *>();

            m_FactoryConfigCache = new NWidgetFactoryConfigCache();
            m_WidgetConfigCache  = new NWidgetConfigCache();

            init();
        }

        NWidgetProvider::~NWidgetProvider()
        {
            if (m_FactoryMap != NULL)
            {
                INList<NString> * keyList = m_FactoryMap->getKeyList();
                for (int i = 0; i < keyList->getSize(); i++)
                {
                    NWidgetFactoryConfig * config = m_FactoryConfigCache->get(keyList->get(i));
                    if (config != NULL)
                    {
                        NPlugin * plugin = m_PluginMap->get(config->getLibrary());
                        if (plugin != NULL)
                        {
                            try
                            {
                                plugin->executeFunction<void, INWidgetFactory *>(NXS(destroyWidgetFactory), m_FactoryMap->get(keyList->get(i)));
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
            if (m_WidgetConfigCache != NULL)
                delete m_WidgetConfigCache;
        }

        void NWidgetProvider::init()
        {
            INList<NWidgetFactoryConfig *> * configList = m_FactoryConfigCache->getAll();

            if (configList != NULL)
            {
                NWidgetFactoryConfig * config = NULL;
                for (int i = 0; i < configList->getSize(); i++)
                {
                    config = configList->get(i);
                    if (config != NULL)
                    {
                        NPlugin * plugin = loadPlugin(config->getLibrary());
                        if (plugin != NULL)
                        {
                            INWidgetFactory * factory = NULL;
                            try
                            {
                                factory = plugin->executeFunction<INWidgetFactory *, const NString &>(NXS(createWidgetFactory), config->getFactory());
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

        NPlugin * NWidgetProvider::loadPlugin(const NString & libName)
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

        INWidget * NWidgetProvider::getWidget(const NString & viewName)
        {
            NWidgetConfig * config = m_WidgetConfigCache->get(viewName);
            if (config != NULL)
            {
                INWidgetFactory * factory = m_FactoryMap->get(config->getFactory());
                if (factory != NULL)
                {
                    INWidget * widget = factory->createWidget(config->getWidget());

                    if (widget != NULL)
                        widget->initialize();

                    return widget;
                }
            }
            return NULL;
        }

        nint NWidgetProvider::compareTo(const INObject * other) const
        {
            if (this == other)
                return 0;
            try
            {
                const NWidgetProvider * obj = dynamic_cast<const NWidgetProvider *>(other);

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