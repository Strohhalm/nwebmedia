//
// Created by strohhalm on 04.09.15.
//

#include <nweb/config/NWidgetFactoryConfigCache.h>

namespace nox
{
    namespace web
    {
        namespace configuration
        {

            NWidgetFactoryConfigCache::NWidgetFactoryConfigCache() : INConfigurationCache<NString, NWidgetFactoryConfig>(NXS(widgetfactory))
            {
            }

            NWidgetFactoryConfigCache::~NWidgetFactoryConfigCache()
            {
            }

            void NWidgetFactoryConfigCache::load()
            {
                INList<NWidgetFactoryConfigFile *> * configFileList = NResourcePool::getResources<NWidgetFactoryConfigFile>(NXS(widgetfactory), XML_SUFFIX);
                if (configFileList != NULL)
                {
                    for (nlong i = 0; i < configFileList->getSize(); i++)
                    {
                        loadFile(configFileList->get(i));
                    }
                    delete configFileList;
                }
            }

            void NWidgetFactoryConfigCache::loadFile(NWidgetFactoryConfigFile * file)
            {
                INList<NWidgetFactoryConfig *> * configList = NULL;
                try
                {
                    if (file != NULL)
                    {
                        configList = file->parse();
                        if (configList != NULL)
                        {
                            for (nlong i = 0; i < configList->getSize(); i++)
                            {
                                NWidgetFactoryConfig * config = configList->get(i);

                                if (!m_ConfigurationCache->contains(config->getName()))
                                {
                                    m_ConfigurationCache->add(config->getName(), config);
                                }
                                else
                                {
                                    delete config;
                                    //TODO: log Warning
                                }
                            }
                            delete configList;
                        }
                        delete file;
                    }
                }
                catch (...)
                {
                    if (configList != NULL)
                    {
                        for (nlong i = 0; i < configList->getSize(); i++)
                        {
                            if (configList->get(i) != NULL)
                                delete configList->get(i);
                        }
                        delete configList;
                    }
                    if (file != NULL)
                        delete file;
                }
            }
        }
    }
}