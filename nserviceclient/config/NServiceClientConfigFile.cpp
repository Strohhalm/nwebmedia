//
// Created by strohhalm on 28.06.15.
//

#include "NServiceClientConfigFile.h"

namespace nox
{
    namespace service
    {
        namespace client
        {
            namespace configuration
            {
                NServiceClientConfigFile::NServiceClientConfigFile(const NString & fileName) : INXmlInputFile<INList<NServiceClientConfig *>>(fileName)
                {
                }

                NServiceClientConfigFile::~NServiceClientConfigFile()
                {
                }

                INList<NServiceClientConfig *> * NServiceClientConfigFile::parseXmlDocument(pugi::xml_document * document)
                {
                    INList<NServiceClientConfig *> * result = new NList<NServiceClientConfig *>();

                    pugi::xml_node serviceClients = document->child("serviceClients");
                    if (serviceClients.type() != pugi::node_null)
                    {
                        for (pugi::xml_node serviceClient : serviceClients.children())
                        {
                            if (serviceClient.type() == pugi::node_element)
                            {
                                if (NString("serviceClient").compare(serviceClient.name()) == 0)
                                {
                                    NServiceClientConfig * config = parseConfigEntry(serviceClient);
                                    if (config != NULL)
                                        result->add(config);
                                }
                            }
                        }
                    }

                    return result;
                }

                NServiceClientConfig * NServiceClientConfigFile::parseConfigEntry(pugi::xml_node & node)
                {
                    NServiceClientConfig * config = NULL;
                    try
                    {
                        config = new NServiceClientConfig();

                        for (pugi::xml_node setting : node.children())
                        {
                            if (setting.type() == pugi::node_element)
                            {
                                if (NString("name").compare(setting.name()) == 0)
                                {
                                    config->setServiceClient(setting.child_value());
                                }
                                else if (NString("host").compare(setting.name()) == 0)
                                {
                                    config->setHost(setting.child_value());
                                }
                                else if (NString("port").compare(setting.name()) == 0)
                                {
                                    config->setPort(NUnsignedShort::fromString(setting.child_value()));
                                }
                                else if (NString("component").compare(setting.name()) == 0)
                                {
                                    config->setComponent(setting.child_value());
                                }
                                else if (NString("factory").compare(setting.name()) == 0)
                                {
                                    config->setFactory(setting.child_value());
                                }
                                else if (NString("protocol").compare(setting.name()) == 0)
                                {
                                    config->setProtocol(NProtocol::getByName(setting.child_value()));
                                }
                            }
                        }

                        if (config->getServiceClient().empty()
                                || config->getComponent().empty()
                                || config->getFactory().empty()
                                || config->getHost().empty()
                                || config->getPort() == NUnsignedShort(0)
                                || config->getProtocol() == NProtocol::UNKNOWN)
                        {
                            throw NRuntimeException("Serviceclient configuration is incomplete");
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