//
// Created by strohhalm on 28.06.15.
//

#include "NClientSocketIcmp.h"

namespace nox
{
    namespace network
    {
        NClientSocketIcmp::NClientSocketIcmp(const NString & service, boost::asio::io_service & ioService)
                : INClientSocket<boost::asio::ip::icmp::socket, boost::asio::ip::icmp::resolver, boost::asio::ip::icmp::resolver::iterator>(
                service, ioService)
        {
        }

        NClientSocketIcmp::NClientSocketIcmp(const NString & host, const NString & service,
                                           boost::asio::io_service & ioService)
                : INClientSocket<boost::asio::ip::icmp::socket, boost::asio::ip::icmp::resolver, boost::asio::ip::icmp::resolver::iterator>(
                host, service, ioService)
        {
        }

        NClientSocketIcmp::~NClientSocketIcmp()
        {
        }

        int NClientSocketIcmp::compareTo(INObject * other)
        {
            if (this == other)
                return 0;
            try
            {
                NClientSocketIcmp * obj = dynamic_cast<NClientSocketIcmp *>(other);

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