//
// Created by strohhalm on 09.07.15.
//

#include "NMySqlPreparedStatement.h"
#include <nmodel/NParameter.h>
#include <nmodel_mysql/NMySqlResultSet.h>

namespace nox
{
    namespace model
    {
        namespace mysql
        {
            NMySqlPreparedStatement::NMySqlPreparedStatement(sql::Connection * connection, const NString & name) : INPreparedStatement(name)
            {
                m_Connection        = connection;
                m_PreparedStatement = NULL;
            }

            NMySqlPreparedStatement::NMySqlPreparedStatement(sql::Connection * connection, const NString & name, const NString & statement) : INPreparedStatement(name, statement)
            {
                m_Connection        = connection;
                m_PreparedStatement = NULL;
            }

            NMySqlPreparedStatement::~NMySqlPreparedStatement()
            {
                if (m_PreparedStatement != NULL)
                    delete m_PreparedStatement;
            }

            void NMySqlPreparedStatement::prepare()
            {
                if (m_ParameterList->getSize() > 0)
                {
                    if (m_ParameterList->get(0)->getName().size() > 0)
                    {
                        prepareNamedParameters();
                    }
                    else
                    {
                        m_PreparedSqlStatement->assign(getStatement());
                    }
                }
                if (m_PreparedStatement == NULL)
                {
                    m_PreparedStatement = m_Connection->prepareStatement(*m_PreparedSqlStatement);
                }
                if (m_PreparedStatement != NULL)
                {
                    applyParameters();
                }
            }

            void NMySqlPreparedStatement::prepareNamedParameters()
            {
                NString statement = getStatement();
                NString paramName;

                regex  _reg(":([A-Za-z0-9_]+)");
                smatch _mat;

                INList<INParameter *> * newParamList = new NList<INParameter *>();

                while (regex_search(statement, _mat, _reg))
                {
                    if (!_mat.empty())
                    {
                        for (nuint i = 0; i < _mat.size(); i++)
                        {
                            paramName = _mat[i].str();

                            for (nlong k = 0; k < m_ParameterList->getSize(); k++)
                            {
                                if (paramName.compare(m_ParameterList->get(k)->getName()) == 0)
                                {
                                    newParamList->add(m_ParameterList->get(k)->clone());
                                    break;
                                }
                            }
                        }
                    }
                    statement = _mat.suffix().str();
                }
                statement = regex_replace(getStatement(), _reg, "?");

                m_PreparedSqlStatement->assign(statement);

                for (nlong i = 0; i < m_ParameterList->getSize(); i++)
                {
                    if (m_ParameterList->get(i) != NULL)
                        delete m_ParameterList->get(i);
                }
                delete m_ParameterList;

                m_ParameterList = newParamList;
            }

            void NMySqlPreparedStatement::applyParameters()
            {
                INParameter * parameter = NULL;
                for (nuint i = 0; i < m_ParameterList->getSize(); i++)
                {
                    parameter = m_ParameterList->get(i);
                    if (parameter->isNull())
                    {
                        m_PreparedStatement->setNull(i + 1, sql::DataType::SQLNULL);
                    }
                    else
                    {
                        if (parameter->getType() == NType<NString>::getTypeCode())
                        {
                            m_PreparedStatement->setString(i + 1, *((NParameter<NString>*)parameter)->getValue());
                        }
                        else if (parameter->getType() == NType<NDateTime>::getTypeCode())
                        {
                            m_PreparedStatement->setDateTime(i + 1, ((NParameter<NDateTime>*)parameter)->getValue()->toString());
                        }
                        else if (parameter->getType() == NType<NDate>::getTypeCode())
                        {
                            m_PreparedStatement->setDateTime(i + 1, ((NParameter<NDate>*)parameter)->getValue()->toString());
                        }
                        else if (parameter->getType() == NType<NTime>::getTypeCode())
                        {
                            m_PreparedStatement->setDateTime(i + 1, ((NParameter<NTime>*)parameter)->getValue()->toString());
                        }
                        else if (parameter->getType() == NType<NShort>::getTypeCode())
                        {
                            m_PreparedStatement->setInt(i + 1, *((NParameter<NShort>*)parameter)->getValue());
                        }
                        else if (parameter->getType() == NType<NUnsignedShort>::getTypeCode())
                        {
                            m_PreparedStatement->setUInt(i + 1, *((NParameter<NUnsignedShort>*)parameter)->getValue());
                        }
                        else if (parameter->getType() == NType<NInteger>::getTypeCode())
                        {
                            m_PreparedStatement->setInt(i + 1, *((NParameter<NInteger>*)parameter)->getValue());
                        }
                        else if (parameter->getType() == NType<NUnsignedInteger>::getTypeCode())
                        {
                            m_PreparedStatement->setUInt(i + 1, *((NParameter<NUnsignedInteger>*)parameter)->getValue());
                        }
                        else if (parameter->getType() == NType<NLong>::getTypeCode())
                        {
                            m_PreparedStatement->setInt64(i + 1, *((NParameter<NLong>*)parameter)->getValue());
                        }
                        else if (parameter->getType() == NType<NUnsignedLong>::getTypeCode())
                        {
                            m_PreparedStatement->setUInt64(i + 1, *((NParameter<NUnsignedLong>*)parameter)->getValue());
                        }
                        else if (parameter->getType() == NType<NLongLong>::getTypeCode())
                        {
                            m_PreparedStatement->setInt64(i + 1, *((NParameter<NLongLong>*)parameter)->getValue());
                        }
                        else if (parameter->getType() == NType<NUnsignedLongLong>::getTypeCode())
                        {
                            m_PreparedStatement->setUInt64(i + 1, *((NParameter<NUnsignedLongLong>*)parameter)->getValue());
                        }
                        else if (parameter->getType() == NType<NDouble>::getTypeCode())
                        {
                            m_PreparedStatement->setDouble(i + 1, *((NParameter<NDouble>*)parameter)->getValue());
                        }
                        else if (parameter->getType() == NType<NLongDouble>::getTypeCode())
                        {
                            m_PreparedStatement->setDouble(i + 1, *((NParameter<NLongDouble>*)parameter)->getValue());
                        }
                        else if (parameter->getType() == NType<NBool>::getTypeCode())
                        {
                            m_PreparedStatement->setBoolean(i + 1, *((NParameter<NBool>*)parameter)->getValue());
                        }
                        else
                        {
                            throw NRuntimeException("Unknown Datatype");
                        }
                    }
                }
            }

            nlong NMySqlPreparedStatement::execute()
            {
                prepare();

                if (m_PreparedStatement->execute())
                {
                    return m_PreparedStatement->getUpdateCount();
                }
                return -1;
            }

            nbool NMySqlPreparedStatement::executeQuery()
            {
                prepare();

                return m_PreparedStatement->execute();
            }

            INResultSet * NMySqlPreparedStatement::getResultSet()
            {
                return new NMySqlResultSet(m_PreparedStatement);
            }

            void NMySqlPreparedStatement::close()
            {
                if (m_PreparedStatement != NULL)
                {
                    m_PreparedStatement->cancel();
                    m_PreparedStatement->close();

                    delete m_PreparedStatement;
                    m_PreparedStatement = NULL;
                }
            }

            nint NMySqlPreparedStatement::compareTo(const INObject * other) const
            {
                if (this == other)
                    return 0;
                try
                {
                    const NMySqlPreparedStatement * obj = dynamic_cast<const NMySqlPreparedStatement *>(other);

                    if (obj != NULL)
                    {
                        nint result = 0;
                        if ((result = getName().compare(obj->getName())) == 0)
                        {
                            result = getStatement().compare(obj->getStatement());
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