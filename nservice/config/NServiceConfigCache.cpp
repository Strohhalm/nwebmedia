//
// Created by strohhalm on 22.06.15.
//

#include "NServiceConfigCache.h"
#include "NServiceConfigFile.h"

using namespace nox::resource;

namespace nox
{
    namespace service
    {
        namespace configuration
        {
            NServiceConfigCache::NServiceConfigCache() : INConfigurationCache<NString, NServiceConfig>(NXS(service))
            {
            }

            NServiceConfigCache::~NServiceConfigCache()
            {
            }

            void NServiceConfigCache::load()
            {
                INList<NServiceConfigFile *> * configFileList = NResourcePool::getResources<NServiceConfigFile>("service", XML_SUFFIX);
                if (configFileList != NULL)
                {
                    for (nlong i = 0; i < configFileList->getSize(); i++)
                    {
                        loadFile(configFileList->get(i));
                    }
                    delete configFileList;
                }
            }

            void NServiceConfigCache::loadFile(NServiceConfigFile * file)
            {
                INList<NServiceConfig *> * configList = NULL;
                try
                {
                    configList = file->parse();

                    if (configList != NULL)
                    {
                        NServiceConfig * config = NULL;
                        for (nlong i = 0; i < configList->getSize(); i++)
                        {
                            config = configList->get(i);
                            if (config != NULL)
                            {
                                if (!m_ConfigurationCache->contains(config->getService()))
                                {
                                    m_ConfigurationCache->add(config->getService(), config);
                                }
                                else
                                {
                                    delete config;
                                    //TODO: Log warning
                                }
                            }
                        }
                        delete configList;
                    }
                    delete file;
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