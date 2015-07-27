//
// Created by strohhalm on 03.06.15.
//

#include "INModelAccess.h"

namespace nox
{
    namespace model
    {
        INModelAccess::INModelAccess(const NString & componentName, const NString & tableName) : INObject()
        {
            m_Component = new NString(componentName);
            m_TableName = new NString(tableName);
            m_StatementMap = new NMap<NString, INPreparedStatement *>();
        }

        INModelAccess::~INModelAccess()
        {
            if (m_Component != NULL)
                delete m_Component;
            if (m_TableName != NULL)
                delete m_TableName;
            if (m_StatementMap != NULL)
            {
                INList<NString> * keyList = m_StatementMap->getKeyList();
                for (int i = 0; i < keyList->getSize(); i++)
                {
                    if (m_StatementMap->get(keyList->get(i)) != NULL)
                        delete m_StatementMap->get(keyList->get(i));
                }
                delete m_StatementMap;
            }

        }

        INPreparedStatement * INModelAccess::getPreparedStatement(const NString & name)
        {
            INTransaction * transaction = NTransactionPool::getInstance()->getCurrentTransaction();
            INConnection  * connection = transaction->getConnection(*m_Component);

            if (!m_StatementMap->contains(name))
                m_StatementMap->add(name, connection->createPreparedStatement(name));
            return m_StatementMap->get(name);
        }

        INPreparedStatement * INModelAccess::getPreparedStatement(const NString & name, const NString & statement)
        {
            INTransaction * transaction = NTransactionPool::getInstance()->getCurrentTransaction();
            INConnection  * connection = transaction->getConnection(*m_Component);

            if (!m_StatementMap->contains(name))
                m_StatementMap->add(name, connection->createPreparedStatement(name, statement));
            return m_StatementMap->get(name);
        }
    }
}