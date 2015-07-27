//
// Created by strohhalm on 05.06.15.
//

#ifndef NCONNECTIONCONFIG_H
#define NCONNECTIONCONFIG_H

#include <nbase/INObject.h>
#include <nmodel/enumeration/NConnectionType.h>

using namespace nox::model::enumeration;

namespace nox
{
    namespace model
    {
        namespace configuration
        {
            class NConnectionConfig : public INObject
            {
            protected:
                NString * m_Name;
                NString * m_Host;
                NUnsignedShort * m_Port;
                NString * m_User;
                NString * m_Password;
                NString * m_Schema;
                const NConnectionType * m_ConnectionType;
            public:
                NConnectionConfig();
                NConnectionConfig(const NConnectionConfig & other);
                NConnectionConfig(const NString & name, const NString & host, const NUnsignedShort & port, const NString & user, const NString & password,
                                  const NString & schema, const NConnectionType * connectionType);
                virtual ~NConnectionConfig();
                virtual void setName(const NString & name);
                virtual const NString & getName() const;
                virtual void setHost(const NString & host);
                virtual const NString & getHost() const;
                virtual void setPort(const NUnsignedShort & port);
                virtual const NUnsignedShort & getPort() const;
                virtual void setUser(const NString & user);
                virtual const NString & getUser() const;
                virtual void setPassword(const NString & password);
                virtual const NString & getPassword() const;
                virtual void setSchema(const NString & schema);
                virtual const NString & getSchema() const;
                virtual void setConnectionType(const NConnectionType * connectionType);
                virtual const NConnectionType * getConnectionType() const;
                virtual nint compareTo(const INObject * other) const;
            };
        }
    }
}

#endif //NCONNECTIONCONFIG_H
