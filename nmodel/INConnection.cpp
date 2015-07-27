//
// Created by strohhalm on 09.07.15.
//

#include "INConnection.h"

namespace nox
{
    namespace model
    {
        INConnection::INConnection(const NString & host, const NUnsignedShort & port, const NString & user, const NString & password, const NString & database)
        {
            m_Host = new NString(host);
            m_Port = new NUnsignedShort(port);
            m_User = new NString(user);
            m_Password = new NString(password);
            m_Database = new NString(database);
        }

        INConnection::~INConnection()
        {
            if (m_Host != NULL)
                delete m_Host;
            if (m_Port != NULL)
                delete m_Port;
            if (m_User != NULL)
                delete m_User;
            if (m_Password != NULL)
                delete m_Password;
            if (m_Database != NULL)
                delete m_Database;
        }

        const NString & INConnection::getHost() const
        {
            return *m_Host;
        }

        const NUnsignedShort & INConnection::getPort() const
        {
            return *m_Port;
        }

        const NString & INConnection::getUser() const
        {
            return *m_User;
        }

        const NString & INConnection::getPassword() const
        {
            return *m_Password;
        }

        const NString & INConnection::getDatabase() const
        {
            return *m_Database;
        }
    }
}