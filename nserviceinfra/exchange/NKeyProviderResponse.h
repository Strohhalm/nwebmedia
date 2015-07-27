//
// Created by strohhalm on 24.07.15.
//

#ifndef NWEBMEDIA_NKEYPROVIDERRESPONSE_H
#define NWEBMEDIA_NKEYPROVIDERRESPONSE_H

#include <nservice/exchange/INServiceResponse.h>
#include <nserviceinfra/exchange/NKeyProviderKey.h>

namespace nox
{
    namespace service
    {
        namespace exchange
        {
            namespace infra
            {
                struct _NKeyProviderResponse : public _IINServiceResponse
                {
                    _NKeyProviderKey Data;
                };

                class NKeyProviderResponse : public INServiceResponse<_NKeyProviderResponse>
                {
                protected:
                    NKeyProviderKey * m_Data;
                public:
                    NKeyProviderResponse();
                    NKeyProviderResponse(const NServiceResponseHead & head, const NKeyProviderKey & data);
                    NKeyProviderResponse(const NKeyProviderResponse & other);
                    NKeyProviderResponse(const _NKeyProviderResponse & from);
                    virtual ~NKeyProviderResponse();
                    virtual NKeyProviderKey & getData();
                    virtual void toStruct(_NKeyProviderResponse & input);
                };
            }
        }
    }
}

#endif //NWEBMEDIA_NKEYPROVIDERRESPONSE_H
