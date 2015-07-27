//
// Created by strohhalm on 28.06.15.
//

#include "NServiceClientFactoryConfigFile.h"

namespace nox
{
    namespace service
    {
        namespace client
        {
            namespace configuration
            {

                NServiceClientFactoryConfigFile::NServiceClientFactoryConfigFile(const NString & fileName) : INXmlInputFile<INList<NServiceClientFactoryConfig *>>(fileName)
                {
                }

                NServiceClientFactoryConfigFile::~NServiceClientFactoryConfigFile()
                {
                }

                INList<NServiceClientFactoryConfig *> * NServiceClientFactoryConfigFile::parseXmlDocument(pugi::xml_document * document)
                {
                    INList<NServiceClientFactoryConfig *> * result = new NList<NServiceClientFactoryConfig *>();

                    pugi::xml_node factories = document->child("factories");
                    if (factories.type() != pugi::node_null)
                    {
                        for (pugi::xml_node factory : factories.children())
                        {
                            if (factory.type() == pugi::node_element)
                            {
                                if (NString("factory").compare(factory.name()) == 0)
                                {
                                    NServiceClientFactoryConfig * config = parseConfigEntry(factory);
                                    if (config != NULL)
                                        result->add(config);
                                }
                            }
                        }
                    }

                    return result;
                }

                NServiceClientFactoryConfig * NServiceClientFactoryConfigFile::parseConfigEntry(pugi::xml_node & node)
                {
                    NServiceClientFactoryConfig * config = NULL;
                    try
                    {
                        config = new NServiceClientFactoryConfig();

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
                            throw NRuntimeException("Service client factory configuratin is incomplete");
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
}