//
// Created by strohhalm on 21.06.15.
//

#ifndef NSERVICECONFIG_H
#define NSERVICECONFIG_H

#include <nbase/INObject.h>
#include <nbase/NBaseType.h>
#include <nbase/enumeration/NNetwork.h>
#include <nbase/enumeration/NProtocol.h>

using namespace nox::enumeration;

namespace nox
{
    namespace service
    {
        namespace configuration
        {
            class NServiceConfig : public INObject
            {
            protected:
                NString * m_Service;
                NString * m_Factory;
                NUnsignedShort * m_Port;
                NString * m_Component;
                const NProtocol * m_Protocol;
                const NNetwork * m_Network;
            public:
                NServiceConfig();
                NServiceConfig(const NString & service, const NString & factory, const NUnsignedShort & port, const NString & component, const NProtocol * protocol, const NNetwork * network);
                NServiceConfig(const NServiceConfig & other);
                virtual ~NServiceConfig();
                virtual void setService(const NString & service);
                virtual const NString & getService() const;
                virtual void setFactory(const NString & factory);
                virtual const NString & getFactory() const;
                virtual void setPort(const NUnsignedShort & port);
                virtual const NUnsignedShort & getPort() const;
                virtual void setComponent(const NString & component);
                virtual const NString & getComponent() const;
                virtual void setProtocol(const NProtocol * protocol);
                virtual const NProtocol * getProtocol() const;
                virtual void setNetwork(const NNetwork * network);
                virtual const NNetwork * getNetwork() const;
                virtual nint compareTo(const INObject * other) const;
            };
        }
    }
}

#endif //NSERVICECONFIG_H
