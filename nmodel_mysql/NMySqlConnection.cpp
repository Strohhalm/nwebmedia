//
// Created by strohhalm on 09.07.15.
//

#include "NMySqlConnection.h"
#include "NMySqlPreparedStatement.h"

namespace nox
{
    namespace model
    {
        namespace mysql
        {
            NMySqlConnection::NMySqlConnection(const NString & host, const NUnsignedShort & port, const NString & user, const NString & password, const NString & database)
                            : INConnection(host, port, user, password, database)
            {
                m_Driver = get_driver_instance();
                m_Connection = NULL;
            }

            NMySqlConnection::~NMySqlConnection()
            {
                close();
            }

            nbool NMySqlConnection::isConnected() const
            {
                if (m_Connection != NULL)
                    return !m_Connection->isClosed();
                return false;
            }

            void NMySqlConnection::connect()
            {
                close();

                m_Connection = m_Driver->connect((*m_Host).append(":").append(NUnsignedShort::toString(*m_Port)), *m_User, *m_Password);
                m_Connection->setAutoCommit(false);
                m_Connection->setSchema(*m_Database);
            }

            void NMySqlConnection::rollback()
            {
                if (m_Connection != NULL)
                {
                    if (!m_Connection->isClosed())
                    {
                        m_Connection->rollback();
                        m_Connection->close();

                        delete m_Connection;
                        m_Connection = NULL;
                    }
                }
            }

            void NMySqlConnection::commit()
            {
                if (m_Connection != NULL)
                {
                    if (!m_Connection->isClosed())
                    {
                        m_Connection->commit();
                        m_Connection->close();

                        delete m_Connection;
                        m_Connection = NULL;
                    }
                }
            }

            void NMySqlConnection::close()
            {
                if (m_Connection != NULL)
                {
                    if (!m_Connection->isClosed())
                    {
                        m_Connection->close();

                        delete m_Connection;
                        m_Connection = NULL;
                    }
                }
            }

            void * NMySqlConnection::getBackend()
            {
                return m_Connection;
            }

            INPreparedStatement* NMySqlConnection::createPreparedStatement(const NString & name)
            {
                return new NMySqlPreparedStatement(m_Connection, name);
            }

            INPreparedStatement* NMySqlConnection::createPreparedStatement(const NString & name, const NString & statement)
            {
                return new NMySqlPreparedStatement(m_Connection, name, statement);
            }

            nint NMySqlConnection::compareTo(const INObject * other) const
            {
                if (this == other)
                    return 0;
                try
                {
                    const NMySqlConnection * obj = dynamic_cast<const NMySqlConnection *>(other);

                    if (obj != NULL)
                    {
                        nint result = 0;
                        if ((result = getHost().compare(obj->getHost())) == 0)
                        {
                            if ((result = getPort().getValue() - obj->getPort().getValue()) == 0)
                            {
                                if ((result = getUser().compare(obj->getUser())) == 0)
                                {
                                    if ((result = getPassword().compare(obj->getPassword())) == 0)
                                    {
                                        result = getDatabase().compare(obj->getDatabase());
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