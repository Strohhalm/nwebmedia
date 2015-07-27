//
// Created by strohhalm on 25.07.15.
//

#ifndef NWEBMEDIA_NCREATEUSERRESPONSE_H
#define NWEBMEDIA_NCREATEUSERRESPONSE_H

#include <nservice/exchange/INServiceResponse.h>
#include <nservicesecurity/exchange/NUserData.h>

namespace nox
{
    namespace service
    {
        namespace exchange
        {
            namespace security
            {
                struct _NCreateUserResponse : public _IINServiceResponse
                {
                    _NUserData Data;
                };

                class NCreateUserResponse : public INServiceResponse<_NCreateUserResponse>
                {
                protected:
                    NUserData * m_Data;
                public:
                    NCreateUserResponse();
                    NCreateUserResponse(const NServiceResponseHead & head, const NUserData & data);
                    NCreateUserResponse(const NCreateUserResponse & other);
                    NCreateUserResponse(const _NCreateUserResponse & from);
                    virtual ~NCreateUserResponse();
                    virtual NUserData & getData();
                    virtual void toStruct(_NCreateUserResponse & input);
                };
            }
        }
    }
}

#endif //NWEBMEDIA_NCREATEUSERRESPONSE_H
