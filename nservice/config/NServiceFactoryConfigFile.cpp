//
// Created by strohhalm on 21.06.15.
//

#include <nbase/collection/NList.h>
#include "NServiceFactoryConfigFile.h"


namespace nox
{
    namespace service
    {
        namespace configuration
        {
            NServiceFactoryConfigFile::NServiceFactoryConfigFile(const NString & fileName) : INXmlInputFile<INList<NServiceFactoryConfig *>>(fileName)
            {
            }

            NServiceFactoryConfigFile::~NServiceFactoryConfigFile()
            {
            }

            INList<NServiceFactoryConfig *> * NServiceFactoryConfigFile::parseXmlDocument(pugi::xml_document * document)
            {
                INList<NServiceFactoryConfig *> * result = new NList<NServiceFactoryConfig *>();

                pugi::xml_node factories = document->child("factories");
                if (factories.type() != pugi::node_null)
                {
                    for (pugi::xml_node factory : factories.children())
                    {
                        if (factory.type() == pugi::node_element)
                        {
                            if (NString("factory").compare(factory.name()) == 0)
                            {
                                NServiceFactoryConfig * config = parseConfigEntry(factory);
                                if (config != NULL)
                                    result->add(config);
                            }
                        }
                    }
                }
                return result;
            }

            NServiceFactoryConfig * NServiceFactoryConfigFile::parseConfigEntry(pugi::xml_node & node)
            {
                NServiceFactoryConfig * config = NULL;

                try
                {
                    config = new NServiceFactoryConfig();

                    for (pugi::xml_node setting : node.children())
                    {
                        if (setting.type() == pugi::node_element)
                        {
                            if (NString("name").compare(setting.name()) == 0)
                            {
                                config->setFactory(setting.child_value());
                            }
                            else if (NString("component").compare(setting.name()) == 0)
                            {
                                config->setComponent(setting.child_value());
                            }
                            else if (NString("library").compare(setting.name()) == 0)
                            {
                                config->setLibrary(setting.child_value());
                            }
                        }
                    }
                    if (config->getFactory().empty()
                            || config->getComponent().empty()
                            || config->getLibrary().empty())
                    {
                        throw NRuntimeException("Service factory configuration is incomplete");
                    }
                }
                catch (...)
                {
                    if (config != NULL)
                        delete config;
                    return NULL;
                }
                return config;
            }
        }
    }
}