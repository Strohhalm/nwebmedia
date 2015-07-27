//
// Created by strohhalm on 09.07.15.
//

#include <nbase/NRuntimeException.h>
#include "NMySqlResultSet.h"

namespace nox
{
    namespace model
    {
        namespace mysql
        {
            NMySqlResultSet::NMySqlResultSet(sql::PreparedStatement * statement) : INResultSet()
            {
                m_ResultSet = statement->getResultSet();
                m_MetaData  = m_ResultSet->getMetaData();
            }

            NMySqlResultSet::~NMySqlResultSet()
            {
                close();
            }

            nbool NMySqlResultSet::first()
            {
                if (m_ResultSet != NULL)
                {
                    if (!m_ResultSet->isClosed())
                    {
                        return m_ResultSet->first();
                    }
                }
                return false;
            }

            nbool NMySqlResultSet::previous()
            {
                if (m_ResultSet != NULL)
                {
                    if (!m_ResultSet->isClosed())
                    {
                        return m_ResultSet->previous();
                    }
                }
                return false;
            }

            nbool NMySqlResultSet::next()
            {
                if (m_ResultSet != NULL)
                {
                    if (!m_ResultSet->isClosed())
                    {
                        return m_ResultSet->next();
                    }
                }
                return false;
            }

            nbool NMySqlResultSet::last()
            {
                if (m_ResultSet != NULL)
                {
                    if (!m_ResultSet->isClosed())
                    {
                        return m_ResultSet->last();
                    }
                }
                return false;
            }

            nlong NMySqlResultSet::getColumnCount()
            {
                if (m_ResultSet != NULL)
                {
                    if (!m_ResultSet->isClosed())
                    {
                        if (m_MetaData != NULL)
                        {
                            return m_MetaData->getColumnCount();
                        }
                    }
                }
                return -1;
            }

            const NString NMySqlResultSet::getColumnName(nuint index)
            {
                if (m_ResultSet != NULL)
                {
                    if (!m_ResultSet->isClosed())
                    {
                        if (m_MetaData != NULL)
                        {
                            return m_MetaData->getColumnName(index);
                        }
                    }
                }
                throw NRuntimeException("Resultset is not open");
            }

            NString NMySqlResultSet::getString(nuint index)
            {
                if (m_ResultSet != NULL)
                {
                    if (!m_ResultSet->isClosed())
                    {
                        return m_ResultSet->getString(index);
                    }
                }
                throw NRuntimeException("Resultset is not open");
            }

            NDateTime NMySqlResultSet::getDateTime(nuint index)
            {
                if (m_ResultSet != NULL)
                {
                    if (!m_ResultSet->isClosed())
                    {
                        return NDateTime(m_ResultSet->getString(index));
                    }
                }
                throw NRuntimeException("Resultset is not open");
            }

            NDate NMySqlResultSet::getDate(nuint index)
            {
                if (m_ResultSet != NULL)
                {
                    if (!m_ResultSet->isClosed())
                    {
                        return NDate(m_ResultSet->getString(index));
                    }
                }
                throw NRuntimeException("Resultset is not open");
            }

            NTime NMySqlResultSet::getTime(nuint index)
            {
                if (m_ResultSet != NULL)
                {
                    if (!m_ResultSet->isClosed())
                    {
                        return NTime(m_ResultSet->getString(index));
                    }
                }
                throw NRuntimeException("Resultset is not open");
            }

            NLongDouble NMySqlResultSet::getDouble(nuint index)
            {
                if (m_ResultSet != NULL)
                {
                    if (!m_ResultSet->isClosed())
                    {
                        return NLongDouble(m_ResultSet->getDouble(index));
                    }
                }
                throw NRuntimeException("Resultset is not open");
            }

            NLong NMySqlResultSet::getLong(nuint index)
            {
                if (m_ResultSet != NULL)
                {
                    if (!m_ResultSet->isClosed())
                    {
                        return NLong(m_ResultSet->getInt64(index));
                    }
                }
                throw NRuntimeException("Resultset is not open");
            }

            NUnsignedLong NMySqlResultSet::getUnsignedLong(nuint index)
            {
                if (m_ResultSet != NULL)
                {
                    if (!m_ResultSet->isClosed())
                    {
                        return NUnsignedLong(m_ResultSet->getUInt64(index));
                    }
                }
                throw NRuntimeException("Resultset is not open");
            }

            NInteger NMySqlResultSet::getInteger(nuint index)
            {
                if (m_ResultSet != NULL)
                {
                    if (!m_ResultSet->isClosed())
                    {
                        return NInteger(m_ResultSet->getInt(index));
                    }
                }
                throw NRuntimeException("Resultset is not open");
            }

            NUnsignedInteger NMySqlResultSet::getUnsignedInteger(nuint index)
            {
                if (m_ResultSet != NULL)
                {
                    if (!m_ResultSet->isClosed())
                    {
                        return NUnsignedInteger(m_ResultSet->getUInt(index));
                    }
                }
                throw NRuntimeException("Resultset is not open");
            }

            NShort NMySqlResultSet::getShort(nuint index)
            {
                if (m_ResultSet != NULL)
                {
                    if (!m_ResultSet->isClosed())
                    {
                        return NShort(m_ResultSet->getInt(index));
                    }
                }
                throw NRuntimeException("Resultset is not open");
            }

            NUnsignedShort NMySqlResultSet::getUnsignedShort(nuint index)
            {
                if (m_ResultSet != NULL)
                {
                    if (!m_ResultSet->isClosed())
                    {
                        return NUnsignedShort(m_ResultSet->getInt(index));
                    }
                }
                throw NRuntimeException("Resultset is not open");
            }

            NBool NMySqlResultSet::getBool(nuint index)
            {
                if (m_ResultSet != NULL)
                {
                    if (!m_ResultSet->isClosed())
                    {
                        return NBool(m_ResultSet->getBoolean(index));
                    }
                }
                throw NRuntimeException("Resultset is not open");
            }

            nbool NMySqlResultSet::isNull(nuint index)
            {
                if (m_ResultSet != NULL)
                {
                    if (!m_ResultSet->isClosed())
                    {
                        return m_ResultSet->isNull(index);
                    }
                }
                return true;
            }

            NResultType NMySqlResultSet::getColumnType(nuint index)
            {
                if (m_ResultSet != NULL)
                {
                    if (m_MetaData != NULL)
                    {
                        switch (m_MetaData->getColumnType(index))
                        {
                            case sql::DataType::TINYINT:
                                return NResultType::BOOL;
                            case sql::DataType::SMALLINT:
                                if (m_MetaData->isSigned(index))
                                    return NResultType::SHORT;
                                return NResultType::USHORT;
                            case sql::DataType::MEDIUMINT:
                            case sql::DataType::INTEGER:
                                if (m_MetaData->isSigned(index))
                                    return NResultType::INT;
                                return NResultType::UINT;
                            case sql::DataType::BIGINT:
                                if (m_MetaData->isSigned(index))
                                    return NResultType::LONG;
                                return NResultType::ULONG;
                            case sql::DataType::REAL:
                            case sql::DataType::DOUBLE:
                            case sql::DataType::DECIMAL:
                                return NResultType::DOUBLE;
                            case sql::DataType::DATE:
                                return NResultType::DATE;
                            case sql::DataType::TIME:
                                return NResultType::TIME;
                            case sql::DataType::TIMESTAMP:
                                return NResultType::DATETIME;
                            case sql::DataType::CHAR:
                            case sql::DataType::VARCHAR:
                            case sql::DataType::LONGVARCHAR:
                                return NResultType::STRING;
                            case sql::DataType::BINARY:
                            case sql::DataType::VARBINARY:
                            case sql::DataType::LONGVARBINARY:
                                break;
                            default:
                                break;
                        }
                    }
                }
                return NResultType::UNKNOWN;
            }

            void NMySqlResultSet::close()
            {
                if (m_ResultSet != NULL)
                {
                    m_ResultSet->close();

                    delete m_ResultSet;
                    m_ResultSet = NULL;
                }
            }

            nint NMySqlResultSet::compareTo(const INObject * other) const
            {
                if (this == other)
                    return 0;
                try
                {
                    const NMySqlResultSet * obj = dynamic_cast<const NMySqlResultSet *>(other);

                    if (obj != NULL)
                    {
                        if (this > obj)
                            return 1;
                        return -1;
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