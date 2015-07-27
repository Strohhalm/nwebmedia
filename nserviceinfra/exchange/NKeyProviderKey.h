//
// Created by strohhalm on 24.07.15.
//

#ifndef NWEBMEDIA_NKEYPROVIDERKEY_H
#define NWEBMEDIA_NKEYPROVIDERKEY_H

#include <nbase/NBaseType.h>

namespace nox
{
    namespace service
    {
        namespace exchange
        {
            namespace infra
            {
                struct _NKeyProviderKey
                {
                    nlong Key;
                };

                class NKeyProviderKey
                {
                protected:
                    NLong * m_Key;
                public:
                    NKeyProviderKey();
                    NKeyProviderKey(const NLong & key);
                    NKeyProviderKey(const NKeyProviderKey & other);
                    NKeyProviderKey(const _NKeyProviderKey & from);
                    virtual ~NKeyProviderKey();
                    virtual void setKey(const NLong & key);
                    virtual const NLong & getKey();
                    virtual void toStruct(_NKeyProviderKey & input);
                };
            }
        }
    }
}


#endif //NWEBMEDIA_NKEYPROVIDERKEY_H
