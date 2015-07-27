//
// Created by strohhalm on 30.06.15.
//

#include "NNavigationConfigCache.h"
#include "NNavigationConfigFile.h"

namespace nox
{
    namespace web
    {
        namespace configuration
        {

            NNavigationConfigCache::NNavigationConfigCache() : INConfigurationCache<NString, NNavigationConfig>("navigation")
            {
            }

            NNavigationConfigCache::~NNavigationConfigCache()
            {
            }

            void NNavigationConfigCache::load()
            {
                INList<NNavigationConfigFile *> * configFileList = NResourcePool::getResources<NNavigationConfigFile>("navigation", XML_SUFFIX);
                if (configFileList != NULL)
                {
                    for (nlong i = 0; i < configFileList->getSize(); i++)
                    {
                        loadFile(configFileList->get(i));
                    }
                    delete configFileList;
                }
            }

            void NNavigationConfigCache::loadFile(NNavigationConfigFile * file)
            {
                INList<NNavigationConfig *> * configList = NULL;
                try
                {
                    if (file != NULL)
                    {
                        configList = file->parse();

                        if (configList != NULL)
                        {
                            for (nlong i = 0; i < configList->getSize(); i++)
                            {
                                NNavigationConfig * config = configList->get(i);
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