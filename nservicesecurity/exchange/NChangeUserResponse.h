//
// Created by strohhalm on 25.07.15.
//

#ifndef NWEBMEDIA_NCHANGEUSERRESPONSE_H
#define NWEBMEDIA_NCHANGEUSERRESPONSE_H

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
                struct _NChangeUserResponse : public _IINServiceResponse
                {
                    _NUserData Data;
                };

                class NChangeUserResponse : public INServiceResponse<_NChangeUserResponse>
                {
                protected:
                    NUserData * m_Data;
                public:
                    NChangeUserResponse();
                    NChangeUserResponse(const NServiceResponseHead & head, const NUserData & data);
                    NChangeUserResponse(const NChangeUserResponse & other);
                    NChangeUserResponse(const _NChangeUserResponse & from);
                    virtual ~NChangeUserResponse();
                    virtual NUserData & getData();
                    virtual void toStruct(_NChangeUserResponse & input);
                };
            }
        }
    }
}


#endif //NWEBMEDIA_NCHANGEUSERRESPONSE_H
