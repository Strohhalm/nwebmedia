//
// Created by strohhalm on 29.06.15.
//

#include "NViewFactoryConfigCache.h"
#include "NViewFactoryConfigFile.h"

namespace nox
{
    namespace web
    {
        namespace configuration
        {

            NViewFactoryConfigCache::NViewFactoryConfigCache() : INConfigurationCache<NString, NViewFactoryConfig>(NXS(viewfactory))
            {
            }

            NViewFactoryConfigCache::~NViewFactoryConfigCache()
            {
            }

            void NViewFactoryConfigCache::load()
            {
                INList<NViewFactoryConfigFile *> * configFileList = NResourcePool::getResources<NViewFactoryConfigFile>("viewFactory", XML_SUFFIX);
                if (configFileList != NULL)
                {
                    for (nlong i = 0; i < configFileList->getSize(); i++)
                    {
                        loadFile(configFileList->get(i));
                    }
                    delete configFileList;
                }
            }

            void NViewFactoryConfigCache::loadFile(NViewFactoryConfigFile * file)
            {
                INList<NViewFactoryConfig *> * configList = NULL;
                try
                {
                    if (file != NULL)
                    {
                        configList = file->parse();
                        if (configList != NULL)
                        {
                            for (nlong i = 0; i < configList->getSize(); i++)
                            {
                                NViewFactoryConfig * config = configList->get(i);

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