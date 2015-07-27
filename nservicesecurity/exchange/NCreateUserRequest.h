//
// Created by strohhalm on 25.07.15.
//

#ifndef NWEBMEDIA_NCREATEUSERREQUEST_H
#define NWEBMEDIA_NCREATEUSERREQUEST_H

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
                struct _NCreateUserRequest : public _IINServiceRequest
                {
                    _NUserData Data;
                };

                class NCreateUserRequest : public INServiceRequest<_NCreateUserRequest>
                {
                protected:
                    NUserData * m_Data;
                public:
                    NCreateUserRequest();
                    NCreateUserRequest(const NServiceRequestHead & head, const NUserData & data);
                    NCreateUserRequest(const NCreateUserRequest & other);
                    NCreateUserRequest(const _NCreateUserRequest & from);
                    virtual ~NCreateUserRequest();
                    virtual NUserData & getData();
                    virtual void toStruct(_NCreateUserRequest & input);
                };
            }
        }
    }
}

#endif //NWEBMEDIA_NCREATEUSERREQUEST_H
