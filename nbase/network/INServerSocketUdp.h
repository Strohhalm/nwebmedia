//
// Created by strohhalm on 18.06.15.
//

#ifndef INSERVERSOCKETUDP_H
#define INSERVERSOCKETUDP_H

#include "INServerSocket.h"
#include "INConnectionUdp.h"

namespace nox
{
    namespace network
    {
        class INServerSocketUdp : public INServerSocket<boost::asio::ip::udp::endpoint>
        {
        protected:
            boost::asio::ip::udp::socket * m_Socket;
        public:
            INServerSocketUdp(boost::asio::ip::udp::endpoint * endpoint);
            virtual ~INServerSocketUdp();
            virtual void run(bool async = true);
        protected:
            virtual INConnectionUdp * createConnection(boost::asio::ip::udp::socket * socket) = 0;
        };
    }
}


#endif //INSERVERSOCKETUDP_H
