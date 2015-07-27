//
// Created by strohhalm on 21.06.15.
//

#include "NServiceConfig.h"

namespace nox
{
    namespace service
    {
        namespace configuration
        {
            NServiceConfig::NServiceConfig() : INObject()
            {
                m_Service = new NString();
                m_Factory = new NString();
                m_Port = new NUnsignedShort();
                m_Component = new NString();
                m_Protocol = NProtocol::UNKNOWN;
                m_Network = NNetwork::IPV4;
            }

            NServiceConfig::NServiceConfig(const NString & service, const NString & factory, const NUnsignedShort & port, const NString & component, const NProtocol * protocol, const NNetwork * network) : INObject()
            {
                m_Service = new NString(service);
                m_Factory = new NString(factory);
                m_Port = new NUnsignedShort(port);
                m_Component = new NString(component);
                m_Protocol = protocol;
                m_Network = network;
            }

            NServiceConfig::NServiceConfig(const NServiceConfig & other) : INObject()
            {
                m_Service = new NString(*other.m_Service);
                m_Factory = new NString(*other.m_Factory);
                m_Port = new NUnsignedShort(*other.m_Port);
                m_Component = new NString(*other.m_Component);
                m_Protocol = other.m_Protocol;
                m_Network = other.m_Network;
            }

            NServiceConfig::~NServiceConfig()
            {
                if (m_Service != NULL)
                    delete m_Service;
                if (m_Factory != NULL)
                    delete m_Factory;
                if (m_Port != NULL)
                    delete m_Port;
                if (m_Component != NULL)
                    delete m_Component;
            }

            void NServiceConfig::setService(const NString & service)
            {
                m_Service->assign(service);
            }

            const NString & NServiceConfig::getService() const
            {
                return *m_Service;
            }

            void NServiceConfig::setFactory(const NString & factory)
            {
                m_Factory->assign(factory);
            }

            const NString& NServiceConfig::getFactory() const
            {
                return *m_Factory;
            }

            void NServiceConfig::setPort(const NUnsignedShort & port)
            {
                m_Port->setValue(port);
            }

            const NUnsignedShort & NServiceConfig::getPort() const
            {
                return *m_Port;
            }

            void NServiceConfig::setComponent(const NString & component)
            {
                m_Component->assign(component);
            }

            const NString & NServiceConfig::getComponent() const
            {
                return *m_Component;
            }

            void NServiceConfig::setProtocol(const NProtocol * protocol)
            {
                m_Protocol = protocol;
            }

            const NProtocol * NServiceConfig::getProtocol() const
            {
                return m_Protocol;
            }

            void NServiceConfig::setNetwork(const NNetwork * network)
            {
                m_Network = network;
            }

            const NNetwork* NServiceConfig::getNetwork() const
            {
                return m_Network;
            }

            nint NServiceConfig::compareTo(const INObject * other) const
            {
                if (this == other)
                    return 0;
                try
                {
                    const NServiceConfig * obj = dynamic_cast<const NServiceConfig *>(other);

                    if (obj != NULL)
                    {
                        int result = 0;
                        if ((result = getService().compare(obj->getService())) == 0)
                        {
                            if ((result = getFactory().compare(obj->getFactory())) == 0)
                            {
                                if ((result = getComponent().compare(obj->getComponent())) == 0)
                                {
                                    if ((result = getPort().getValue() - obj->getPort().getValue()) == 0)
                                    {
                                        if ((result = getNetwork()->getValue() - obj->getNetwork()->getValue()) == 0)
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