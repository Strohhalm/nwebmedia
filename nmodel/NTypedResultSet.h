//
// Created by strohhalm on 10.07.15.
//

#ifndef NWEBMEDIA_NTYPEDRESULTSET_H
#define NWEBMEDIA_NTYPEDRESULTSET_H

#include <nbase/NAssert.h>
#include <nmodel/INModel.h>
#include <nmodel/INResultSet.h>
#include <nmodel/INTypedResultSet.h>

namespace nox
{
    namespace model
    {
        template<class MODEL>
        class NTypedResultSet : public INTypedResultSet<MODEL>
        {
        protected:
            NStaticAssertBaseOf(INModel, MODEL)
            INResultSet * m_ResultSet;
        public:
            NTypedResultSet(INResultSet * resultSet) : INTypedResultSet<MODEL>()
            {
                m_ResultSet = resultSet;
            }

            virtual ~NTypedResultSet()
            {
                close();
            }

            virtual MODEL * first()
            {
                if (m_ResultSet != NULL)
                {
                    if (m_ResultSet->first())
                    {
                        return toModelType();
                    }
                }
                return NULL;
            }

            virtual MODEL * previous()
            {
                if (m_ResultSet != NULL)
                {
                    if (m_ResultSet->previous())
                    {
                        return toModelType();
                    }
                }
                return NULL;
            }

            virtual MODEL * next()
            {
                if (m_ResultSet != NULL)
                {
                    if (m_ResultSet->next())
                    {
                        return toModelType();
                    }
                }
                return NULL;
            }

            virtual MODEL * last()
            {
                if (m_ResultSet != NULL)
                {
                    if (m_ResultSet->last())
                    {
                        return toModelType();
                    }
                }
                return NULL;
            }

            virtual void close()
            {
                if (m_ResultSet != NULL)
                {
                    m_ResultSet->close();

                    delete m_ResultSet;
                    m_ResultSet = NULL;
                }
            }

            virtual nint compare(INObject * other)
            {
                if (this == other)
                    return 0;
                try
                {
                    NTypedResultSet<MODEL> * obj = dynamic_cast<NTypedResultSet<MODEL>*>(other);

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

        protected:
            virtual MODEL * toModelType()
            {
                MODEL * result = NULL;
                if (m_ResultSet != NULL)
                {
                    result = new MODEL();

                    for (nuint i = 0; i < m_ResultSet->getColumnCount(); i++)
                    {
                        assignType(result, i+1);
                    }
                }
                return result;
            }
            virtual void assignType(INModel * result, nuint index)
            {
                switch (m_ResultSet->getColumnType(index))
                {
                    case NResultType::STRING:
                        if (m_ResultSet->isNull(index))
                        {
                            result->setValue<NString>(m_ResultSet->getColumnName(index), NULL);
                        }
                        else
                        {
                            result->setValue<NString>(m_ResultSet->getColumnName(index), new NString(m_ResultSet->getString(index)));
                        }
                        break;
                    case NResultType::DATETIME:
                        if (m_ResultSet->isNull(index))
                        {
                            result->setValue<NDateTime>(m_ResultSet->getColumnName(index), NULL);
                        }
                        else
                        {
                            result->setValue<NDateTime>(m_ResultSet->getColumnName(index), new NDateTime(m_ResultSet->getDateTime(index)));
                        }
                        break;
                    case NResultType::DATE:
                        if (m_ResultSet->isNull(index))
                        {
                            result->setValue<NDate>(m_ResultSet->getColumnName(index), NULL);
                        }
                        else
                        {
                            result->setValue<NDate>(m_ResultSet->getColumnName(index), new NDate(m_ResultSet->getDate(index)));
                        }
                        break;
                    case NResultType::TIME:
                        if (m_ResultSet->isNull(index))
                        {
                            result->setValue<NTime>(m_ResultSet->getColumnName(index), NULL);
                        }
                        else
                        {
                            result->setValue<NTime>(m_ResultSet->getColumnName(index), new NTime(m_ResultSet->getTime(index)));
                        }
                        break;
                    case NResultType::DOUBLE:
                        if (m_ResultSet->isNull(index))
                        {
                            result->setValue<NLongDouble>(m_ResultSet->getColumnName(index), NULL);
                        }
                        else
                        {
                            result->setValue<NLongDouble>(m_ResultSet->getColumnName(index), new NLongDouble(m_ResultSet->getDouble(index)));
                        }
                        break;
                    case NResultType::LONG:
                        if (m_ResultSet->isNull(index))
                        {
                            result->setValue<NLong>(m_ResultSet->getColumnName(index), NULL);
                        }
                        else
                        {
                            result->setValue<NLong>(m_ResultSet->getColumnName(index), new NLong(m_ResultSet->getLong(index)));
                        }
                        break;
                    case NResultType::ULONG:
                        if (m_ResultSet->isNull(index))
                        {
                            result->setValue<NUnsignedLong>(m_ResultSet->getColumnName(index), NULL);
                        }
                        else
                        {
                            result->setValue<NUnsignedLong>(m_ResultSet->getColumnName(index), new NUnsignedLong(m_ResultSet->getUnsignedLong(index)));
                        }
                        break;
                    case NResultType::INT:
                        if (m_ResultSet->isNull(index))
                        {
                            result->setValue<NInteger>(m_ResultSet->getColumnName(index), NULL);
                        }
                        else
                        {
                            result->setValue<NInteger>(m_ResultSet->getColumnName(index), new NInteger(m_ResultSet->getInteger(index)));
                        }
                        break;
                    case NResultType::UINT:
                        if (m_ResultSet->isNull(index))
                        {
                            result->setValue<NUnsignedInteger>(m_ResultSet->getColumnName(index), NULL);
                        }
                        else
                        {
                            result->setValue<NUnsignedInteger>(m_ResultSet->getColumnName(index), new NUnsignedInteger(m_ResultSet->getUnsignedInteger(index)));
                        }
                        break;
                    case NResultType::SHORT:
                        if (m_ResultSet->isNull(index))
                        {
                            result->setValue<NShort>(m_ResultSet->getColumnName(index), NULL);
                        }
                        else
                        {
                            result->setValue<NShort>(m_ResultSet->getColumnName(index), new NShort(m_ResultSet->getShort(index)));
                        }
                        break;
                    case NResultType::USHORT:
                        if (m_ResultSet->isNull(index))
                        {
                            result->setValue<NUnsignedShort>(m_ResultSet->getColumnName(index), NULL);
                        }
                        else
                        {
                            result->setValue<NUnsignedShort>(m_ResultSet->getColumnName(index), new NUnsignedShort(m_ResultSet->getUnsignedShort(index)));
                        }
                        break;
                    case NResultType::BOOL:
                        if (m_ResultSet->isNull(index))
                        {
                            result->setValue<NBool>(m_ResultSet->getColumnName(index), NULL);
                        }
                        else
                        {
                            result->setValue<NBool>(m_ResultSet->getColumnName(index), new NBool(m_ResultSet->getBool(index)));
                        }
                        break;
                    default:
                        throw NRuntimeException("Unknown Type");
                }
            }

            virtual nint compareTo(const INObject * other) const
            {
                if (this == other)
                    return 0;
                try
                {
                    const NTypedResultSet<MODEL> * obj = dynamic_cast<const NTypedResultSet<MODEL> *>(other);

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
        };
    }
}


#endif //NWEBMEDIA_NTYPEDRESULTSET_H
