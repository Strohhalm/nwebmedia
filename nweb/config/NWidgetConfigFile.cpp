//
// Created by strohhalm on 04.09.15.
//

#include <nweb/config/NWidgetConfigFile.h>

namespace nox
{
    namespace web
    {
        namespace configuration
        {
            NWidgetConfigFile::NWidgetConfigFile(const NString & fileName) : INXmlInputFile<INList<NWidgetConfig *>>(fileName)
            {
            }

            NWidgetConfigFile::~NWidgetConfigFile()
            {
            }

            INList<NWidgetConfig *> * NWidgetConfigFile::parseXmlDocument(pugi::xml_document * document)
            {
                INList<NWidgetConfig *> * result = new NList<NWidgetConfig *>();

                pugi::xml_node views = document->child("widgets");
                if (views.type() != pugi::node_null)
                {
                    for (pugi::xml_node view : views.children())
                    {
                        if (view.type() == pugi::node_element)
                        {
                            if (NString("widget").compare(view.name()) == 0)
                            {
                                NWidgetConfig * config = parseConfigEntry(view);
                                if (config != NULL)
                                    result->add(config);
                            }
                        }
                    }
                }

                return result;
            }

            NWidgetConfig * NWidgetConfigFile::parseConfigEntry(pugi::xml_node & node)
            {
                NWidgetConfig * config = NULL;
                try
                {
                    config = new NWidgetConfig();

                    for (pugi::xml_node setting : node.children())
                    {
                        if (setting.type() == pugi::node_element)
                        {
                            if (NString("name").compare(setting.name()) == 0)
                            {
                                config->setName(setting.child_value());
                            }
                            else if (NString("widget").compare(setting.name()) == 0)
                            {
                                config->setWidget(setting.child_value());
                            }
                            else if (NString("component").compare(setting.name()) == 0)
                            {
                                config->setComponent(setting.child_value());
                            }
                            else if (NString("factory").compare(setting.name()) == 0)
                            {
                                config->setFactory(setting.child_value());
                            }
                        }
                    }

                    if (config->getName().empty()
                        || config->getWidget().empty()
                        || config->getComponent().empty()
                        || config->getFactory().empty())
                    {
                        throw NRuntimeException("View configuration is incomplete");
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