//
// Created by strohhalm on 16.07.15.
//

#ifndef NWEBMEDIA_INSERVICERESPONSE_H
#define NWEBMEDIA_INSERVICERESPONSE_H

#include <nbase/NAssert.h>
#include <nservice/exchange/IINServiceResponse.h>

namespace nox
{
    namespace service
    {
        namespace exchange
        {
            template<class RESPONSESTRUCT>
            class INServiceResponse : public IINServiceResponse
            {
            protected:
                NStaticAssertBaseOf(_IINServiceResponse, RESPONSESTRUCT)
            public:
                typedef RESPONSESTRUCT structType;
            public:
                INServiceResponse() : IINServiceResponse()
                {
                }

                INServiceResponse(const NServiceResponseHead & head) : IINServiceResponse(head)
                {
                }

                INServiceResponse(const INServiceResponse<RESPONSESTRUCT> & other) : IINServiceResponse(other)
                {
                }

                INServiceResponse(const RESPONSESTRUCT & from) : IINServiceResponse(from)
                {
                }

                virtual ~INServiceResponse()
                {
                }

                virtual void toStruct(RESPONSESTRUCT & input) = 0;
            };
        }
    }
}


#endif //NWEBMEDIA_INSERVICERESPONSE_H
