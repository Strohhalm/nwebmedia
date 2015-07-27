//
// Created by strohhalm on 02.06.15.
//

#ifndef NBASETYPE_H
#define NBASETYPE_H

#include <nbase/INObject.h>
#include <nbase/NAssert.h>
#include <nbase/NDateTime.h>

namespace nox
{
    class INBaseType : public INObject
    {
    public:
        INBaseType();
        virtual ~INBaseType();
    };

    template<class VALUE>
    class NBaseType : public INBaseType
    {
    public:
        template<class U = VALUE>
        static typename enable_if<is_same<U, nbool>::value, NBaseType<U>>::type fromString(const NString & value)
        {
            if (value.length() == 1)
            {
                if (value[0] == 't')
                {
                    return true;
                }
            }
            else
            {
                if (value.length() == 4)
                {
                    if ((value[0] == 'T' || value[0] == 't') &&
                        (value[1] == 'R' || value[1] == 'r') &&
                        (value[2] == 'U' || value[2] == 'u') &&
                        (value[3] == 'E' || value[3] == 'e'))
                    {
                        return true;
                    }
                }
            }
            return false;
        }

        template<class U = VALUE>
        static typename enable_if<!is_same<U, nbool>::value, NBaseType<U>>::type fromString(const NString & value)
        {
            return NBaseType<U>(boost::lexical_cast<VALUE>(value));
        }

        static NString toString(const NBaseType<VALUE> & value)
        {
            return boost::lexical_cast<NString, VALUE>(value);
        }

    protected:
        NStaticAssert(is_literal_type<VALUE>::value || is_floating_point<VALUE>::value);
        VALUE m_Value;
    public:
        NBaseType() : INBaseType()
        {
            m_Value = 0;
        }

        NBaseType(const VALUE & value) : INBaseType()
        {
            m_Value = value;
        }

        NBaseType(const NBaseType<VALUE> & other) : INBaseType()
        {
            m_Value = other.m_Value;
        }

        virtual ~NBaseType()
        {

        }

        virtual operator VALUE() const
        {
            return m_Value;
        }

        virtual NBaseType<VALUE> & operator=(const VALUE value)
        {
            m_Value = value;

            return *this;
        }

        virtual NBaseType<VALUE> & operator=(NBaseType<VALUE> & value)
        {
            m_Value = value.getValue();

            return *this;
        }

        virtual NBaseType<VALUE> operator+(const VALUE value)
        {
            return NBaseType<VALUE>(m_Value + value);
        }

        virtual NBaseType<VALUE> operator+(NBaseType<VALUE> & value)
        {
            return NBaseType<VALUE>(m_Value + value.getValue());
        }

        virtual NBaseType<VALUE> & operator+=(const VALUE value)
        {
            m_Value += value;

            return *this;
        }

        virtual NBaseType<VALUE> & operator+=(NBaseType<VALUE> & value)
        {
            m_Value += value.getValue();

            return *this;
        }

        virtual NBaseType<VALUE> operator-(const VALUE value)
        {
            return NBaseType<VALUE>(m_Value - value);
        }

        virtual NBaseType<VALUE> operator-(NBaseType<VALUE> & value)
        {
            return NBaseType<VALUE>(m_Value - value.getValue());
        }

        virtual NBaseType<VALUE> & operator-=(const VALUE value)
        {
            m_Value -= value;

            return *this;
        }

        virtual NBaseType<VALUE> & operator-=(NBaseType<VALUE> & value)
        {
            m_Value -= value.getValue();

            return *this;
        }

        virtual NBaseType<VALUE> operator*(const VALUE value)
        {
            return NBaseType<VALUE>(m_Value * value);
        }

        virtual NBaseType<VALUE> operator*(NBaseType<VALUE> & value)
        {
            return NBaseType<VALUE>(m_Value * value.getValue());
        }

        virtual NBaseType<VALUE> & operator*=(const VALUE value)
        {
            m_Value *= value;

            return *this;
        }

        virtual NBaseType<VALUE> & operator*=(NBaseType<VALUE> & value)
        {
            m_Value *= value.getValue();

            return *this;
        }

        virtual NBaseType<VALUE> operator/(const VALUE value)
        {
            return NBaseType<VALUE>(m_Value / value);
        }

        virtual NBaseType<VALUE> operator/(NBaseType<VALUE> & value)
        {
            return NBaseType<VALUE>(m_Value / value.getValue());
        }

        virtual NBaseType<VALUE> & operator/=(const VALUE value)
        {
            m_Value /= value;

            return *this;
        }

        virtual NBaseType<VALUE> & operator/=(NBaseType<VALUE> & value)
        {
            m_Value /= value.getValue();

            return *this;
        }

        virtual void setValue(VALUE value)
        {
            m_Value = value;
        }

        virtual VALUE getValue() const
        {
            return m_Value;
        }

        template<class TYPE>
        TYPE as() const
        {
            NStaticAssert(is_literal_type<TYPE>::value || is_floating_point<TYPE>::value);
            return (TYPE)getValue();
        }

        virtual NString toString() const
        {
            return NBaseType<VALUE>::toString(*this);
        }

        virtual nint compareTo(const INObject * other) const
        {
            if (this == other)
                return 0;
            try
            {
                const NBaseType<VALUE> * obj = dynamic_cast<const NBaseType<VALUE> *>(other);

                if (obj != NULL)
                {
                    return getValue() - obj->getValue();
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

    template<class TYPE>
    class NType
    {
    public:
        static size_t getTypeCode()
        {
            return typeid(TYPE).hash_code();
        }

        static NString getTypeName()
        {
            return NString(typeid(TYPE).name());
        }
    };

    typedef NBaseType<nshort> NShort;
    typedef NBaseType<nushort> NUnsignedShort;
    typedef NBaseType<nint> NInteger;
    typedef NBaseType<nuint> NUnsignedInteger;
    typedef NBaseType<nlong> NLong;
    typedef NBaseType<nulong> NUnsignedLong;
    typedef NBaseType<nlonglong> NLongLong;
    typedef NBaseType<nulonglong> NUnsignedLongLong;
    typedef NBaseType<nfloat> NFloat;
    typedef NBaseType<ndouble> NDouble;
    typedef NBaseType<nlongdouble> NLongDouble;
    typedef NBaseType<nbool> NBool;
    typedef NBaseType<nchar> NChar;
}


#endif //NBASETYPE_H
