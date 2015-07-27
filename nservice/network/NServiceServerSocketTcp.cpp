//
// Created by strohhalm on 02.07.15.
//

#include "NServiceServerSocketTcp.h"
#include "NServiceConnectionTcp.h"

namespace nox
{
    namespace service
    {
        namespace network
        {
            NServiceServerSocketTcp::NServiceServerSocketTcp(IINService * service, NServiceConfig & serviceConfig) : INServerSocketTcp(new boost::asio::ip::tcp::endpoint(serviceConfig.getNetwork() ==
                                                                                                                                                                      NNetwork::IPV4 ? boost::asio::ip::tcp::v4() : boost::asio::ip::tcp::v6(), serviceConfig.getPort()))
            {
                m_Service = service;
            }

            NServiceServerSocketTcp::~NServiceServerSocketTcp()
            {
            }

            INConnectionTcp * NServiceServerSocketTcp::createConnection(boost::asio::ip::tcp::socket * socket)
            {
                return new NServiceConnectionTcp(m_Service, socket);
            }
        }
    }
}
