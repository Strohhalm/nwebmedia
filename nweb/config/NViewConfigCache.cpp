//
// Created by strohhalm on 29.06.15.
//

#include "NViewConfigCache.h"
#include "NViewConfigFile.h"

namespace nox
{
    namespace web
    {
        namespace configuration
        {

            NViewConfigCache::NViewConfigCache() : INConfigurationCache<NString, NViewConfig>(NXS(view))
            {
            }

            NViewConfigCache::~NViewConfigCache()
            {
            }

            void NViewConfigCache::load()
            {
                INList<NViewConfigFile *> * configFileList = NResourcePool::getResources<NViewConfigFile>("view", XML_SUFFIX);
                if (configFileList != NULL)
                {
                    for (nlong i = 0; i < configFileList->getSize(); i++)
                    {
                        loadFile(configFileList->get(i));
                    }
                    delete configFileList;
                }
            }

            void NViewConfigCache::loadFile(NViewConfigFile * file)
            {
                INList<NViewConfig *> * configList = NULL;
                try
                {
                    if (file != NULL)
                    {
                        configList = file->parse();

                        if (configList != NULL)
                        {
                            for (nlong i = 0; i < configList->getSize(); i++)
                            {
                                NViewConfig * config = configList->get(i);

                                if (!m_ConfigurationCache->contains(config->getView()))
                                {
                                    m_ConfigurationCache->add(config->getView(), config);
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