//
// Created by strohhalm on 02.07.15.
//

#ifndef NWEBMEDIA_NSERVICESERVERSOCKETTCP_H
#define NWEBMEDIA_NSERVICESERVERSOCKETTCP_H

#include <nbase/network/INServerSocketTcp.h>
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
            class NServiceServerSocketTcp : public INServerSocketTcp
            {
            protected:
                IINService * m_Service;
            public:
                NServiceServerSocketTcp(IINService * service, NServiceConfig & serviceConfig);
                virtual ~NServiceServerSocketTcp();
            protected:
                virtual INConnectionTcp * createConnection(boost::asio::ip::tcp::socket * socket);
            };
        }
    }
}


#endif //NWEBMEDIA_NSERVICESERVERSOCKETTCP_H
