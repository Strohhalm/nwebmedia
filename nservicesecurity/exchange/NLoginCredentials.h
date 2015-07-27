//
// Created by strohhalm on 16.07.15.
//

#ifndef NWEBMEDIA_NLOGINCREDENTIALS_H
#define NWEBMEDIA_NLOGINCREDENTIALS_H

#include <nbase/NBase.h>

namespace nox
{
    namespace service
    {
        namespace exchange
        {
            namespace security
            {
                struct _NLoginCredentials
                {
                    nchar Username[51];
                    nchar Password[51];
                };

                class NLoginCredentials
                {
                protected:
                    NString * m_Username;
                    NString * m_Password;
                public:
                    NLoginCredentials();
                    NLoginCredentials(const NString & username, const NString & password);
                    NLoginCredentials(const NLoginCredentials & other);
                    NLoginCredentials(const _NLoginCredentials & from);
                    virtual ~NLoginCredentials();
                    virtual void setUsername(const NString & username);
                    virtual const NString & getUsername();
                    virtual void setPassword(const NString & password);
                    virtual const NString & getPassword();
                    virtual void toStruct(_NLoginCredentials & input);
                };
            }
        }
    }
}
#endif //NWEBMEDIA_NLOGINCREDENTIALS_H
