//
// Created by strohhalm on 16.07.15.
//

#ifndef NWEBMEDIA_INSERVICEREQUEST_H
#define NWEBMEDIA_INSERVICEREQUEST_H

#include <nbase/NAssert.h>
#include <nservice/exchange/IINServiceRequest.h>

namespace nox
{
    namespace service
    {
        namespace exchange
        {
            template<class REQUESTSTRUCT>
            class INServiceRequest : public IINServiceRequest
            {
            protected:
                NStaticAssertBaseOf(_IINServiceRequest, REQUESTSTRUCT)
            public:
                typedef REQUESTSTRUCT structType;
            public:
                INServiceRequest()
                {
                }

                INServiceRequest(const NServiceRequestHead & head) : IINServiceRequest(head)
                {
                }

                INServiceRequest(const INServiceRequest<REQUESTSTRUCT> & other) : IINServiceRequest(other)
                {
                }

                INServiceRequest(const REQUESTSTRUCT & from) : IINServiceRequest(from)
                {
                }

                virtual ~INServiceRequest()
                {
                }

                virtual void toStruct(REQUESTSTRUCT & input) = 0;
            };
        }
    }
}

#endif //NWEBMEDIA_INSERVICEREQUEST_H
