//
// Created by strohhalm on 24.05.15.
//

#ifndef NMAP_H
#define NMAP_H

#include "INMap.h"
#include "NList.h"

#include <boost/type_traits/has_equal_to.hpp>
#include <boost/type_traits/has_less.hpp>

namespace nox
{
    namespace collection
    {
        template<class KEY, class VALUE>
        class NOX_BASE_API NMap : public INMap<KEY, VALUE>
        {
        private:
            template<class TYPE>
            class NoXComparator
            {
            public:
                template<typename U>
                typename enable_if<is_base_of<INObject, U>::value, int>::type compare(U one, U two)
                {
                    if (one == two)
                    {
                        return 0;
                    }
                    else if (one < two)
                    {
                        return -1;
                    }
                    else
                    {
                        return 1;
                    }
                }

                template<class U>
                typename enable_if<is_base_of<NString, U>::value, int>::type compare(U one, U two)
                {
                    return one.compare(two);
                }

                template<typename U>
                typename enable_if<
                        !is_base_of<INObject, U>::value && !is_base_of<NString, U>::value, int>::type compare(U one,
                                                                                                              U two)
                {
                    return memcmp(&one, &two, sizeof(U));
                }
            };

            template<class TYPE>
            class NoXComparator<TYPE *>
            {
            public:
                template<typename U>
                typename enable_if<is_base_of<INObject, U>::value, int>::type compare(U * one, U * two)
                {
                    if (*one == *two)
                    {
                        return 0;
                    }
                    else if (*one < *two)
                    {
                        return -1;
                    }
                    else
                    {
                        return 1;
                    }
                }

                template<class U>
                typename enable_if<is_base_of<NString, U>::value, int>::type compare(U * one, U * two)
                {
                    return one->compare(two);
                }

                template<typename U>
                typename enable_if<!is_base_of<INObject, U>::value && !is_base_of<NString, U>::value, int>::type compare(U * one, U * two)
                {
                    if (one == two)
                    {
                        return 0;
                    }
                    else if (one < two)
                    {
                        return -1;
                    }
                    else
                    {
                        return 1;
                    }
                }
            };

            template<class FIRST, class SECOND>
            class NPair : public INObject
            {
            protected:
                FIRST m_First;
                SECOND m_Second;
            public:
                NPair() : INObject()
                {

                }

                NPair(FIRST key, SECOND value) : INObject()
                {
                    m_First = key;
                    m_Second = value;
                }

                NPair(const NPair<FIRST, SECOND> & other) : INObject()
                {
                    m_First = other.m_First;
                    m_Second = other.m_Second;
                }

                virtual ~NPair()
                {

                }

                virtual FIRST getFirst() const
                {
                    return m_First;
                }

                virtual void setFirst(FIRST value)
                {
                    m_First = value;
                }

                virtual SECOND getSecond() const
                {
                    return m_Second;
                }

                virtual void setSecond(SECOND value)
                {
                    m_Second = value;
                }

                virtual nint compareTo(const INObject * other) const
                {
                    try
                    {
                        const NPair<FIRST, SECOND> * obj = dynamic_cast<const NPair<FIRST, SECOND> *>(other);

                        if (obj != NULL)
                        {
                            NoXComparator<FIRST> firstComp;
                            NoXComparator<SECOND> secondComp;

                            int result = 0;
                            if ((result = firstComp.compare(getFirst(), obj->getFirst())) == 0)
                            {
                                result = secondComp.compare(getSecond(), obj->getSecond());
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

        protected:
            INList<KEY> * m_KeyList;
            INList<NPair<KEY, VALUE> *> * m_List;
            NoXComparator<KEY> * m_KeyComparator;
            NoXComparator<VALUE> * m_ValueComparator;
        public:
            NMap() : INMap<KEY, VALUE>()
            {
                m_KeyList = new NList<KEY>;
                m_List = new NList<NPair<KEY, VALUE>*>();
                m_KeyComparator = new NoXComparator<KEY>();
                m_ValueComparator = new NoXComparator<VALUE>();
            }

            NMap(const NMap & other) : INMap<KEY, VALUE>(other)
            {
                m_KeyList = new NList<KEY>;
                m_List = new NList<NPair<KEY, VALUE>*>();
                m_KeyComparator = new NoXComparator<KEY>();
                m_ValueComparator = new NoXComparator<VALUE>();

                for (int i = 0; i < other.m_List->getSize(); i++)
                {
                    add(other.m_List->get(i)->getFirst(), other.m_List->get(i)->getSecond());
                }
            }

            virtual ~NMap()
            {
                removeAll();

                if (m_List != NULL)
                    delete m_List;
                if (m_KeyList != NULL)
                    delete m_KeyList;
                if (m_KeyComparator != NULL)
                    delete m_KeyComparator;
            }

            virtual long getSize() const
            {
                return m_List->getSize();
            }

            virtual bool isEmpty() const
            {
                return getSize() == 0;
            }

            virtual void add(KEY key, VALUE value)
            {
                if (!contains(key))
                {
                    m_List->add(new NPair<KEY, VALUE>(key, value));
                    m_KeyList->add(key);
                }
            }

            virtual void remove(KEY key)
            {
                if (contains(key))
                {
                    for (int i = 0; i < m_List->getSize(); i++)
                    {
                        if (m_KeyComparator->compare(m_List->get(i)->getFirst(), key) == 0)
                        {
                            m_List->removeAt(i);
                            m_KeyList->removeAt(i);
                            break;
                        }
                    }
                }
            }

            virtual void removeAll()
            {
                if (getSize() > 0)
                {
                    for (int i = 0; i < m_List->getSize(); i++)
                    {
                        if (m_List->get(i) != NULL)
                            delete m_List->get(i);
                    }
                    m_List->clear();
                    m_KeyList->clear();
                }
            }

            virtual bool contains(KEY key) const
            {
                if (getSize() > 0)
                {
                    for (int i = 0; i < getSize(); i++)
                    {
                        if (m_KeyComparator->compare(key, m_List->get(i)->getFirst()) == 0)
                            return true;
                    }
                }
                return false;
            }

            virtual VALUE get(KEY key) const
            {
                if (getSize() > 0)
                {
                    for (int i = 0; i < getSize(); i++)
                    {
                        if (m_KeyComparator->compare(key, m_List->get(i)->getFirst()) == 0)
                            return m_List->get(i)->getSecond();
                    }
                }
                else
                {
                    throw NRuntimeException("No value found for key");
                }
            }

            virtual VALUE operator[](KEY key) const
            {
                return get(key);
            }

            virtual INList<KEY> * getKeyList()
            {
                return m_KeyList;
            }

            virtual nint compareTo(const INObject * other) const
            {
                try
                {
                    const NMap<KEY, VALUE> * obj = dynamic_cast<const NMap<KEY, VALUE> *>(other);

                    if (obj != NULL)
                    {
                        if (obj == this)
                            return 0;

                        long result = 0;
                        if ((result = getSize() - obj->getSize()) == 0)
                        {
                            for (int i = 0; i < getSize(); i++)
                            {
                                if (obj->contains(m_List->get(i)->getFirst()))
                                {
                                    if ((result = m_ValueComparator->compare(m_List->get(i)->getSecond(),
                                                                             obj->get(m_List->get(i)->getFirst()))) !=
                                            0)
                                        break;
                                }
                            }
                        }
                        return (int) result;
                    }
                    else
                    {
                        return -1;
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

#endif //NMAP_H
