//
// Created by strohhalm on 03.06.15.
//

#ifndef NMODELCOLUMN_H
#define NMODELCOLUMN_H

#include <nbase/NBaseType.h>
#include <nbase/NDate.h>
#include <nmodel/INModelColumn.h>

namespace nox
{
    namespace model
    {
        template<class VALUE>
        class NModelColumn : public INModelColumn
        {
        protected:
            BOOST_STATIC_ASSERT(!boost::is_pointer<VALUE>::value);
            BOOST_STATIC_ASSERT(boost::is_base_of<INBaseType, VALUE>::value || boost::is_same<NString, VALUE>::value || boost::is_base_of<NDate, VALUE>::value || boost::is_base_of<NTime, VALUE>::value || boost::is_base_of<NDateTime, VALUE>::value);
            VALUE * m_Value;
        public:
            NModelColumn(const NString & columnName) : INModelColumn(columnName)
            {
                m_Value = NULL;
            }

            NModelColumn(const NString & columnName, VALUE * value) : INModelColumn(columnName)
            {
                m_Value = value;
            }

            virtual ~NModelColumn()
            {
                if (m_Value != NULL)
                    delete m_Value;
            }

            virtual size_t getType() const
            {
                return NType<VALUE>::getTypeCode();
            }

            virtual VALUE * getValue() const
            {
                return m_Value;
            }

            virtual void setValue(VALUE * value)
            {
                if (m_Value != NULL)
                    delete m_Value;
                m_Value = value;
            }

            virtual nint compareTo(const INObject * other) const
            {
                if (this == other)
                    return 0;
                try
                {
                    const NModelColumn<VALUE> * obj = dynamic_cast<const NModelColumn<VALUE> *>(other);

                    if (obj != NULL)
                    {
                        int result = 0;
                        if ((result = getColumnName().compare(obj->getColumnName())) == 0)
                        {
                            if (getValue() != NULL)
                            {
                                if (*getValue() == *obj->getValue())
                                {
                                    result = 0;
                                }
                                else if (*getValue() > *obj->getValue())
                                {
                                    result = 1;
                                }
                                else
                                {
                                    result = -1;
                                }
                            }
                            else
                            {
                                if (obj->getValue() != NULL)
                                {
                                    result = -1;
                                }
                                else
                                {
                                    result = 0;
                                }
                            }
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
        };
    }
}

#endif //NMODELCOLUMN_H
