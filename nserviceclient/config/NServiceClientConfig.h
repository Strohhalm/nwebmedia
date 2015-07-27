//
// Created by strohhalm on 28.06.15.
//

#ifndef NWEBMEDIA_NSERVICECLIENTCONFIG_H
#define NWEBMEDIA_NSERVICECLIENTCONFIG_H

#include <nbase/INObject.h>
#include <nbase/enumeration/NProtocol.h>

using namespace nox::enumeration;

namespace nox
{
    namespace service
    {
        namespace client
        {
            namespace configuration
            {
                class NServiceClientConfig : public INObject
                {
                protected:
                    NString * m_ServiceClient;
                    NString * m_Host;
                    NUnsignedShort * m_Port;
                    NString * m_Factory;
                    NString * m_Component;
                    const NProtocol * m_Protocol;
                public:
                    NServiceClientConfig();
                    NServiceClientConfig(const NString & serviceClient, const NString & host, const NUnsignedShort & port, const NString & factory, const NString & component, const NProtocol * protocol);
                    NServiceClientConfig(const NServiceClientConfig & other);
                    virtual ~NServiceClientConfig();
                    virtual void setServiceClient(const NString & serviceClient);
                    virtual const NString & getServiceClient() const;
                    virtual void setHost(const NString & host);
                    virtual const NString & getHost() const;
                    virtual void setPort(const NUnsignedShort & port);
                    virtual const NUnsignedShort & getPort() const;
                    virtual void setFactory(const NString & factory);
                    virtual const NString & getFactory() const;
                    virtual void setComponent(const NString & component);
                    virtual const NString & getComponent() const;
                    virtual void setProtocol(const NProtocol * protocol);
                    virtual const NProtocol * getProtocol() const;
                    virtual int compareTo(const INObject * other) const;
                };
            }
        }
    }
}

#endif //NWEBMEDIA_NSERVICECLIENTCONFIG_H
