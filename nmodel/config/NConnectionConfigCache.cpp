//
// Created by strohhalm on 22.06.15.
//

#include <nbase/resource/NResourcePool.h>
#include "NConnectionConfigCache.h"
#include "NConnectionConfigFile.h"

namespace nox
{
    namespace model
    {
        namespace configuration
        {
            NConnectionConfigCache::NConnectionConfigCache() : INConfigurationCache<NString, NConnectionConfig>("database")
            {
            }

            NConnectionConfigCache::~NConnectionConfigCache()
            {
            }

            void NConnectionConfigCache::load()
            {
                INList<NConnectionConfigFile *> * configFileList = NResourcePool::getInstance()->loadResources<NConnectionConfigFile>("database", XML_SUFFIX);
                if (configFileList != NULL)
                {
                    for (nlong i = 0; i < configFileList->getSize(); i++)
                        loadFile(configFileList->get(i));
                    delete configFileList;
                }
                else
                {
                    throw NRuntimeException("No database configuration file found");
                }
            }

            void NConnectionConfigCache::loadFile(NConnectionConfigFile * file)
            {
                INList<NConnectionConfig *> * configurationList = NULL;
                try
                {
                    if (file != NULL)
                    {
                        configurationList = file->parse();

                        if (configurationList != NULL)
                        {
                            for (nlong i = 0; i < configurationList->getSize(); i++)
                            {
                                if (m_ConfigurationCache->contains(configurationList->get(i)->getName()))
                                {
                                    NConnectionConfig * config = m_ConfigurationCache->get(configurationList->get(i)->getName());
                                    if (config != NULL)
                                        delete config;
                                    m_ConfigurationCache->remove(configurationList->get(i)->getName());
                                }
                                m_ConfigurationCache->add(configurationList->get(i)->getName(),
                                                          configurationList->get(i));
                            }
                            delete configurationList;
                        }
                        delete file;
                    }
                }
                catch (exception & exp)
                {
                    if (configurationList != NULL)
                    {
                        for (nlong i = 0; i < configurationList->getSize(); i++)
                        {
                            if (configurationList->get(i) != NULL)
                                delete configurationList->get(i);
                        }
                        delete configurationList;
                    }
                    if (file != NULL)
                        delete file;
                }
            }
        }
    }
}