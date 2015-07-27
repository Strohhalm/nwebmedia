//
// Created by strohhalm on 30.05.15.
//

#include "NTransactionPool.h"

namespace nox
{
    namespace model
    {
        NTransactionPool::NTransaction::NTransaction() : INTransaction()
        {
            m_ConnectionMap = new NMap<NString, INConnection *>();
            m_ConnectionLoaderMap = new NMap<NString, NPlugin *>();
        }

        NTransactionPool::NTransaction::~NTransaction()
        {

            if (m_ConnectionMap != NULL)
            {
                INList<NString> * keyList = m_ConnectionMap->getKeyList();
                for (int i = 0; i < keyList->getSize(); i++)
                {
                    INConnection  * connection = m_ConnectionMap->get(keyList->get(i));
                    if (connection->isConnected())
                    {
                        connection->rollback();
                        connection->close();
                    }
                    NConnectionConfig * config = NTransactionPool::getInstance()->getConnectionConfig(keyList->get(i));

                    if (m_ConnectionLoaderMap->contains(config->getConnectionType()->getValue()))
                    {
                        NPlugin * plugin = m_ConnectionLoaderMap->get(config->getConnectionType()->getValue());
                        if (plugin != NULL)
                        {
                            plugin->executeFunction<void, INConnection *>("DestroyConnection", connection);
                        }
                        else
                        {
                            delete connection;
                        }
                    }
                    else
                    {
                        delete connection;
                    }
                }
                delete m_ConnectionMap;
            }
            if (m_ConnectionLoaderMap != NULL)
            {
                INList<NString> * keyList = m_ConnectionLoaderMap->getKeyList();
                for (int i = 0; i < keyList->getSize(); i++)
                {
                    if (m_ConnectionLoaderMap->get(keyList->get(i)) != NULL)
                        delete m_ConnectionLoaderMap->get(keyList->get(i));
                }
                delete m_ConnectionLoaderMap;
            }
        }

        void NTransactionPool::NTransaction::commit()
        {
            INList<NString> * keyList = m_ConnectionMap->getKeyList();
            for (int i = 0; i < keyList->getSize(); i++)
                commit(keyList->get(i));
        }

        void NTransactionPool::NTransaction::commit(const NString & connectionName)
        {
            if (m_ConnectionMap->contains(connectionName))
            {
                m_ConnectionMap->get(connectionName)->commit();
                m_ConnectionMap->get(connectionName)->close();
            }
        }

        void NTransactionPool::NTransaction::rollback()
        {
            INList<NString> * keyList = m_ConnectionMap->getKeyList();
            for (int i = 0; i < keyList->getSize(); i++)
                rollback(keyList->get(i));
        }

        void NTransactionPool::NTransaction::rollback(const NString & connectionName)
        {
            if (m_ConnectionMap->contains(connectionName))
            {
                m_ConnectionMap->get(connectionName)->rollback();
                m_ConnectionMap->get(connectionName)->close();
            }
        }

        INConnection * NTransactionPool::NTransaction::getConnection(const NString & connectionName)
        {
            if (!m_ConnectionMap->contains(connectionName))
            {
                NConnectionConfig * config = NTransactionPool::getInstance()->getConnectionConfig(connectionName);
                if (config == NULL)
                    throw NRuntimeException("No Connection found for name " + connectionName);

                INConnection * connection = NULL;
                try
                {
                    if (!m_ConnectionLoaderMap->contains(config->getConnectionType()->getValue()))
                        m_ConnectionLoaderMap->add(config->getConnectionType()->getValue(),
                                                   NResourcePool::getResource<NPlugin>("NModel_" + config->getConnectionType()->getValue()));

                    NPlugin * plugin = m_ConnectionLoaderMap->get(config->getConnectionType()->getValue());
                    if (plugin != NULL)
                    {
                        connection = plugin->executeFunction
                                <INConnection *, const NString &, const NUnsignedShort &, const NString &, const NString &, const NString &>
                                ("CreateConnection", config->getHost(), config->getPort(), config->getUser(), config->getPassword(), config->getSchema());
                    }
                    connection->connect();
                }
                catch (exception & exp)
                {
                    if (connection != NULL)
                        delete connection;
                    throw;
                }
                m_ConnectionMap->add(connectionName, connection);
            }
            return m_ConnectionMap->get(connectionName);
        }

        nint NTransactionPool::NTransaction::compareTo(const INObject * other) const
        {
            if (this == other)
                return 0;
            if (this > other)
                return 1;
            return -1;
        }

        NTransactionPool::NTransactionPool() : INSingleton<NTransactionPool>()
        {
            m_TransactionMap = new collection::NMap<boost::thread::id, INTransaction *>();
            m_ConnectionConfigCache = new NConnectionConfigCache();
            m_Mutex = new boost::mutex();
        }

        NTransactionPool::~NTransactionPool()
        {
            if (m_TransactionMap != NULL)
            {
                if (m_TransactionMap->getSize() > 0)
                {
                    collection::INList<boost::thread::id> * keyList = m_TransactionMap->getKeyList();
                    for (int i = 0; i < keyList->getSize(); i++)
                    {
                        delete m_TransactionMap->get(keyList->get(i));
                    }
                }
                delete m_TransactionMap;
            }
            if (m_ConnectionConfigCache != NULL)
                delete m_ConnectionConfigCache;
            if (m_Mutex != NULL)
                delete m_Mutex;
        }

        INTransaction * NTransactionPool::createTransaction()
        {
            INTransaction * result = NULL;
            m_Mutex->lock();
            {
                if (!m_TransactionMap->contains(boost::this_thread::get_id()))
                    m_TransactionMap->add(boost::this_thread::get_id(), new NTransaction());
                result = m_TransactionMap->get(boost::this_thread::get_id());
            }
            m_Mutex->unlock();
            return result;
        }

        INTransaction * NTransactionPool::getCurrentTransaction()
        {
            INTransaction * result = NULL;
            m_Mutex->lock();
            {
                if (m_TransactionMap->contains(boost::this_thread::get_id()))
                    result = m_TransactionMap->get(boost::this_thread::get_id());
            }
            m_Mutex->unlock();
            if (result == NULL)
                result = createTransaction();
            return result;
        }

        void NTransactionPool::destroyCurrentTransaction()
        {
            INTransaction * transaction = getCurrentTransaction();
            m_Mutex->lock();
            {
                if (m_TransactionMap->contains(boost::this_thread::get_id()))
                    m_TransactionMap->remove(boost::this_thread::get_id());
            }
            m_Mutex->unlock();
            if (transaction != NULL)
                delete transaction;
        }

        NConnectionConfig * NTransactionPool::getConnectionConfig(const NString & connectionName)
        {
            NConnectionConfig * result = NULL;

            m_Mutex->lock();
            {
                result = m_ConnectionConfigCache->get(connectionName);
                if (result == NULL)
                    result = m_ConnectionConfigCache->get("DEFAULT");
            }
            m_Mutex->unlock();

            return result;
        }

        nint NTransactionPool::compareTo(const INObject * other) const
        {
            if (other == this)
                return 0;
            if (other > this)
                return -1;
            return 1;
        }
    }
}