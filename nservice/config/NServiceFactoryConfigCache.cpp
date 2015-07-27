//
// Created by strohhalm on 22.06.15.
//

#include "NServiceFactoryConfigCache.h"
#include "NServiceFactoryConfigFile.h"

namespace nox
{
    namespace service
    {
        namespace configuration
        {
            NServiceFactoryConfigCache::NServiceFactoryConfigCache() : INConfigurationCache<NString, NServiceFactoryConfig>(NXS(serviceFactory))
            {
            }

            NServiceFactoryConfigCache::~NServiceFactoryConfigCache()
            {
            }

            void NServiceFactoryConfigCache::load()
            {
                INList<NServiceFactoryConfigFile *> * configFileList  = NResourcePool::getResources<NServiceFactoryConfigFile>("serviceFactory", XML_SUFFIX);
                if (configFileList != NULL)
                {
                    for (nlong i = 0; i < configFileList->getSize(); i++)
                    {
                        loadFile(configFileList->get(i));
                    }
                    delete configFileList;
                }
            }

            void NServiceFactoryConfigCache::loadFile(NServiceFactoryConfigFile * file)
            {
                INList<NServiceFactoryConfig *> * configList = NULL;
                try
                {
                    if (file != NULL)
                    {
                        configList = file->parse();

                        if (configList != NULL)
                        {
                            for (nlong i = 0; i < configList->getSize(); i++)
                            {
                                NServiceFactoryConfig * config = configList->get(i);
                                if (!m_ConfigurationCache->contains(config->getFactory()))
                                {
                                    m_ConfigurationCache->add(config->getFactory(), config);
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