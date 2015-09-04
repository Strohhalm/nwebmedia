//
// Created by strohhalm on 04.09.15.
//

#include <nweb/config/NWidgetFactoryConfigFile.h>

namespace nox
{
    namespace web
    {
        namespace configuration
        {
            NWidgetFactoryConfigFile::NWidgetFactoryConfigFile(const NString & fileName) : INXmlInputFile<INList<NWidgetFactoryConfig *>>(fileName)
            {
            }

            NWidgetFactoryConfigFile::~NWidgetFactoryConfigFile()
            {
            }

            INList<NWidgetFactoryConfig *> * NWidgetFactoryConfigFile::parseXmlDocument(pugi::xml_document * document)
            {
                INList<NWidgetFactoryConfig *> * result = new NList<NWidgetFactoryConfig *>();

                pugi::xml_node factories = document->child("factories");
                if (factories.type() != pugi::node_null)
                {
                    for (pugi::xml_node factory : factories.children())
                    {
                        if (factory.type() == pugi::node_element)
                        {
                            if (NString("factory").compare(factory.name()) == 0)
                            {
                                NWidgetFactoryConfig * config = parseConfigEntry(factory);
                                if (config != NULL)
                                    result->add(config);
                            }
                        }
                    }
                }

                return result;
            }

            NWidgetFactoryConfig * NWidgetFactoryConfigFile::parseConfigEntry(pugi::xml_node & node)
            {
                NWidgetFactoryConfig * config = NULL;
                try
                {
                    config = new NWidgetFactoryConfig();

                    for (pugi::xml_node setting : node.children())
                    {
                        if (setting.type() == pugi::node_element)
                        {
                            if (NString("name").compare(setting.name()) == 0)
                            {
                                config->setName(setting.child_value());
                            }
                            else if (NString("factory").compare(setting.name()) == 0)
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

                    if (config->getName().empty()
                        || config->getFactory().empty()
                        || config->getComponent().empty()
                        || config->getLibrary().empty())
                    {
                        throw NRuntimeException("View factory configuration is incomplete");
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