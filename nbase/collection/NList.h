//
// Created by strohhalm on 27.05.15.
//

#ifndef NLIST_H
#define NLIST_H

#include "INList.h"
#include "../NIndexOutOfBoundsException.h"

namespace nox
{
    namespace collection
    {
        template<class TYPE>
        class NOX_BASE_API NList : public INList<TYPE>
        {
        private:
            template<class COMP_TYPE>
            class NoXComparator
            {
            public:
                nint compare(COMP_TYPE value1, COMP_TYPE value2)
                {
                    if (value1 == value2)
                        return 0;
                    if (value1 > value2)
                        return 1;
                    return -1;
                }
            };
            template<class COMP_TYPE>
            class NoXComparator <COMP_TYPE *>
            {
            public:
                template<typename T>
                typename enable_if<is_base_of<INObject, T>::value, nint>::type compare(T * value1, T * value2)
                {
                    if (*value1 == *value2)
                        return 0;
                    if (*value1 > *value2)
                        return 1;
                    return -1;
                }
                template<typename T>
                typename enable_if<!is_base_of<INObject, T>::value, nint>::type compare(T * value1, T * value2)
                {
                    if (value1 == value2)
                        return 0;
                    if (value1 > value2)
                        return 1;
                    return -1;
                }
            };
        protected:
            std::vector<TYPE> * m_List;
        public:
            NList() : INList<TYPE>()
            {
                m_List = new std::vector<TYPE>();
            }

            NList(const NList<TYPE> & values) : INList<TYPE>(values)
            {
                m_List = new std::vector<TYPE>(*values.m_List);
            }

            virtual ~NList()
            {
                clear();
                if (m_List != NULL)
                    delete m_List;
            }

            virtual void add(TYPE value)
            {
                m_List->push_back(value);
            }

            virtual void insert(TYPE value, nlong index)
            {
                if (index >= 0 && index <= m_List->size())
                {
                    m_List->insert(m_List->begin() + index, value);
                }
                else
                {
                    throw NIndexOutOfBoundsException();
                }
            }

            virtual void remove(TYPE value)
            {
                NoXComparator<TYPE> comparator;
                typename std::vector<TYPE>::iterator iter = m_List->begin();
                typename std::vector<TYPE>::iterator end;
                while (iter != end)
                {
                    if (comparator.compare(*iter, value) == 0)
                    {
                        m_List->erase(iter);
                        break;
                    }
                    iter++;
                }
            }

            virtual void removeAt(nlong index)
            {
                if (index >= 0 && index < m_List->size())
                {
                    m_List->erase(m_List->begin() + index);
                }
                else
                {
                    throw NIndexOutOfBoundsException();
                }
            }

            virtual void clear()
            {
                m_List->clear();
            }

            virtual TYPE get(nlong index) const
            {
                if (index >= 0 && index < m_List->size())
                {
                    return m_List->at(index);
                }
                else
                {
                    throw NIndexOutOfBoundsException("Index out of bounds");
                }
            }

            virtual TYPE operator[] (nlong index) const
            {
                return get(index);
            }

            virtual bool contains(TYPE value) const
            {
                return indexOf(value) != -1;
            }

            virtual long indexOf(TYPE value)  const
            {
                NoXComparator<TYPE> comparator;
                for (int i = 0; i < m_List->size(); i++)
                {
                    if (comparator.compare(value, get(i)) == 0)
                    {
                        return i;
                    }
                }
                return -1;
            }

            virtual nlong getSize() const
            {
                return m_List->size();
            }

            virtual nint compareTo(const INObject * other) const
            {
                try
                {
                    const NList<TYPE> * obj = dynamic_cast<const NList<TYPE> *>(other);

                    if (obj != NULL)
                    {
                        if (obj == this)
                            return 0;

                        if (obj->getSize() == getSize())
                        {
                            NoXComparator<TYPE> comparator;

                            nint result = 0;
                            for (nlong i = 0; i < getSize(); i++)
                            {
                                if ((result = comparator.compare(get(i), obj->get(i))) != 0)
                                {
                                    break;
                                }
                            }
                            return result;
                        }
                        else
                        {
                            return (nint)(getSize() - obj->getSize());
                        }
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

#endif //NLIST_H
