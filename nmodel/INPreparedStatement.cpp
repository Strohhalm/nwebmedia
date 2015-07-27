//
// Created by strohhalm on 05.06.15.
//

#include "INPreparedStatement.h"

namespace nox
{
    namespace model
    {
        INPreparedStatement::INPreparedStatement(const NString & name) : INStatement()
        {
            m_ParameterList = new NList<INParameter *>();
            m_Name = new NString(name);
            m_PreparedSqlStatement = new NString();
        }

        INPreparedStatement::INPreparedStatement(const NString & name, const NString & statement) : INStatement(statement)
        {
            m_ParameterList = new NList<INParameter *>();
            m_Name = new NString(name);
            m_PreparedSqlStatement = new NString();
        }

        INPreparedStatement::~INPreparedStatement()
        {
            if (m_ParameterList != NULL)
            {
                clearParameters();
                delete m_ParameterList;
            }
            if (m_Name != NULL)
                delete m_Name;
            if (m_PreparedSqlStatement != NULL)
                delete m_PreparedSqlStatement;
        }

        const NString& INPreparedStatement::getName() const
        {
            return *m_Name;
        }

        void INPreparedStatement::addParameter(INParameter * param)
        {
            if (param != NULL)
                m_ParameterList->add(param);
        }

        void INPreparedStatement::clearParameters()
        {
            if (m_ParameterList != NULL)
            {
                for (int i = 0; i < m_ParameterList->getSize(); i++)
                {
                    if (m_ParameterList->get(i) != NULL)
                        delete m_ParameterList->get(i);
                }
                m_ParameterList->clear();
            }
        }
    }
}