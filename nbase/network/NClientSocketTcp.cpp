//
// Created by strohhalm on 28.06.15.
//

#include "NClientSocketTcp.h"


namespace nox
{
    namespace network
    {
        NClientSocketTcp::NClientSocketTcp(const NString & service, boost::asio::io_service & ioService)
                : INClientSocket<boost::asio::ip::tcp::socket, boost::asio::ip::tcp::resolver, boost::asio::ip::tcp::resolver::iterator>(
                service, ioService)
        {
        }

        NClientSocketTcp::NClientSocketTcp(const NString & host, const NString & service,
                                           boost::asio::io_service & ioService)
                : INClientSocket<boost::asio::ip::tcp::socket, boost::asio::ip::tcp::resolver, boost::asio::ip::tcp::resolver::iterator>(
                host, service, ioService)
        {
        }

        NClientSocketTcp::~NClientSocketTcp()
        {
        }

        void NClientSocketTcp::send(void * data, nsize size)
        {
            boost::system::error_code errCode;
            if (m_Socket != NULL)
            {
                if (isConnected())
                {
                    boost::asio::write(*m_Socket, boost::asio::buffer(data, size), errCode);
                    if (errCode)
                    {
                        throw new NRuntimeException(errCode.message());
                    }
                }
            }
        }

        void NClientSocketTcp::receive(void * data, nsize size)
        {
            boost::system::error_code errCode;
            if (m_Socket != NULL)
            {
                if (isConnected())
                {
                    boost::asio::read(*m_Socket, boost::asio::buffer(data, size), errCode);
                    if (errCode)
                    {
                        throw new NRuntimeException(errCode.message());
                    }
                }
            }
        }

        nint NClientSocketTcp::compareTo(const INObject * other) const
        {
            if (this == other)
                return 0;
            try
            {
                const NClientSocketTcp * obj = dynamic_cast<const NClientSocketTcp *>(other);

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