//
// Created by strohhalm on 06.06.15.
//

#include <nbase/collection/NList.h>
#include <nmodel/config/NConnectionConfigFile.h>

namespace nox
{
    namespace model
    {
        namespace configuration
        {
            NConnectionConfigFile::NConnectionConfigFile(const NString & fileName) : INXmlInputFile(fileName)
            {
            }

            NConnectionConfigFile::~NConnectionConfigFile()
            {
            }

            INList<NConnectionConfig *> * NConnectionConfigFile::parseXmlDocument(pugi::xml_document * document)
            {
                INList<NConnectionConfig *> * result = new NList<NConnectionConfig *>();

                pugi::xml_node connections = document->child("databases");
                if (connections.type() != pugi::node_null)
                {
                    for (pugi::xml_node connection : connections.children())
                    {
                        if (connection.type() == pugi::node_element)
                        {
                            if (NString("database").compare(connection.name()) == 0)
                            {
                                NConnectionConfig * config = parseConfigEntry(connection);
                                if (config != NULL)
                                    result->add(config);
                            }
                        }
                    }
                }

                return result;
            }

            NConnectionConfig * NConnectionConfigFile::parseConfigEntry(pugi::xml_node & node)
            {
                NConnectionConfig * config = NULL;
                try
                {
                    config = new NConnectionConfig();

                    for (pugi::xml_node setting : node.children())
                    {
                        if (setting.type() == pugi::node_element)
                        {
                            if (NString("name").compare(setting.name()) == 0)
                            {
                                config->setName(setting.child_value());
                            }
                            else if (NString("host").compare(setting.name()) == 0)
                            {
                                config->setHost(setting.child_value());
                            }
                            else if (NString("port").compare(setting.name()) == 0)
                            {
                                config->setPort(NUnsignedShort::fromString(setting.child_value()));
                            }
                            else if (NString("user").compare(setting.name()) == 0)
                            {
                                config->setUser(setting.child_value());
                            }
                            else if (NString("password").compare(setting.name()) == 0)
                            {
                                config->setPassword(setting.child_value());
                            }
                            else if (NString("schema").compare(setting.name()) == 0)
                            {
                                config->setSchema(setting.child_value());
                            }
                            else if (NString("type").compare(setting.name()) == 0)
                            {
                                config->setConnectionType(NConnectionType::getByValue(setting.child_value()));
                            }
                        }
                    }
                    if (config->getName().empty()
                            || config->getHost().empty()
                            || config->getUser().empty()
                            || config->getPassword().empty()
                            || config->getSchema().empty()
                            || config->getPort() == NUnsignedShort(0)
                            || config->getConnectionType() == NConnectionType::UNKNOWN)
                    {
                        throw NRuntimeException("Connection configuration is incomplete");
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