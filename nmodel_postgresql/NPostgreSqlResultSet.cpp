//
// Created by strohhalm on 10.07.15.
//

#include "NPostgreSqlResultSet.h"

namespace nox
{
    namespace model
    {
        namespace postgresql
        {
            NPostgreSqlResultSet::NPostgreSqlResultSet(pqxx::result result) : INResultSet() , m_Result(result)
            {
                m_RowIndex = 0;
            }

            NPostgreSqlResultSet::~NPostgreSqlResultSet()
            {
                close();
            }

            nbool NPostgreSqlResultSet::first()
            {
                if (m_Result.size() > 0)
                {
                    m_RowIndex = 0;

                    return true;
                }
                return false;
            }

            nbool NPostgreSqlResultSet::previous()
            {
                if (m_Result.size() > 0)
                {
                    if (m_RowIndex > 0)
                    {
                        m_RowIndex--;

                        return true;
                    }
                }
                return false;
            }

            nbool NPostgreSqlResultSet::next()
            {
                if (m_Result.size() > 0)
                {
                    if (m_RowIndex < m_Result.size())
                    {
                        m_RowIndex++;

                        return true;
                    }
                }
                return false;
            }

            nbool NPostgreSqlResultSet::last()
            {
                if (m_Result.size() > 0)
                {
                    m_RowIndex = m_Result.size();

                    return true;
                }
                return false;
            }

            nlong NPostgreSqlResultSet::getColumnCount()
            {
                return m_Result.size();
            }

            const NString NPostgreSqlResultSet::getColumnName(nuint index)
            {
                return m_Result.column_name(index);
            }

            NResultType NPostgreSqlResultSet::getColumnType(nuint index)
            {
                switch (m_Result.column_type(index))
                {
                    case 16:
                        return NResultType::BOOL;
                    case 18:
                    case 25:
                    case 1042:
                    case 1043:
                    case 2275:
                        return NResultType::STRING;
                    case 20:
                        return NResultType::LONG;
                    case 21:
                        return NResultType::SHORT;
                    case 24:
                        return NResultType::INT;
                    case 700:
                    case 701:
                    case 791:
                    case 1700:
                        return NResultType::DOUBLE;
                    case 1082:
                        return NResultType::DATE;
                    case 1083:
                        return NResultType::TIME;
                    case 1114:
                        return NResultType::DATETIME;
                    default:
                        break;
                }
                return NResultType::UNKNOWN;

            }

            NString NPostgreSqlResultSet::getString(nuint index)
            {
                return m_Result[m_RowIndex][index].as<NString>();
            }

            NDateTime NPostgreSqlResultSet::getDateTime(nuint index)
            {
                return m_Result[m_RowIndex][index].as<NString>();
            }

            NDate NPostgreSqlResultSet::getDate(nuint index)
            {
                return m_Result[m_RowIndex][index].as<NString>();
            }

            NTime NPostgreSqlResultSet::getTime(nuint index)
            {
                return m_Result[m_RowIndex][index].as<NString>();
            }

            NLongDouble NPostgreSqlResultSet::getDouble(nuint index)
            {
                return m_Result[m_RowIndex][index].as<ndouble>();
            }

            NLong NPostgreSqlResultSet::getLong(nuint index)
            {
                return m_Result[m_RowIndex][index].as<nlong>();
            }

            NUnsignedLong NPostgreSqlResultSet::getUnsignedLong(nuint index)
            {
                return m_Result[m_RowIndex][index].as<nulong>();
            }

            NInteger NPostgreSqlResultSet::getInteger(nuint index)
            {
                return m_Result[m_RowIndex][index].as<nint>();
            }

            NUnsignedInteger NPostgreSqlResultSet::getUnsignedInteger(nuint index)
            {
                return m_Result[m_RowIndex][index].as<nuint>();
            }

            NShort NPostgreSqlResultSet::getShort(nuint index)
            {
                return m_Result[m_RowIndex][index].as<nshort>();
            }

            NUnsignedShort NPostgreSqlResultSet::getUnsignedShort(nuint index)
            {
                return m_Result[m_RowIndex][index].as<nushort>();
            }

            NBool NPostgreSqlResultSet::getBool(nuint index)
            {
                return m_Result[m_RowIndex][index].as<nbool>();
            }

            nbool NPostgreSqlResultSet::isNull(nuint index)
            {
                return m_Result[m_RowIndex][index].is_null();
            }

            void NPostgreSqlResultSet::close()
            {
                m_Result.clear();
            }

            nint NPostgreSqlResultSet::compareTo(const INObject * other) const
            {
                if (this == other)
                    return 0;
                try
                {
                    const NPostgreSqlResultSet * obj = dynamic_cast<const NPostgreSqlResultSet *>(other);

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