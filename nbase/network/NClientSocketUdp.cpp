//
// Created by strohhalm on 28.06.15.
//

#include "NClientSocketUdp.h"

namespace nox
{
    namespace network
    {
        NClientSocketUdp::NClientSocketUdp(const NString & service, boost::asio::io_service & ioService)
                : INClientSocket<boost::asio::ip::udp::socket, boost::asio::ip::udp::resolver, boost::asio::ip::udp::resolver::iterator>(
                service, ioService)
        {
        }

        NClientSocketUdp::NClientSocketUdp(const NString & host, const NString & service,
                                           boost::asio::io_service & ioService)
                : INClientSocket<boost::asio::ip::udp::socket, boost::asio::ip::udp::resolver, boost::asio::ip::udp::resolver::iterator>(
                host, service, ioService)
        {
        }

        NClientSocketUdp::~NClientSocketUdp()
        {
        }

        nint NClientSocketUdp::compareTo(const INObject * other) const
        {
            if (this == other)
                return 0;
            try
            {
                const NClientSocketUdp * obj = dynamic_cast<const NClientSocketUdp *>(other);

                if (obj != NULL)
                {
                    if (this > obj)
                        return 1;
                    return -1;
                }
                else
                {
                    return 1;
                }
            }
            catch (bad_cast &)
            {
                return 1;
            }
        }
    }
}