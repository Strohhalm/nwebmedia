//
// Created by strohhalm on 16.07.15.
//

#ifndef NWEBMEDIA_NCHECKLOGINCREDENTIALSREQUEST_H
#define NWEBMEDIA_NCHECKLOGINCREDENTIALSREQUEST_H

#include <nservice/exchange/INServiceRequest.h>
#include <nservicesecurity/exchange/NLoginCredentials.h>

namespace nox
{
    namespace service
    {
        namespace exchange
        {
            namespace security
            {
                struct _NCheckLoginCredentialsRequest : public _IINServiceRequest
                {
                    _NLoginCredentials Data;
                };

                class NCheckLoginCredentialsRequest : public INServiceRequest<_NCheckLoginCredentialsRequest>
                {
                protected:
                    NLoginCredentials * m_Data;
                public:
                    NCheckLoginCredentialsRequest();
                    NCheckLoginCredentialsRequest(const NServiceRequestHead & head, const NLoginCredentials & data);
                    NCheckLoginCredentialsRequest(const NCheckLoginCredentialsRequest & other);
                    NCheckLoginCredentialsRequest(const _NCheckLoginCredentialsRequest & from);
                    virtual ~NCheckLoginCredentialsRequest();
                    virtual NLoginCredentials & getData();
                    virtual void toStruct(_NCheckLoginCredentialsRequest & input);
                };
            }
        }
    }
}

#endif //NWEBMEDIA_NCHECKLOGINCREDENTIALSREQUEST_H
