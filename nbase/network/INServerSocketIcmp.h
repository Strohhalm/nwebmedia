//
// Created by strohhalm on 18.06.15.
//

#ifndef INSERVERSOCKETICMP_H
#define INSERVERSOCKETICMP_H

#include "INServerSocket.h"
#include "INConnectionIcmp.h"

namespace nox
{
    namespace network
    {
        class INServerSocketIcmp : public INServerSocket<boost::asio::ip::icmp::endpoint>
        {
        protected:
            boost::asio::ip::icmp::socket * m_Socket;
        public:
            INServerSocketIcmp(boost::asio::ip::icmp::endpoint * endpoint);
            virtual ~INServerSocketIcmp();
            virtual void run(bool async = true);
        protected:
            virtual INConnectionIcmp * createConnection(boost::asio::ip::icmp::socket * ioService) = 0;
        };
    }
}

#endif //INSERVERSOCKETICMP_H
