//
// Created by strohhalm on 30.06.15.
//

#include <nbase/NBaseType.h>
#include <nbase/collection/NList.h>
#include "NNavigationConfigFile.h"

namespace nox
{
    namespace web
    {
        namespace configuration
        {

            NNavigationConfigFile::NNavigationConfigFile(const NString & fileName) : INXmlInputFile<INList<NNavigationConfig *>>(fileName)
            {
            }

            NNavigationConfigFile::~NNavigationConfigFile()
            {
            }

            INList<NNavigationConfig *> * NNavigationConfigFile::parseXmlDocument(pugi::xml_document * document)
            {
                INList<NNavigationConfig *> * result = new NList<NNavigationConfig *>();

                pugi::xml_node navigation = document->child("navigations");
                if (navigation.type() != pugi::node_null)
                {
                    for (pugi::xml_node view : navigation.children())
                    {
                        if (view.type() == pugi::node_element)
                        {
                            if (NString("navigation").compare(view.name()) == 0)
                            {
                                NNavigationConfig * config = parseConfigEntry(view);
                                if (config != NULL)
                                    result->add(config);
                            }
                        }
                    }
                }

                return result;
            }

            NNavigationConfig * NNavigationConfigFile::parseConfigEntry(pugi::xml_node & node)
            {
                NNavigationConfig * config = NULL;
                try
                {
                    config = new NNavigationConfig();

                    for (pugi::xml_node setting : node.children())
                    {
                        if (setting.type() == pugi::node_element)
                        {
                            if (NString("view").compare(setting.name()) == 0)
                            {
                                config->setView(setting.child_value());
                            }
                            else if (NString("initial").compare(setting.name()) == 0)
                            {
                                config->setInitial(NBool::fromString(setting.child_value()));
                            }
                            else if (NString("rules").compare(setting.name()) == 0)
                            {
                                config->setNavigationRules(new NList<NNavigationRuleConfig *>());

                                for (pugi::xml_node rule : setting.children())
                                {
                                    if (rule.type() == pugi::node_element)
                                    {
                                        if (NString("rule").compare(rule.name()) == 0)
                                        {
                                            NNavigationRuleConfig * subConfig = parseSubConfigEntry(rule);
                                            if (subConfig != NULL)
                                                config->getNavigationRules()->add(subConfig);
                                        }
                                    }
                                }
                            }
                        }
                    }

                    if (config->getView().empty()
                            || config->getNavigationRules() == NULL
                            || config->getNavigationRules()->getSize() == 0)
                    {
                        throw NRuntimeException("Navigation config is incomplete");
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

            NNavigationRuleConfig * NNavigationConfigFile::parseSubConfigEntry(pugi::xml_node & node)
            {
                NNavigationRuleConfig * config = NULL;
                try
                {
                    config = new NNavigationRuleConfig();

                    for (pugi::xml_node ruleSetting : node.children())
                    {
                        if (ruleSetting.type() == pugi::node_element)
                        {
                            if (NString("outcome").compare(ruleSetting.name()) == 0)
                            {
                                config->setOutcome(ruleSetting.child_value());
                            }
                            else if (NString("view").compare(ruleSetting.name()) == 0)
                            {
                                config->setView(ruleSetting.child_value());
                            }
                        }
                    }

                    if (config->getOutcome().empty()
                            || config->getView().empty())
                    {
                        throw NRuntimeException("Navigationrule config is incomplete");
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