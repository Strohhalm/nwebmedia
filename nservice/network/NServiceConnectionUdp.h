//
// Created by strohhalm on 19.06.15.
//

#ifndef NSERVICECONNECTIONUDP_H
#define NSERVICECONNECTIONUDP_H

#include <nbase/NNullPointerException.h>
#include <nbase/network/INConnectionUdp.h>
#include <nservice/IINService.h>

using namespace nox::network;

namespace nox
{
    namespace service
    {
        namespace network
        {
            class NServiceConnectionUdp : public INConnectionUdp
            {
            protected:
                IINService * m_Service;
            public:
                NServiceConnectionUdp(IINService * service, boost::asio::ip::udp::socket * socket, boost::asio::ip::udp::endpoint * endPoint) : INConnectionUdp(socket, endPoint)
                {
                    m_Service = service;
                }
                virtual ~NServiceConnectionUdp()
                {
                }
                virtual void run()
                {
                    _IINServiceResponse * response = m_Service->call((_IINServiceRequest*)getBuffer().c_array(), getBytesRead());

                    m_Socket->send(boost::asio::buffer(response, response->Head.Control.Size));
                }
            };
        }
    }
}

#endif //NSERVICECONNECTIONUDP_H
