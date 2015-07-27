//
// Created by strohhalm on 06.06.15.
//

#ifndef INENUM_H
#define INENUM_H

#include <nbase/NBase.h>
#include <nbase/NBaseType.h>
#include "IINEnumeration.h"

using namespace nox::collection;

namespace nox
{
    namespace enumeration
    {
        template<class ENUM, class TYPE>
        class INEnumeration : public IINEnumeration
        {
        protected:
            BOOST_STATIC_ASSERT(!is_pointer<ENUM>::value);
        public:
            static const ENUM * getByName(const NString & name)
            {
                NString enumName = typeid(ENUM).name();
                if (IINEnumeration::getEnumMap()->contains(enumName))
                {
                    INList<IINEnumeration *> * enumList = IINEnumeration::getEnumMap()->get(enumName);
                    for (int i = 0; i < enumList->getSize(); i++)
                    {
                        if (enumList->get(i)->getName().compare(name) == 0)
                            return (const ENUM *)enumList->get(i);
                    }
                }
                throw NRuntimeException("No Enum was found");
            }
            static const ENUM * getByValue(TYPE value)
            {
                NString enumName = typeid(ENUM).name();
                if (IINEnumeration::getEnumMap()->contains(enumName))
                {
                    INList<IINEnumeration *> * enumList = IINEnumeration::getEnumMap()->get(enumName);
                    for (int i = 0; i < enumList->getSize(); i++)
                    {
                        if (((const ENUM *)enumList->get(i))->getValue() == value)
                            return (const ENUM *)enumList->get(i);
                    }
                }
                throw NRuntimeException("No Enum was found");
            }
        protected:
            INEnumeration(const NString & name, TYPE value) : IINEnumeration()
            {
                m_EnumName = new NString(typeid(ENUM).name());
                m_Name  = new NString(name);
                m_Value = value;

                if (!IINEnumeration::getEnumMap()->contains(*m_EnumName))
                    IINEnumeration::getEnumMap()->add(*m_EnumName, new NList<IINEnumeration *>());
                bool found = false;
                INList<IINEnumeration *> * enumList = IINEnumeration::getEnumMap()->get(*m_EnumName);
                for (int i = 0; i < enumList->getSize(); i++)
                    if (enumList->get(i)->compareTo(this) == 0)
                        found = true;
                if (!found)
                {
                    IINEnumeration::getEnumMap()->get(*m_EnumName)->add(this);
                }
                else
                {
                    throw NRuntimeException("Value already exists");
                }
            }
            INEnumeration(const INEnumeration<ENUM, TYPE> & other) : IINEnumeration()
            {
                m_EnumName = new NString(*other.m_EnumName);
                m_Name  = new NString(*other.m_Name);
                m_Value = other.m_Value;
            }
            virtual ~INEnumeration()
            {
                if (m_EnumName != NULL)
                    delete m_EnumName;
                if (m_Name != NULL)
                    delete m_Name;
            }
        protected:
            NString * m_EnumName;
            NString * m_Name;
            TYPE m_Value;
        public:
            virtual const NString & getName() const
            {
                return *m_Name;
            }
            virtual const NString & getEnumName() const
            {
                return *m_EnumName;
            }
            virtual const TYPE getValue() const
            {
                return m_Value;
            }
            virtual nint compareTo(const INObject * other) const
            {
                if (this == other)
                    return 0;
                try
                {
                    const ENUM * obj = dynamic_cast<const ENUM * >(other);

                    if (obj != NULL)
                    {
                        int result = 0;
                        if ((result = getEnumName().compare(obj->getEnumName())) == 0)
                        {
                            result = obj->getName().compare(getName());
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

#define DefineEnumValue(TYPE, NAME)                                                                                    \
    static const TYPE * NAME;
#define DeclareEnumValue(TYPE, NAME, VALUE)                                                                            \
    const TYPE * TYPE::NAME = new TYPE(#NAME, VALUE);

#endif //INENUM_H
