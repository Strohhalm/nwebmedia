//
// Created by strohhalm on 02.07.15.
//

#include "NServiceServerSocketUdp.h"
#include "NServiceConnectionUdp.h"

namespace nox
{
    namespace service
    {
        namespace network
        {
            NServiceServerSocketUdp::NServiceServerSocketUdp(IINService * service, NServiceConfig & serviceConfig)
                    : INServerSocketUdp(new boost::asio::ip::udp::endpoint((serviceConfig.getNetwork() == NNetwork::IPV4 ? boost::asio::ip::udp::v4() : boost::asio::ip::udp::v6()), serviceConfig.getPort()))
            {
                m_Service = service;
            }

            NServiceServerSocketUdp::~NServiceServerSocketUdp()
            {
            }

            INConnectionUdp * NServiceServerSocketUdp::createConnection(boost::asio::ip::udp::socket * socket)
            {
                return new NServiceConnectionUdp(m_Service, socket, new boost::asio::ip::udp::endpoint());
            }
        }
    }
}