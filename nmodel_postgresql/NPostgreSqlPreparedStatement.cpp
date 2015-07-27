//
// Created by strohhalm on 10.07.15.
//

#include <nmodel/NParameter.h>
#include "NPostgreSqlPreparedStatement.h"
#include "NPostgreSqlResultSet.h"

namespace nox
{
    namespace model
    {
        namespace postgresql
        {
            NPostgreSqlPreparedStatement::NPostgreSqlPreparedStatement(pqxx::connection * connection, pqxx::work * transaction, const NString & name) : INPreparedStatement(name)
            {
                m_Connection = connection;
                m_Transaction = transaction;
            }

            NPostgreSqlPreparedStatement::NPostgreSqlPreparedStatement(pqxx::connection * connection, pqxx::work * transaction, const NString & name, const NString & statement) : INPreparedStatement(name, statement)
            {
                m_Connection = connection;
                m_Transaction = transaction;
            }

            NPostgreSqlPreparedStatement::~NPostgreSqlPreparedStatement()
            {

            }

            void NPostgreSqlPreparedStatement::prepare()
            {
                if (m_ParameterList->getSize() > 0)
                {
                    if (m_ParameterList->get(0)->getName().size() > 0)
                    {
                        prepareNamedParameters();
                    }
                }
                NString::iterator beginIterator = m_PreparedSqlStatement->begin();
                NString::iterator endIterator = m_PreparedSqlStatement->end();

                NUnsignedLong counter = 1;
                while (beginIterator != endIterator)
                {
                    if (*beginIterator == '?')
                    {
                        m_PreparedSqlStatement->replace(beginIterator, beginIterator, "$" + counter.toString());
                    }
                    counter += 1;
                    beginIterator++;
                }

                if (!m_Transaction->prepared(getName()).exists())
                {
                    prepareStatement();
                }
            }

            nlong NPostgreSqlPreparedStatement::execute()
            {
                return applyParameters(m_Transaction->prepared(getName())).exec().affected_rows();
            }

            nbool NPostgreSqlPreparedStatement::executeQuery()
            {
                return !(m_Result = applyParameters(m_Transaction->prepared(getName())).exec()).empty();
            }

            INResultSet * NPostgreSqlPreparedStatement::getResultSet()
            {
                return new NPostgreSqlResultSet(m_Result);
            }

            void NPostgreSqlPreparedStatement::close()
            {
            }

            void NPostgreSqlPreparedStatement::prepareNamedParameters()
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

                for (int i = 0; i < m_ParameterList->getSize(); i++)
                {
                    if (m_ParameterList->get(i) != NULL)
                        delete m_ParameterList->get(i);
                }
                delete m_ParameterList;

                m_ParameterList = newParamList;
            }

            void NPostgreSqlPreparedStatement::prepareStatement()
            {
                pqxx::prepare::declaration _dec = m_Connection->prepare(*m_PreparedSqlStatement);
                INParameter * parameter = NULL;
                for (int i = 0; i < m_ParameterList->getSize(); i++)
                {
                    parameter = m_ParameterList->get(i);
                    if (parameter->getType() == NType<NString>::getTypeCode())
                    {
                        _dec.operator()("varchar", pqxx::prepare::treat_string);
                    }
                    else if (parameter->getType() == NType<NDateTime>::getTypeCode())
                    {
                        _dec.operator()("timestamp");
                    }
                    else if (parameter->getType() == NType<NDate>::getTypeCode())
                    {
                        _dec.operator()("date");
                    }
                    else if (parameter->getType() == NType<NTime>::getTypeCode())
                    {
                        _dec.operator()("time");
                    }
                    else if (parameter->getType() == NType<NShort>::getTypeCode())
                    {
                        _dec.operator()("smallint");
                    }
                    else if (parameter->getType() == NType<NUnsignedShort>::getTypeCode())
                    {
                        _dec.operator()("smallint");
                    }
                    else if (parameter->getType() == NType<NInteger>::getTypeCode())
                    {
                        _dec.operator()("integer");
                    }
                    else if (parameter->getType() == NType<NUnsignedInteger>::getTypeCode())
                    {
                        _dec.operator()("integer");
                    }
                    else if (parameter->getType() == NType<NLong>::getTypeCode())
                    {
                        _dec.operator()("bigint");
                    }
                    else if (parameter->getType() == NType<NUnsignedLong>::getTypeCode())
                    {
                        _dec.operator()("bigint");
                    }
                    else if (parameter->getType() == NType<NLongLong>::getTypeCode())
                    {
                        _dec.operator()("bigint");
                    }
                    else if (parameter->getType() == NType<NUnsignedLongLong>::getTypeCode())
                    {
                        _dec.operator()("bigint");
                    }
                    else if (parameter->getType() == NType<NDouble>::getTypeCode())
                    {
                        _dec.operator()("double precision");
                    }
                    else if (parameter->getType() == NType<NLongDouble>::getTypeCode())
                    {
                        _dec.operator()("double precision");
                    }
                    else if (parameter->getType() == NType<NBool>::getTypeCode())
                    {
                        _dec.operator()("boolean");
                    }
                    else
                    {
                        throw NRuntimeException("Unknown Datatype");
                    }
                }
            }

            pqxx::prepare::invocation NPostgreSqlPreparedStatement::applyParameters(pqxx::prepare::invocation _inv)
            {
                INParameter * parameter = NULL;
                for (int i = 0; i < m_ParameterList->getSize(); i++)
                {
                    parameter = m_ParameterList->get(i);
                    if (parameter->isNull())
                    {
                        _inv.operator()();
                    }
                    else
                    {
                        if (parameter->getType() == NType<NString>::getTypeCode())
                        {
                            _inv.operator()(*((NParameter<NString>*)parameter)->getValue());
                        }
                        else if (parameter->getType() == NType<NDateTime>::getTypeCode())
                        {
                            _inv.operator()(((NParameter<NDateTime>*)parameter)->getValue()->toString());
                        }
                        else if (parameter->getType() == NType<NDate>::getTypeCode())
                        {
                            _inv.operator()(((NParameter<NDate>*)parameter)->getValue()->toString());
                        }
                        else if (parameter->getType() == NType<NTime>::getTypeCode())
                        {
                            _inv.operator()(((NParameter<NTime>*)parameter)->getValue()->toString());
                        }
                        else if (parameter->getType() == NType<NShort>::getTypeCode())
                        {
                            _inv.operator()(((NParameter<NShort>*)parameter)->getValue()->getValue());
                        }
                        else if (parameter->getType() == NType<NUnsignedShort>::getTypeCode())
                        {
                            _inv.operator()(((NParameter<NUnsignedShort>*)parameter)->getValue()->getValue());
                        }
                        else if (parameter->getType() == NType<NInteger>::getTypeCode())
                        {
                            _inv.operator()(((NParameter<NInteger>*)parameter)->getValue()->getValue());
                        }
                        else if (parameter->getType() == NType<NUnsignedInteger>::getTypeCode())
                        {
                            _inv.operator()(((NParameter<NUnsignedInteger>*)parameter)->getValue()->getValue());
                        }
                        else if (parameter->getType() == NType<NLong>::getTypeCode())
                        {
                            _inv.operator()(((NParameter<NLong>*)parameter)->getValue()->getValue());
                        }
                        else if (parameter->getType() == NType<NUnsignedLong>::getTypeCode())
                        {
                            _inv.operator()(((NParameter<NUnsignedLong>*)parameter)->getValue()->getValue());
                        }
                        else if (parameter->getType() == NType<NLongLong>::getTypeCode())
                        {
                            _inv.operator()(((NParameter<NLongLong>*)parameter)->getValue()->getValue());
                        }
                        else if (parameter->getType() == NType<NUnsignedLongLong>::getTypeCode())
                        {
                            _inv.operator()(((NParameter<NUnsignedLongLong>*)parameter)->getValue()->getValue());
                        }
                        else if (parameter->getType() == NType<NDouble>::getTypeCode())
                        {
                            _inv.operator()(((NParameter<NDouble>*)parameter)->getValue()->getValue());
                        }
                        else if (parameter->getType() == NType<NLongDouble>::getTypeCode())
                        {
                            _inv.operator()(((NParameter<NLongDouble>*)parameter)->getValue()->getValue());
                        }
                        else if (parameter->getType() == NType<NBool>::getTypeCode())
                        {
                            _inv.operator()(((NParameter<NBool>*)parameter)->getValue()->getValue());
                        }
                        else
                        {
                            throw NRuntimeException("Unknown Datatype");
                        }
                    }
                }
                return _inv;
            }

            nint NPostgreSqlPreparedStatement::compareTo(const INObject * other) const
            {
                if (this == other)
                    return 0;
                try
                {
                    const NPostgreSqlPreparedStatement * obj = dynamic_cast<const NPostgreSqlPreparedStatement *>(other);

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