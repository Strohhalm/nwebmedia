//
// Created by strohhalm on 18.06.15.
//

#ifndef INSERVERSOCKETTCP_H
#define INSERVERSOCKETTCP_H

#include "INServerSocket.h"
#include "INConnectionTcp.h"

namespace nox
{
    namespace network
    {
        class INServerSocketTcp : public INServerSocket<boost::asio::ip::tcp::endpoint>
        {
        protected:
            boost::asio::ip::tcp::acceptor * m_Acceptor;
        public:
            INServerSocketTcp(boost::asio::ip::tcp::endpoint * endpoint);
            virtual ~INServerSocketTcp();
            virtual void run(bool async = true);
        protected:
            virtual void handleReceive(const boost::system::error_code & errorCode, bool async, INConnectionTcp * connection, nsize bytesRead);
            virtual INConnectionTcp * createConnection(boost::asio::ip::tcp::socket * socket) = 0;
        };
    }
}

#endif //INSERVERSOCKETTCP_H
