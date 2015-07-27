//
// Created by strohhalm on 28.06.15.
//

#include "NServiceClientConfig.h"

namespace nox
{
    namespace service
    {
        namespace client
        {
            namespace configuration
            {
                NServiceClientConfig::NServiceClientConfig() : INObject()
                {
                    m_ServiceClient = new NString();
                    m_Host = new NString();
                    m_Port = new NUnsignedShort();
                    m_Component = new NString();
                    m_Factory = new NString();
                    m_Protocol = NProtocol::UNKNOWN;
                }

                NServiceClientConfig::NServiceClientConfig(const NString & serviceClient, const NString & host, const NUnsignedShort & port,
                                                                         const NString & factory,
                                                                         const NString & component,
                                                                         const NProtocol * protocol) : INObject()
                {
                    m_ServiceClient = new NString(serviceClient);
                    m_Host = new NString(host);
                    m_Port = new NUnsignedShort(port);
                    m_Component = new NString(component);
                    m_Factory = new NString(factory);
                    m_Protocol = protocol;
                }

                NServiceClientConfig::NServiceClientConfig(const NServiceClientConfig & other) : INObject()
                {
                    m_ServiceClient = new NString(*other.m_ServiceClient);
                    m_Host = new NString(*other.m_Host);
                    m_Port = new NUnsignedShort(*other.m_Port);
                    m_Component = new NString(*other.m_Component);
                    m_Factory = new NString(*other.m_Factory);
                    m_Protocol = other.m_Protocol;
                }

                NServiceClientConfig::~NServiceClientConfig()
                {
                    if (m_ServiceClient != NULL)
                        delete m_ServiceClient;
                    if (m_Host != NULL)
                        delete m_Host;
                    if (m_Port != NULL)
                        delete m_Port;
                    if (m_Component != NULL)
                        delete m_Component;
                    if (m_Factory != NULL)
                        delete m_Factory;
                }

                void NServiceClientConfig::setServiceClient(const NString & serviceClient)
                {
                    m_ServiceClient->assign(serviceClient);
                }

                const NString& NServiceClientConfig::getServiceClient() const
                {
                    return *m_ServiceClient;
                }

                void NServiceClientConfig::setHost(const NString & host)
                {
                    m_Host->assign(host);
                }

                const NString & NServiceClientConfig::getHost() const
                {
                    return *m_Host;
                }

                void NServiceClientConfig::setPort(const NUnsignedShort & port)
                {
                    m_Port->setValue(port);
                }

                const NUnsignedShort & NServiceClientConfig::getPort() const
                {
                    return *m_Port;
                }

                void NServiceClientConfig::setFactory(const NString & factory)
                {
                    m_Factory->assign(factory);
                }

                const NString & NServiceClientConfig::getFactory() const
                {
                    return *m_Factory;
                }

                void NServiceClientConfig::setComponent(const NString & component)
                {
                    m_Component->assign(component);
                }

                const NString & NServiceClientConfig::getComponent() const
                {
                    return *m_Component;
                }

                void NServiceClientConfig::setProtocol(const NProtocol * protocol)
                {
                    m_Protocol = protocol;
                }

                const NProtocol * NServiceClientConfig::getProtocol() const
                {
                    return m_Protocol;
                }

                int NServiceClientConfig::compareTo(const INObject * other) const
                {
                    if (this == other)
                        return 0;
                    try
                    {
                        const NServiceClientConfig * obj = dynamic_cast<const NServiceClientConfig *>(other);

                        if (obj != NULL)
                        {
                            int result = 0;
                            if ((result = getServiceClient().compare(obj->getServiceClient())) == 0)
                            {
                                if ((result = getHost().compare(obj->getHost())) == 0)
                                {
                                    if ((result = getPort().getValue() - obj->getPort().getValue()) == 0)
                                    {
                                        if ((result = getComponent().compare(obj->getComponent())) == 0)
                                        {
                                            if ((result = getFactory().compare(obj->getFactory())) == 0)
                                            {
                                                result = getProtocol()->getValue() - obj->getProtocol()->getValue();
                                            }
                                        }
                                    }
                                }
                            }
                            return result;
                        }
                        else
                        {
                            return 1;
                        }
                    }
                    catch (bad_cast &)
                    {
                        return 1;
                    }
                }
            }
        }
    }
}