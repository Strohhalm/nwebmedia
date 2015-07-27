//
// Created by strohhalm on 28.06.15.
//

#include "NServiceClientFactoryConfigCache.h"
#include "NServiceClientFactoryConfigFile.h"

namespace nox
{
    namespace service
    {
        namespace client
        {
            namespace configuration
            {
                NServiceClientFactoryConfigCache::NServiceClientFactoryConfigCache() : INConfigurationCache<NString, NServiceClientFactoryConfig>(NXS(serviceClientFactory))
                {
                }

                NServiceClientFactoryConfigCache::~NServiceClientFactoryConfigCache()
                {
                }

                void NServiceClientFactoryConfigCache::load()
                {
                    INList<NServiceClientFactoryConfigFile *> * configFileList = NResourcePool::getResources<NServiceClientFactoryConfigFile>("serviceClientFactory", XML_SUFFIX);
                    if (configFileList != NULL)
                    {
                        for (nlong i = 0; i < configFileList->getSize(); i++)
                        {
                            loadFile(configFileList->get(i));
                        }
                        delete configFileList;
                    }
                }

                void NServiceClientFactoryConfigCache::loadFile(NServiceClientFactoryConfigFile * file)
                {
                    INList<NServiceClientFactoryConfig *> * configList = NULL;
                    try
                    {
                        if (file != NULL)
                        {
                            configList = file->parse();

                            if (configList != NULL)
                            {
                                for (nlong i = 0; i < configList->getSize(); i++)
                                {
                                    NServiceClientFactoryConfig * config = configList->get(i);

                                    if (!m_ConfigurationCache->contains(config->getFactory()))
                                    {
                                        m_ConfigurationCache->add(config->getFactory(), config);
                                    }
                                    else
                                    {
                                        delete config;
                                        //TODO:: log Warning
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
}