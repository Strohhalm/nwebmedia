//
// Created by strohhalm on 28.06.15.
//

#ifndef NWEBMEDIA_NCLIENTSOCKETICMP_H
#define NWEBMEDIA_NCLIENTSOCKETICMP_H

#include "INClientSocket.h"

namespace nox
{
    namespace network
    {
        class NClientSocketIcmp : public INClientSocket<boost::asio::ip::icmp::socket, boost::asio::ip::icmp::resolver, boost::asio::ip::icmp::resolver::iterator>
        {
        public:
            NClientSocketIcmp(const NString & service, boost::asio::io_service & ioService);
            NClientSocketIcmp(const NString & host, const NString & service, boost::asio::io_service & ioService);
            virtual ~NClientSocketIcmp();
            virtual int compareTo(INObject * other);
        };
    }
}


#endif //NWEBMEDIA_NCLIENTSOCKETICMP_H
