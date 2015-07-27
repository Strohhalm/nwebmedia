//
// Created by strohhalm on 09.07.15.
//

#include "NPostgreSqlConnection.h"
#include "NPostgreSqlPreparedStatement.h"

namespace nox
{
    namespace model
    {
        namespace postgresql
        {
            NPostgreSqlConnection::NPostgreSqlConnection(const NString & host, const NUnsignedShort & port, const NString & user, const NString & password, const NString & database)
                    : INConnection(host, port, user, password, database)
            {
                m_Connection = NULL;
                m_Transaction = NULL;
            }

            NPostgreSqlConnection::~NPostgreSqlConnection()
            {
                close();
            }

            nbool NPostgreSqlConnection::isConnected() const
            {
                if (m_Connection != NULL)
                    return m_Connection->is_open();
                return false;
            }

            void NPostgreSqlConnection::connect()
            {
                close();

                m_Connection = new pqxx::connection("dbname=" + *m_Database +
                                                    " user=" + *m_User +
                                                    " password=" + *m_Password +
                                                    " hostaddr=" + *m_Host +
                                                    " port=" + NUnsignedShort::toString(*m_Port));
                if (m_Connection->is_open())
                {
                    m_Transaction = new pqxx::work(*m_Connection);
                    m_IsTransactionOpen = true;
                }
            }

            void NPostgreSqlConnection::rollback()
            {
                if (m_Connection != NULL)
                {
                    if (m_Connection->is_open())
                    {
                        m_Transaction->abort();

                        close();
                    }
                }
            }

            void NPostgreSqlConnection::commit()
            {
                if (m_Connection != NULL)
                {
                    if (m_Connection->is_open())
                    {
                        m_Transaction->commit();

                        close();
                    }
                }
            }

            void NPostgreSqlConnection::close()
            {
                if (m_Connection != NULL)
                {
                    if (m_Connection->is_open())
                    {
                        if (m_IsTransactionOpen)
                            m_Transaction->abort();
                        m_Connection->disconnect();

                        delete m_Transaction;
                        delete m_Connection;

                        m_Transaction = NULL;
                        m_Connection = NULL;
                    }
                }
            }

            void * NPostgreSqlConnection::getBackend()
            {
                return m_Connection;
            }

            INPreparedStatement * NPostgreSqlConnection::createPreparedStatement(const NString & name)
            {
                return new NPostgreSqlPreparedStatement(m_Connection, m_Transaction, name);
            }

            INPreparedStatement * NPostgreSqlConnection::createPreparedStatement(const NString & name, const NString & statement)
            {
                return new NPostgreSqlPreparedStatement(m_Connection, m_Transaction, name, statement);
            }

            nint NPostgreSqlConnection::compareTo(const INObject * other) const
            {
                if (this == other)
                    return 0;
                try
                {
                    const NPostgreSqlConnection * obj = dynamic_cast<const NPostgreSqlConnection *>(other);

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