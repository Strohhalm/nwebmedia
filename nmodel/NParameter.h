//
// Created by strohhalm on 05.06.15.
//

#ifndef NPARAMETER_H
#define NPARAMETER_H

#include <nbase/NBaseType.h>
#include <nmodel/INParameter.h>

namespace nox
{
    namespace model
    {
        template<class VALUE>
        class NParameter : public INParameter
        {
        protected:
            VALUE * m_Value;
        public:
            NParameter() : INParameter()
            {
                m_Value = NULL;
            }

            NParameter(const NString &paramName) : INParameter(paramName)
            {
                m_Value = NULL;
            }

            NParameter(const NString &paramName, VALUE * value) : INParameter(paramName)
            {
                m_Value = value;
            }

            NParameter(const NString &paramName, const VALUE & value) : INParameter(paramName)
            {
                m_Value = new VALUE(value);
            }

            NParameter(const NParameter & other) : INParameter(other)
            {
                m_Value = new VALUE(*other.m_Value);
            }

            virtual ~NParameter()
            {
                if (m_Value != NULL)
                    delete m_Value;
            }

            virtual void setValue(VALUE * value)
            {
                if (m_Value != NULL)
                    delete m_Value;
                m_Value = value;
            }

            virtual VALUE * getValue() const
            {
                return m_Value;
            }

            virtual size_t getType() const
            {
                return NType<VALUE>::getTypeCode();
            }

            virtual bool isNull() const
            {
                return m_Value == NULL;
            }

            virtual INParameter * clone()
            {
                return new NParameter<VALUE>(*this);
            }

            virtual nint compareTo(const INObject * other) const
            {
                if (this == other)
                    return 0;
                try
                {
                    const NParameter<VALUE> * obj = dynamic_cast<const NParameter<VALUE> *>(other);

                    if (obj != NULL)
                    {
                        nint result = 0;
                        if ((result = this->getName().compare(obj->getName())) == 0)
                        {
                            if (getValue() == obj->getValue())
                            {
                                result = 0;
                            }
                            else if (getValue() > obj->getValue())
                            {
                                result = 1;
                            }
                            else
                            {
                                result = -1;
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


#endif //NPARAMETER_H
