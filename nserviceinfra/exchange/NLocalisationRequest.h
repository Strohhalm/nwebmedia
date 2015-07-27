//
// Created by strohhalm on 16.07.15.
//

#ifndef NWEBMEDIA_NLOCALISATIONREQUEST_H
#define NWEBMEDIA_NLOCALISATIONREQUEST_H

#include <nservice/exchange/INServiceRequest.h>
#include <nserviceinfra/exchange/NLocalisationPortion.h>

namespace nox
{
    namespace service
    {
        namespace exchange
        {
            namespace infra
            {
                struct _NLocalisationRequest : public _IINServiceRequest
                {
                    _NLocalisationPortion Portion;
                };

                class NLocalisationRequest : public INServiceRequest<_NLocalisationRequest>
                {
                protected:
                    NLocalisationPortion * m_Portion;
                public:
                    NLocalisationRequest();
                    NLocalisationRequest(const NServiceRequestHead & head, const NLocalisationPortion & portion);
                    NLocalisationRequest(const NLocalisationRequest & other);
                    NLocalisationRequest(const _NLocalisationRequest & from);
                    virtual ~NLocalisationRequest();
                    virtual NLocalisationPortion & getPortion();
                    virtual void toStruct(_NLocalisationRequest & input);
                };
            }
        }
    }
}

#endif //NWEBMEDIA_NLOCALISATIONREQUEST_H
