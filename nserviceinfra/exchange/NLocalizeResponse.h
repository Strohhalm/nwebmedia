//
// Created by strohhalm on 16.07.15.
//

#ifndef NWEBMEDIA_NLOCALIZERESPONSE_H
#define NWEBMEDIA_NLOCALIZERESPONSE_H

#include <nservice/exchange/INServiceResponse.h>
#include <nserviceinfra/exchange/NLocalisationValue.h>

namespace nox
{
    namespace service
    {
        namespace exchange
        {
            namespace infra
            {
                struct _NLocalizeResponse : public _IINServiceResponse
                {
                    _NLocalisationValue Data;
                };

                class NLocalizeResponse : public INServiceResponse<_NLocalizeResponse>
                {
                protected:
                    NLocalisationValue * m_Data;
                public:
                    NLocalizeResponse();
                    NLocalizeResponse(const NServiceResponseHead & head, const NLocalisationValue data);
                    NLocalizeResponse(const NLocalizeResponse & other);
                    NLocalizeResponse(const _NLocalizeResponse & from);
                    virtual ~NLocalizeResponse();
                    virtual NLocalisationValue & getData();
                    virtual void toStruct(_NLocalizeResponse & input);
                };
            }
        }
    }
}

#endif //NWEBMEDIA_NLOCALIZERESPONSE_H
