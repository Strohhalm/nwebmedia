//
// Created by strohhalm on 16.07.15.
//

#ifndef NWEBMEDIA_IINSERVICERESPONSE_H
#define NWEBMEDIA_IINSERVICERESPONSE_H

#include <nservice/exchange/NServiceResponseHead.h>

namespace nox
{
    namespace service
    {
        namespace exchange
        {
            struct _IINServiceResponse
            {
                _NServiceResponseHead Head;
            };

            class IINServiceResponse
            {
            protected:
                NServiceResponseHead * m_Head;
            public:
                IINServiceResponse();
                IINServiceResponse(const NServiceResponseHead & head);
                IINServiceResponse(const IINServiceResponse & other);
                IINServiceResponse(const _IINServiceResponse & from);
                virtual ~IINServiceResponse();
                virtual NServiceResponseHead & getHead();
            };
        }
    }
}


#endif //NWEBMEDIA_IINSERVICERESPONSE_H
