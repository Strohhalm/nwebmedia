//
// Created by strohhalm on 21.06.15.
//

#include <nbase/collection/NList.h>
#include "NServiceConfigFile.h"

namespace nox
{
    namespace service
    {
        namespace configuration
        {
            NServiceConfigFile::NServiceConfigFile(const NString & fileName) : INXmlInputFile<INList<NServiceConfig*>>(fileName)
            {
            }

            NServiceConfigFile::~NServiceConfigFile()
            {
            }

            INList<NServiceConfig *>* NServiceConfigFile::parseXmlDocument(pugi::xml_document * document)
            {
                INList<NServiceConfig *> * result = new NList<NServiceConfig *>();

                pugi::xml_node services = document->child("services");
                if (services.type() != pugi::node_null)
                {
                    for (pugi::xml_node service : services.children())
                    {
                        if (service.type() == pugi::node_element)
                        {
                            if (NString("service").compare(service.name()) == 0)
                            {
                                NServiceConfig * config = parseConfigEntry(service);
                                if (config != NULL)
                                    result->add(config);
                            }
                        }
                    }
                }
                return result;
            }

            NServiceConfig * NServiceConfigFile::parseConfigEntry(pugi::xml_node & node)
            {
                NServiceConfig * config = NULL;
                try
                {
                    config = new NServiceConfig();

                    for (pugi::xml_node setting : node.children())
                    {
                        if (setting.type() == pugi::node_element)
                        {
                            if (NString("name").compare(setting.name()) == 0)
                            {
                                config->setName(setting.child_value());
                            }
                            else if (NString("service").compare(setting.name()) == 0)
                            {
                                config->setService(setting.child_value());
                            }
                            else if (NString("facotry").compare(setting.name()) == 0)
                            {
                                config->setFactory(setting.child_value());
                            }
                            else if (NString("component").compare(setting.name()) == 0)
                            {
                                config->setComponent(setting.child_value());
                            }
                            else if (NString("port").compare(setting.name()) == 0)
                            {
                                config->setPort(
                                        NUnsignedShort::fromString(setting.child_value()));
                            }
                            else if (NString("protocol").compare(setting.name()) == 0)
                            {
                                config->setProtocol(NProtocol::getByName(setting.child_value()));
                            }
                            else if (NString("network").compare(setting.child_value()) == 0)
                            {
                                config->setNetwork(NNetwork::getByName(setting.value()));
                            }
                        }
                    }

                    if (config->getService().empty()
                            || config->getFactory().empty()
                            || config->getComponent().empty()
                            || config->getPort() == NUnsignedShort(0)
                            || config->getProtocol() == NProtocol::UNKNOWN)
                    {
                        throw NRuntimeException("Incomplete service configuration");
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