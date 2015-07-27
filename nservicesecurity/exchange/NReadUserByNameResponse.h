//
// Created by strohhalm on 27.07.15.
//

#ifndef NWEBMEDIA_NREADUSERBYNAMERESPONSE_H
#define NWEBMEDIA_NREADUSERBYNAMERESPONSE_H

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
                struct _NReadUserByNameResponse : public _IINServiceResponse
                {
                    _NUserData Data;
                };

                class NReadUserByNameResponse : public INServiceResponse<_NReadUserByNameResponse>
                {
                protected:
                    NUserData * m_Data;
                public:
                    NReadUserByNameResponse();
                    NReadUserByNameResponse(const NServiceResponseHead & head, const NUserData & data);
                    NReadUserByNameResponse(const NReadUserByNameResponse & other);
                    NReadUserByNameResponse(const _NReadUserByNameResponse & from);
                    virtual ~NReadUserByNameResponse();
                    virtual NUserData & getData();
                    virtual void toStruct(_NReadUserByNameResponse & input);
                };
            }
        }
    }
}


#endif //NWEBMEDIA_NREADUSERBYNAMERESPONSE_H
