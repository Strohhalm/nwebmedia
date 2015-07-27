//
// Created by strohhalm on 16.07.15.
//

#ifndef NWEBMEDIA_NLOCALISATIONRESPONSE_H
#define NWEBMEDIA_NLOCALISATIONRESPONSE_H

#include <nservice/exchange/INServiceResponse.h>
#include <nserviceinfra/exchange/NLocalisationList.h>

namespace nox
{
    namespace service
    {
        namespace exchange
        {
            namespace infra
            {
                struct _NLocalisationResponse : public _IINServiceResponse
                {
                    _NLocalisationList Data;
                };

                class NLocalisationResponse : public INServiceResponse<_NLocalisationResponse>
                {
                protected:
                    NLocalisationList * m_Data;
                public:
                    NLocalisationResponse();
                    NLocalisationResponse(const NServiceResponseHead & head, const NLocalisationList & data);
                    NLocalisationResponse(const NLocalisationResponse & other);
                    NLocalisationResponse(const _NLocalisationResponse & from);
                    virtual ~NLocalisationResponse();
                    virtual NLocalisationList & getData();
                    virtual void toStruct(_NLocalisationResponse & input);
                };
            }
        }
    }
}

#endif //NWEBMEDIA_NLOCALISATIONRESPONSE_H
