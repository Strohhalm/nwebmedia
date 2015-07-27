//
// Created by strohhalm on 16.07.15.
//

#ifndef NWEBMEDIA_NLOCALISATIONLIST_H
#define NWEBMEDIA_NLOCALISATIONLIST_H

#include <nbase/collection/NList.h>
#include <nserviceinfra/exchange/NLocalisationEntry.h>

using namespace nox::collection;

namespace nox
{
    namespace service
    {
        namespace exchange
        {
            namespace infra
            {
                struct _NLocalisationList
                {
                    _NLocalisationEntry Entries[100];
                    nlong Count;
                };

                class NLocalisationList
                {
                protected:
                    NList<NLocalisationEntry *> * m_Entries;
                public:
                    NLocalisationList();
                    NLocalisationList(const NList<NLocalisationEntry *> & entries);
                    NLocalisationList(const NLocalisationList & other);
                    NLocalisationList(const _NLocalisationList & from);
                    virtual ~NLocalisationList();
                    virtual NList<NLocalisationEntry *> & getEntries();
                    virtual void toStruct(_NLocalisationList & input);
                };
            }
        }
    }
}

#endif //NWEBMEDIA_NLOCALISATIONLIST_H
