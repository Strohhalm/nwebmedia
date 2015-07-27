//
// Created by strohhalm on 09.07.15.
//

#include "INStatement.h"

namespace nox
{
    namespace model
    {
        INStatement::INStatement() : INObject()
        {
            m_SqlStatement  = new NString();
        }

        INStatement::INStatement(const NString & statement) : INObject()
        {
            m_SqlStatement  = new NString(statement);
        }

        INStatement::~INStatement()
        {
            if (m_SqlStatement != NULL)
                delete m_SqlStatement;
        }

        void INStatement::setStatement(const NString & statement)
        {
            m_SqlStatement->assign(statement);
        }

        const NString & INStatement::getStatement() const
        {
            return *m_SqlStatement;
        }
    }
}