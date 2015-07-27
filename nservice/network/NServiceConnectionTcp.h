//
// Created by strohhalm on 19.06.15.
//

#ifndef NSERVICECONNECTIONTCP_H
#define NSERVICECONNECTIONTCP_H

#include <nbase/NNullPointerException.h>
#include <nbase/network/INConnectionTcp.h>
#include <nservice/IINService.h>

using namespace nox::network;

namespace nox
{
    namespace service
    {
        namespace network
        {
            class NServiceConnectionTcp : public INConnectionTcp
            {
            protected:
                IINService * m_Service;
            public:
                NServiceConnectionTcp(IINService * serivce, boost::asio::ip::tcp::socket * socket) : INConnectionTcp(
                        socket)
                {
                    m_Service = serivce;
                }

                virtual ~NServiceConnectionTcp()
                {
                }

                virtual void run()
                {
                    _IINServiceResponse * response = NULL;

                    boost::system::error_code errCode;
                    try
                    {
                        while (((_IINServiceRequest *)getBuffer().c_array())->Head.Control.Size > getBytesRead())
                            getSocket().receive(boost::asio::buffer(getBuffer()));

                        response = m_Service->call((_IINServiceRequest *) getBuffer().c_array(),
                                                   getBytesRead());
                        if (response == NULL)
                            throw NNullPointerException("Response is NULL");

                        boost::asio::write(*m_Socket,
                                           boost::asio::buffer(response, response->Head.Control.Size),
                                           errCode);
                    }
                    catch (exception & exp)
                    {
                        NString message(exp.what());

                        if (response == NULL)
                            response = new _IINServiceResponse();
                        memset(response, 0, sizeof(_IINServiceResponse));

                        response->Head.Control.Size = sizeof(_IINServiceResponse);
                        response->Head.Error.Code = 12;
                        message.copy(response->Head.Error.Message, message.length());

                        boost::asio::write(*m_Socket,
                                           boost::asio::buffer(response, response->Head.Control.Size),
                                           errCode);
                    }
                    delete response;
                    delete this;
                }
            };
        }
    }
}

#endif //NSERVICECONNECTIONTCP_H
