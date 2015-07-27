//
// Created by strohhalm on 28.06.15.
//

#include "NServiceClientConfigCache.h"
#include "NServiceClientConfigFile.h"

namespace nox
{
    namespace service
    {
        namespace client
        {
            namespace configuration
            {
                NServiceClientConfigCache::NServiceClientConfigCache() : INConfigurationCache<NString, NServiceClientConfig>(NXS(serviceClient))
                {
                }

                NServiceClientConfigCache::~NServiceClientConfigCache()
                {
                }

                void NServiceClientConfigCache::load()
                {
                    INList<NServiceClientConfigFile *> * configFileList = NResourcePool::getResources<NServiceClientConfigFile>("serviceClient", XML_SUFFIX);
                    if (configFileList != NULL)
                    {
                        for (nlong i = 0; i < configFileList->getSize(); i++)
                        {
                            loadFile(configFileList->get(i));
                        }
                        delete configFileList;
                    }
                }

                void NServiceClientConfigCache::loadFile(NServiceClientConfigFile * file)
                {
                    INList<NServiceClientConfig *> * configList = NULL;
                    try
                    {
                        if (file != NULL)
                        {
                            configList = file->parse();

                            if (configList != NULL)
                            {
                                for (nlong i = 0; i < configList->getSize(); i++)
                                {
                                    NServiceClientConfig * config = configList->get(i);
                                    if (!m_ConfigurationCache->contains(config->getServiceClient()))
                                    {
                                        m_ConfigurationCache->add(config->getServiceClient(), config);
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
}