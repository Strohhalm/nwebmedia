//
// Created by strohhalm on 16.07.15.
//

#ifndef NWEBMEDIA_NLOGINCREDENTIALSOK_H
#define NWEBMEDIA_NLOGINCREDENTIALSOK_H

#include <nbase/NBaseType.h>

namespace nox
{
    namespace service
    {
        namespace exchange
        {
            namespace security
            {
                struct _NLoginCredentialsOk
                {
                    nint UserId;
                    nbool Ok;
                };

                class NLoginCredentialsOk
                {
                protected:
                    NInteger * m_UserId;
                    NBool * m_Ok;
                public:
                    NLoginCredentialsOk();
                    NLoginCredentialsOk(const NInteger & userId, const NBool & ok);
                    NLoginCredentialsOk(const NLoginCredentialsOk & other);
                    NLoginCredentialsOk(const _NLoginCredentialsOk & from);
                    virtual ~NLoginCredentialsOk();
                    virtual void setUserId(const NInteger & userId);
                    virtual const NInteger & getUserId();
                    virtual void setOk(const NBool & ok);
                    virtual const NBool & isOk();
                    virtual void toStruct(_NLoginCredentialsOk & input);
                };
            }
        }
    }
}

#endif //NWEBMEDIA_NLOGINCREDENTIALSOK_H
