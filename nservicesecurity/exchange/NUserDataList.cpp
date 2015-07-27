//
// Created by strohhalm on 27.07.15.
//

#include "NUserDataList.h"

namespace nox
{
    namespace service
    {
        namespace exchange
        {
            namespace security
            {
                NUserDataList::NUserDataList()
                {
                    m_Users = new NList<NUserData *>();
                }

                NUserDataList::NUserDataList(const NList<NUserData *> & users)
                {
                    m_Users = new NList<NUserData *>();
                    for (nlong i = 0; i < users.getSize(); i++)
                        m_Users->add(new NUserData(*users.get(i)));
                }

                NUserDataList::NUserDataList(const NUserDataList & other)
                {
                    m_Users = new NList<NUserData *>();
                    for (nlong i = 0; i < other.m_Users->getSize(); i++)
                        m_Users->add(new NUserData(*other.m_Users->get(i)));
                }

                NUserDataList::NUserDataList(const _NUserDataList & from)
                {
                    m_Users = new NList<NUserData *>();
                    for (nlong i = 0; i < from.Count; i++)
                        m_Users->add(new NUserData(from.Users[i]));
                }

                NUserDataList::~NUserDataList()
                {
                    if (m_Users != NULL)
                    {
                        for (nlong i = 0; i < m_Users->getSize(); i++)
                        {
                            if (m_Users->get(i) != NULL)
                                delete m_Users->get(i);
                        }
                        delete m_Users;
                    }
                }

                NList<NUserData *> & NUserDataList::getUsers()
                {
                    return *m_Users;
                }

                void NUserDataList::toStruct(_NUserDataList & input)
                {
                    memset(&input, 0, sizeof(_NUserDataList));

                    input.Count = m_Users->getSize();
                    if (input.Count > 50)
                        input.Count = 50;
                    for (nlong i = 0; i < input.Count; i++)
                        m_Users->get(i)->toStruct(input.Users[i]);
                }
            }
        }
    }
}