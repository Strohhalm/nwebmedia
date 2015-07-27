//
// Created by strohhalm on 18.06.15.
//

#include "INServerSocketUdp.h"

namespace nox
{
    namespace network
    {
        INServerSocketUdp::INServerSocketUdp(boost::asio::ip::udp::endpoint * endpoint)
                : INServerSocket<boost::asio::ip::udp::endpoint>(endpoint)
        {
            m_Socket = new boost::asio::ip::udp::socket(*m_IoService, *endpoint);
        }

        INServerSocketUdp::~INServerSocketUdp()
        {
            if (m_Socket != NULL)
            {
                if (m_Socket->is_open())
                {
                    m_Socket->cancel();
                    m_Socket->close();
                }
                delete m_Socket;
            }
        }

        void INServerSocketUdp::run(bool async)
        {
            INConnectionUdp * newConnection = createConnection(m_Socket);

            if (async)
            {
                m_Socket->async_receive_from(boost::asio::buffer(newConnection->getBuffer()),
                                             newConnection->getEndpoint(),
                                             boost::bind(&INServerSocketUdp::handleReceive, this,
                                                         boost::asio::placeholders::error, async, newConnection,
                                                         boost::asio::placeholders::bytes_transferred));
            }
            else
            {
                boost::system::error_code errCode;

                nsize bytesRead = m_Socket->receive_from(boost::asio::buffer(newConnection->getBuffer()),
                                                          newConnection->getEndpoint(), 0, errCode);

                this->handleReceive(errCode, async, newConnection, bytesRead);
            }
        }
    }
}