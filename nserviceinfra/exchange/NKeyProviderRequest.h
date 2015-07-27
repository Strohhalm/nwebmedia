//
// Created by strohhalm on 24.07.15.
//

#ifndef NWEBMEDIA_NKEYPROVIDERREQUEST_H
#define NWEBMEDIA_NKEYPROVIDERREQUEST_H

#include <nservice/exchange/INServiceRequest.h>
#include <nserviceinfra/exchange/NKeyProviderKeyReference.h>

namespace nox
{
    namespace service
    {
        namespace exchange
        {
            namespace infra
            {
                struct _NKeyProviderRequest : public _IINServiceRequest
                {
                    _NKeyProviderKeyReference Data;
                };

                class NKeyProviderRequest : public INServiceRequest<_NKeyProviderRequest>
                {
                protected:
                    NKeyProviderKeyReference * m_Data;
                public:
                    NKeyProviderRequest();
                    NKeyProviderRequest(const NServiceRequestHead & head, const NKeyProviderKeyReference & data);
                    NKeyProviderRequest(const NKeyProviderRequest & other);
                    NKeyProviderRequest(const _NKeyProviderRequest & from);
                    virtual ~NKeyProviderRequest();
                    virtual NKeyProviderKeyReference & getData();
                    virtual void toStruct(_NKeyProviderRequest & input);
                };
            }
        }
    }
}


#endif //NWEBMEDIA_NKEYPROVIDERREQUEST_H
