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
                NServiceConnectionTcp(IINService * serivce, boost::asio::ip::tcp::socket * socket);
                virtual ~NServiceConnectionTcp();
                virtual void run();
            };
        }
    }
}

#endif //NSERVICECONNECTIONTCP_H
