//
// Created by strohhalm on 29.06.15.
//

#include "NViewConfigFile.h"

namespace nox
{
    namespace web
    {
        namespace configuration
        {
            NViewConfigFile::NViewConfigFile(const NString & fileName) : INXmlInputFile<INList<NViewConfig *>>(fileName)
            {
            }

            NViewConfigFile::~NViewConfigFile()
            {
            }

            INList<NViewConfig *> * NViewConfigFile::parseXmlDocument(pugi::xml_document * document)
            {
                INList<NViewConfig *> * result = new NList<NViewConfig *>();

                pugi::xml_node views = document->child("views");
                if (views.type() != pugi::node_null)
                {
                    for (pugi::xml_node view : views.children())
                    {
                        if (view.type() == pugi::node_element)
                        {
                            if (NString("view").compare(view.name()) == 0)
                            {
                                NViewConfig * config = parseConfigEntry(view);
                                if (config != NULL)
                                    result->add(config);
                            }
                        }
                    }
                }

                return result;
            }

            NViewConfig * NViewConfigFile::parseConfigEntry(pugi::xml_node & node)
            {
                NViewConfig * config = NULL;
                try
                {
                    config = new NViewConfig();

                    for (pugi::xml_node setting : node.children())
                    {
                        if (setting.type() == pugi::node_element)
                        {
                            if (NString("name").compare(setting.name()) == 0)
                            {
                                config->setName(setting.child_value());
                            }
                            else if (NString("view").compare(setting.name()) == 0)
                            {
                                config->setView(setting.child_value());
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
                        || config->getView().empty()
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