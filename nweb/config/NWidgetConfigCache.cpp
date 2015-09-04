//
// Created by strohhalm on 04.09.15.
//

#include <nweb/config/NWidgetConfigCache.h>

namespace nox
{
    namespace web
    {
        namespace configuration
        {

            NWidgetConfigCache::NWidgetConfigCache() : INConfigurationCache<NString, NWidgetConfig>(NXS(widget))
            {
            }

            NWidgetConfigCache::~NWidgetConfigCache()
            {
            }

            void NWidgetConfigCache::load()
            {
                INList<NWidgetConfigFile *> * configFileList = NResourcePool::getResources<NWidgetConfigFile>(NXS(widget), XML_SUFFIX);
                if (configFileList != NULL)
                {
                    for (nlong i = 0; i < configFileList->getSize(); i++)
                    {
                        loadFile(configFileList->get(i));
                    }
                    delete configFileList;
                }
            }

            void NWidgetConfigCache::loadFile(NWidgetConfigFile * file)
            {
                INList<NWidgetConfig *> * configList = NULL;
                try
                {
                    if (file != NULL)
                    {
                        configList = file->parse();

                        if (configList != NULL)
                        {
                            for (nlong i = 0; i < configList->getSize(); i++)
                            {
                                NWidgetConfig * config = configList->get(i);

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