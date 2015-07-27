//
// Created by strohhalm on 02.07.15.
//

#ifndef NWEBMEDIA_NSERVICESERVERSOCKETUDP_H
#define NWEBMEDIA_NSERVICESERVERSOCKETUDP_H

#include <nbase/network/INServerSocketUdp.h>
#include <nservice/IINService.h>
#include <nservice/config/NServiceConfig.h>

using namespace nox::network;
using namespace nox::service::configuration;

namespace nox
{
    namespace service
    {
        namespace network
        {
            class NServiceServerSocketUdp : public INServerSocketUdp
            {
            protected:
                IINService * m_Service;
            public:
                NServiceServerSocketUdp(IINService * service, NServiceConfig & serviceConfig);
                virtual ~NServiceServerSocketUdp();
            protected:
                virtual INConnectionUdp * createConnection(boost::asio::ip::udp::socket * socket);
            };
        }
    }
}


#endif //NWEBMEDIA_NSERVICESERVERSOCKETUDP_H
