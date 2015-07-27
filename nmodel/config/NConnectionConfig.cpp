//
// Created by strohhalm on 05.06.15.
//

#include "NConnectionConfig.h"

namespace nox
{
    namespace model
    {
        namespace configuration
        {
            NConnectionConfig::NConnectionConfig() : INObject()
            {
                m_Name = new NString();
                m_Host = new NString();
                m_Port = new NUnsignedShort();
                m_User = new NString();
                m_Password = new NString();
                m_Schema = new NString();
                m_ConnectionType = NConnectionType::UNKNOWN;
            }

            NConnectionConfig::NConnectionConfig(const NConnectionConfig & other) : INObject()
            {
                m_Name = new NString(*other.m_Name);
                m_Host = new NString(*other.m_Host);
                m_Port = new NUnsignedShort(*other.m_Port);
                m_User = new NString(*other.m_User);
                m_Password = new NString(*other.m_Password);
                m_Schema = new NString(*other.m_Schema);
                m_ConnectionType = other.m_ConnectionType;
            }

            NConnectionConfig::NConnectionConfig(const NString & name, const NString & host, const NUnsignedShort & port, const NString & user, const NString & password,
                                                 const NString & schema, const NConnectionType * connectionType) : INObject()
            {
                m_Name = new NString(name);
                m_Host = new NString(host);
                m_Port = new NUnsignedShort(port);
                m_User = new NString(user);
                m_Password = new NString(password);
                m_Schema = new NString(schema);
                m_ConnectionType = connectionType;
            }

            NConnectionConfig::~NConnectionConfig()
            {
                if (m_Name != NULL)
                    delete m_Name;
                if (m_Host != NULL)
                    delete m_Host;
                if (m_Port != NULL)
                    delete m_Port;
                if (m_User != NULL)
                    delete m_User;
                if (m_Password != NULL)
                    delete m_Password;
                if (m_Schema != NULL)
                    delete m_Schema;
            }

            void NConnectionConfig::setName(const NString & name)
            {
                m_Name->assign(name);
            }

            const NString & NConnectionConfig::getName() const
            {
                return *m_Name;
            }

            void NConnectionConfig::setHost(const NString & host)
            {
                m_Host->assign(host);
            }

            const NString & NConnectionConfig::getHost() const
            {
                return *m_Host;
            }

            void NConnectionConfig::setPort(const NUnsignedShort & port)
            {
                m_Port->setValue(port);
            }

            const NUnsignedShort& NConnectionConfig::getPort() const
            {
                return *m_Port;
            }

            void NConnectionConfig::setUser(const NString & user)
            {
                m_User->assign(user);
            }

            const NString & NConnectionConfig::getUser() const
            {
                return *m_User;
            }

            void NConnectionConfig::setPassword(const NString & password)
            {
                m_Password->assign(password);
            }

            const NString & NConnectionConfig::getPassword() const
            {
                return *m_Password;
            }

            void NConnectionConfig::setSchema(const NString & schema)
            {
                m_Schema->assign(schema);
            }

            const NString & NConnectionConfig::getSchema() const
            {
                return *m_Schema;
            }

            void NConnectionConfig::setConnectionType(const NConnectionType * connectionType)
            {
                m_ConnectionType = connectionType;
            }

            const NConnectionType * NConnectionConfig::getConnectionType() const
            {
                return m_ConnectionType;
            }

            nint NConnectionConfig::compareTo(const INObject * other) const
            {
                if (this == other)
                    return 0;
                try
                {
                    const NConnectionConfig * obj = dynamic_cast<const NConnectionConfig *>(other);

                    if (obj != NULL)
                    {
                        int result = 0;
                        if ((result = getName().compare(obj->getName())) == 0)
                        {
                            if ((result = getHost().compare(obj->getHost())) == 0)
                            {
                                if ((result = getPort().getValue() - obj->getPort().getValue()) == 0)
                                {
                                    if ((result = getUser().compare(obj->getUser())) == 0)
                                    {
                                        if ((result = getPassword().compare(obj->getPassword())) == 0)
                                        {
                                            if ((result = getSchema().compare(obj->getSchema())) == 0)
                                            {
                                                result = getConnectionType()->getValue().compare(obj->getConnectionType()->getValue());
                                            }
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