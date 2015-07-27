//
// Created by strohhalm on 28.06.15.
//

#ifndef NWEBMEDIA_NCLIENTSOCKETTCP_H
#define NWEBMEDIA_NCLIENTSOCKETTCP_H

#include "INClientSocket.h"

namespace nox
{
    namespace network
    {
        class NClientSocketTcp : public INClientSocket<boost::asio::ip::tcp::socket, boost::asio::ip::tcp::resolver, boost::asio::ip::tcp::resolver::iterator>
        {
        public:
            NClientSocketTcp(const NString & service, boost::asio::io_service & ioService);
            NClientSocketTcp(const NString & host, const NString & service, boost::asio::io_service & ioService);
            virtual ~NClientSocketTcp();
            virtual void send(void * data, nsize size);
            virtual void receive(void * data, nsize size);
            virtual nint compareTo(const INObject * other) const;
        };
    }
}


#endif //NWEBMEDIA_NCLIENTSOCKETTCP_H
