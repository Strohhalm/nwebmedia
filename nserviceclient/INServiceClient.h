//
// Created by strohhalm on 27.06.15.
//

#ifndef NWEBMEDIA_INSERVICECLIENT_H
#define NWEBMEDIA_INSERVICECLIENT_H

#include <nbase/NAssert.h>
#include <nbase/NRuntimeException.h>
#include <nbase/network/IINClientSocket.h>
#include <nservice/exchange/INServiceExchange.h>
#include <nserviceclient/IINServiceClient.h>

using namespace nox::network;
using namespace nox::service::exchange;

namespace nox
{
    namespace service
    {
        namespace client
        {
            class INServiceClient : public IINServiceClient
            {
            protected:
                IINClientSocket * m_Socket;
            public:
                INServiceClient(IINClientSocket * socket);
                virtual ~INServiceClient();
            protected:
                template<class INPUT, class OUTPUT>
                OUTPUT * call(INPUT * request)
                {
                    NStaticAssertBaseOf(IINServiceRequest, INPUT);
                    NStaticAssertBaseOf(IINServiceResponse, OUTPUT);

                    NAssertNull(request)

                    typename INPUT::structType _request;
                    typename OUTPUT::structType _response;

                    request->toStruct(_request);

                    boost::system::error_code errCode;
                    try
                    {
                        m_Socket->connect();
                        m_Socket->send(&_request, sizeof(_request));
                        m_Socket->receive(&_response, sizeof(_response));
                        m_Socket->disconnect();
                    }
                    catch (...)
                    {
                        throw;
                    }
                    return new OUTPUT(_response);
                }
            };
        }
    }
}

#endif //NWEBMEDIA_INSERVICECLIENT_H
