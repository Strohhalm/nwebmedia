//
// Created by strohhalm on 16.07.15.
//

#include "NLocalisationList.h"

namespace nox
{
    namespace service
    {
        namespace exchange
        {
            namespace infra
            {
                NLocalisationList::NLocalisationList()
                {
                    m_Entries = new NList<NLocalisationEntry *>();
                }

                NLocalisationList::NLocalisationList(const NList<NLocalisationEntry *> & entries)
                {
                    m_Entries = new NList<NLocalisationEntry *>();
                    for (nlong i = 0; i < entries.getSize(); i++)
                        m_Entries->add(entries.get(i));
                }

                NLocalisationList::NLocalisationList(const NLocalisationList & other)
                {
                    m_Entries = new NList<NLocalisationEntry *>();
                    for (nlong i = 0; i < other.m_Entries->getSize(); i++)
                        m_Entries->add(new NLocalisationEntry(*other.m_Entries->get(i)));

                }

                NLocalisationList::NLocalisationList(const _NLocalisationList & from)
                {
                    m_Entries = new NList<NLocalisationEntry *>();
                    for (nlong i = 0; i < from.Count; i++)
                        m_Entries->add(new NLocalisationEntry(from.Entries[i]));
                }

                NLocalisationList::~NLocalisationList()
                {
                    if (m_Entries != NULL)
                    {
                        for (nlong i = 0; i < m_Entries->getSize(); i++)
                        {
                            if (m_Entries->get(i) != NULL)
                                delete m_Entries->get(i);
                        }
                        delete m_Entries;
                    }
                }

                NList<NLocalisationEntry *> & NLocalisationList::getEntries()
                {
                    return *m_Entries;
                }

                void NLocalisationList::toStruct(_NLocalisationList & input)
                {
                    memset(&input, 0, sizeof(_NLocalisationList));

                    input.Count = m_Entries->getSize();

                    if (input.Count > 100)
                        input.Count = 100;

                    for (nlong i = 0; i < input.Count; i++)
                        m_Entries->get(i)->toStruct(input.Entries[i]);
                }
            }
        }
    }
}