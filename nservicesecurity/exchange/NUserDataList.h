//
// Created by strohhalm on 27.07.15.
//

#ifndef NWEBMEDIA_NUSERDATALIST_H
#define NWEBMEDIA_NUSERDATALIST_H

#include <nbase/collection/NList.h>
#include <nservicesecurity/exchange/NUserData.h>

using namespace nox::collection;

namespace nox
{
    namespace service
    {
        namespace exchange
        {
            namespace security
            {
                struct _NUserDataList
                {
                    _NUserData Users[50];
                    nlong Count;
                };

                class NUserDataList
                {
                protected:
                    NList<NUserData *> * m_Users;
                public:
                    NUserDataList();
                    NUserDataList(const NList<NUserData *> & users);
                    NUserDataList(const NUserDataList & other);
                    NUserDataList(const _NUserDataList & from);
                    virtual ~NUserDataList();
                    virtual NList<NUserData *> & getUsers();
                    virtual void toStruct(_NUserDataList & input);
                };
            }
        }
    }
}


#endif //NWEBMEDIA_NUSERDATALIST_H
