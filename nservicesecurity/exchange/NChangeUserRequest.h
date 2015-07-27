//
// Created by strohhalm on 25.07.15.
//

#ifndef NWEBMEDIA_NCHANGEUSERREQUEST_H
#define NWEBMEDIA_NCHANGEUSERREQUEST_H

#include <nservice/exchange/INServiceRequest.h>
#include <nservicesecurity/exchange/NUserData.h>

namespace nox
{
    namespace service
    {
        namespace exchange
        {
            namespace security
            {
                struct _NChangeUserRequest : public _IINServiceRequest
                {
                    _NUserData Data;
                };

                class NChangeUserRequest : public INServiceRequest<_NChangeUserRequest>
                {
                protected:
                    NUserData * m_Data;
                public:
                    NChangeUserRequest();
                    NChangeUserRequest(const NServiceRequestHead & head, const NUserData & data);
                    NChangeUserRequest(const NChangeUserRequest & other);
                    NChangeUserRequest(const _NChangeUserRequest & from);
                    virtual ~NChangeUserRequest();
                    virtual NUserData & getData();
                    virtual void toStruct(_NChangeUserRequest & input);
                };
            }
        }
    }
}


#endif //NWEBMEDIA_NCHANGEUSERREQUEST_H
