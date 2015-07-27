//
// Created by strohhalm on 16.07.15.
//

#ifndef NWEBMEDIA_IINSERVICEREQUEST_H
#define NWEBMEDIA_IINSERVICEREQUEST_H

#include <nservice/exchange/NServiceRequestHead.h>

namespace nox
{
    namespace service
    {
        namespace exchange
        {
            struct _IINServiceRequest
            {
                _NServiceRequestHead Head;
            };

            class IINServiceRequest
            {
            protected:
                NServiceRequestHead * m_Head;
            public:
                IINServiceRequest();
                IINServiceRequest(const NServiceRequestHead & head);
                IINServiceRequest(const IINServiceRequest & other);
                IINServiceRequest(const _IINServiceRequest & from);
                virtual ~IINServiceRequest();
                virtual NServiceRequestHead & getHead();
            };
        }
    }
}


#endif //NWEBMEDIA_IINSERVICEREQUEST_H
