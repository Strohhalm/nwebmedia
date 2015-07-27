//
// Created by strohhalm on 16.07.15.
//

#ifndef NWEBMEDIA_NLOCALIZEREQUEST_H
#define NWEBMEDIA_NLOCALIZEREQUEST_H

#include <nservice/exchange/INServiceRequest.h>
#include <nserviceinfra/exchange/NLocalisationKey.h>

namespace nox
{
    namespace service
    {
        namespace exchange
        {
            namespace infra
            {
                struct _NLocalizeRequest : public _IINServiceRequest
                {
                    _NLocalisationKey Data;
                };

                class NLocalizeRequest : public INServiceRequest<_NLocalizeRequest>
                {
                protected:
                    NLocalisationKey * m_Data;
                public:
                    NLocalizeRequest();
                    NLocalizeRequest(const NServiceRequestHead & head, const NLocalisationKey & data);
                    NLocalizeRequest(const NLocalizeRequest & other);
                    NLocalizeRequest(const _NLocalizeRequest & from);
                    virtual ~NLocalizeRequest();
                    virtual NLocalisationKey & getData();
                    virtual void toStruct(_NLocalizeRequest & input);

                };
            }
        }
    }
}

#endif //NWEBMEDIA_NLOCALIZEREQUEST_H
