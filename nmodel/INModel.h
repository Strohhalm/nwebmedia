//
// Created by strohhalm on 03.06.15.
//

#ifndef INMODEL_H
#define INMODEL_H

#include <nbase/NAssert.h>
#include <nbase/NIndexOutOfBoundsException.h>
#include <nbase/collection/INMap.h>
#include <nmodel/INModelColumn.h>
#include <nmodel/NModelColumn.h>

using namespace nox::collection;

namespace nox
{
    namespace model
    {
        class INModel : public INObject
        {
        protected:
            NString * m_TableName;
            INMap<NString, INModelColumn *> * m_Columns;
        public:
            INModel(const NString & tableName);
            INModel(const INModel & other);
            virtual ~INModel();
            template<class TYPE>
            void setValue(const NString & columnName, TYPE * value)
            {
                if (m_Columns->contains(columnName))
                {
                    NModelColumn<TYPE> * column = static_cast<NModelColumn<TYPE>*>(m_Columns->get(columnName));

                    NAssertNull(column)

                    column->setValue(value);
                }
                else
                {
                    throw NRuntimeException(NString("Column ").append(columnName).append(" does not exist in model"));
                }
            }
            template<class TYPE>
            void setValue(long columnIndex, TYPE * value)
            {
                if (columnIndex >= 0 && columnIndex < m_Columns->getSize())
                {
                    setValue<TYPE>(m_Columns->getKeyList()->get(columnIndex), value);
                }
                else
                {
                    throw NIndexOutOfBoundsException();
                }
            }
            template<class TYPE>
            TYPE * getValue(const NString & columnName) const
            {
                if (m_Columns->contains(columnName))
                {
                    NModelColumn<TYPE> * column = static_cast<NModelColumn<TYPE>*>(m_Columns->get(columnName));

                    NAssertNull(column)

                    return column->getValue();
                }
                else
                {
                    throw NRuntimeException("Column does not exist in model");
                }
            }
            template<class TYPE>
            TYPE * getValue(long columnIndex) const
            {
                if (columnIndex >= 0 && columnIndex < m_Columns->getSize())
                {
                    return getValue<TYPE>(m_Columns->getKeyList()->get(columnIndex));
                }
                else
                {
                    throw NIndexOutOfBoundsException();
                }
            }
        protected:
            template<class TYPE>
            nint compare(const TYPE * one, const TYPE * two) const
            {
                if (one == NULL && two == NULL)
                {
                    return 0;
                }
                else if (one == NULL)
                {
                    return -1;
                }
                else if (two == NULL)
                {
                    return 1;
                }
                else
                {
                    if (*one == *two)
                    {
                        return 0;
                    }
                    else if (*one > *two)
                    {
                        return 1;
                    }
                    return -1;
                }
            }
        };
    }
}
#define DeclareModelValueFunction(COLUMN_NAME, VALUE_NAME, VALUE_TYPE)                              \
    virtual VALUE_TYPE * get##VALUE_NAME() const;                                                   \
    virtual void set##VALUE_NAME(VALUE_TYPE * value);                                               \
    virtual void set##VALUE_NAME(const VALUE_TYPE & value);

#define DefineModelValueFunction(MODEL_TYPE, COLUMN_NAME, VALUE_NAME, VALUE_TYPE)                   \
    VALUE_TYPE * MODEL_TYPE::get##VALUE_NAME() const                                                \
    {                                                                                               \
        return INModel::getValue<VALUE_TYPE>(NString(#COLUMN_NAME));                                \
    }                                                                                               \
    void MODEL_TYPE::set##VALUE_NAME(VALUE_TYPE * value)                                            \
    {                                                                                               \
        INModel::setValue<VALUE_TYPE>(NString(#COLUMN_NAME), value);                                \
    }                                                                                               \
    void MODEL_TYPE::set##VALUE_NAME(const VALUE_TYPE & value)                                      \
    {                                                                                               \
        INModel::setValue<VALUE_TYPE>(NString(#COLUMN_NAME), new VALUE_TYPE(value));                \
    }

#define CreateModelColumn(COLUMN_NAME, VALUE_TYPE)                                                  \
    m_Columns->add(NString(#COLUMN_NAME),                                                           \
                   new NModelColumn<VALUE_TYPE>(NString(#COLUMN_NAME)));

#endif //INMODEL_H
