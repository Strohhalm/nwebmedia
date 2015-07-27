//
// Created by strohhalm on 16.07.15.
//

#ifndef NWEBMEDIA_NCHECKLOGINCREDENTIALSRESPONSE_H
#define NWEBMEDIA_NCHECKLOGINCREDENTIALSRESPONSE_H

#include <nservice/exchange/INServiceResponse.h>
#include <nservicesecurity/exchange/NLoginCredentialsOk.h>

namespace nox
{
    namespace service
    {
        namespace exchange
        {
            namespace security
            {
                struct _NCheckLoginCredentialsResponse : public _IINServiceResponse
                {
                    _NLoginCredentialsOk Data;
                };

                class NCheckLoginCredentialsResponse : public INServiceResponse<_NCheckLoginCredentialsResponse>
                {
                protected:
                    NLoginCredentialsOk * m_Data;
                public:
                    NCheckLoginCredentialsResponse();
                    NCheckLoginCredentialsResponse(const NServiceResponseHead & head, const NLoginCredentialsOk & data);
                    NCheckLoginCredentialsResponse(const NCheckLoginCredentialsResponse & other);
                    NCheckLoginCredentialsResponse(const _NCheckLoginCredentialsResponse & from);
                    virtual ~NCheckLoginCredentialsResponse();
                    virtual NLoginCredentialsOk & getData();
                    virtual void toStruct(_NCheckLoginCredentialsResponse & input);
                };
            }
        }
    }
}

#endif //NWEBMEDIA_NCHECKLOGINCREDENTIALSRESPONSE_H
