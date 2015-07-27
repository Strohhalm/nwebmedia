//
// Created by strohhalm on 28.06.15.
//

#ifndef NWEBMEDIA_NCLIENTSOCKETUDP_H
#define NWEBMEDIA_NCLIENTSOCKETUDP_H

#include "INClientSocket.h"

namespace nox
{
    namespace network
    {
        class NClientSocketUdp : public INClientSocket<boost::asio::ip::udp::socket, boost::asio::ip::udp::resolver, boost::asio::ip::udp::resolver::iterator>
        {
        public:
            NClientSocketUdp(const NString & service, boost::asio::io_service & ioService);
            NClientSocketUdp(const NString & host, const NString & service, boost::asio::io_service & ioService);
            virtual ~NClientSocketUdp();
            virtual nint compareTo(const INObject * other) const;
        };
    }
}

#endif //NWEBMEDIA_NCLIENTSOCKETUDP_H
