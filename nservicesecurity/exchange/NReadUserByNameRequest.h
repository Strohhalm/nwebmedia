//
// Created by strohhalm on 27.07.15.
//

#ifndef NWEBMEDIA_NREADUSERBYNAMEREQUEST_H
#define NWEBMEDIA_NREADUSERBYNAMEREQUEST_H

#include <nservice/exchange/INServiceRequest.h>
#include <nservicesecurity/exchange/NReadUserByNameParam.h>

namespace nox
{
    namespace service
    {
        namespace exchange
        {
            namespace security
            {
                struct _NReadUserByNameRequest : public _IINServiceRequest
                {
                    _NReadUserByNameParam Data;
                };

                class NReadUserByNameRequest : public INServiceRequest<_NReadUserByNameRequest>
                {
                protected:
                    NReadUserByNameParam * m_Data;
                public:
                    NReadUserByNameRequest();
                    NReadUserByNameRequest(const NServiceRequestHead & head, const NReadUserByNameParam & data);
                    NReadUserByNameRequest(const NReadUserByNameRequest & other);
                    NReadUserByNameRequest(const _NReadUserByNameRequest & from);
                    virtual ~NReadUserByNameRequest();
                    virtual NReadUserByNameParam & getData();
                    virtual void toStruct(_NReadUserByNameRequest & input);
                };
            }
        }
    }
}

#endif //NWEBMEDIA_NREADUSERBYNAMEREQUEST_H
