//
// Created by strohhalm on 18.06.15.
//

#include "INServerSocketIcmp.h"

namespace nox
{
    namespace network
    {
        INServerSocketIcmp::INServerSocketIcmp(boost::asio::ip::icmp::endpoint * endpoint)
                : INServerSocket<boost::asio::ip::icmp::endpoint>(endpoint)
        {
            m_Socket = new boost::asio::ip::icmp::socket(*m_IoService, *endpoint);
        }

        INServerSocketIcmp::~INServerSocketIcmp()
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

        void INServerSocketIcmp::run(bool async)
        {
            INConnectionIcmp * newConnection = createConnection(m_Socket);
            if (async)
            {
                m_Socket->async_receive_from(boost::asio::buffer(newConnection->getBuffer()),
                                             newConnection->getEndpoint(), boost::bind(
                                &INServerSocket<boost::asio::ip::icmp::endpoint>::handleReceive, this,
                                boost::asio::placeholders::error, async, newConnection,
                                boost::asio::placeholders::bytes_transferred()));
            }
            else
            {
                boost::system::error_code errCode;

                size_t bytes_read = m_Socket->receive_from(boost::asio::buffer(newConnection->getBuffer()),
                                                           newConnection->getEndpoint(),
                                                           0,
                                                           errCode);

                handleReceive(errCode, async, newConnection, bytes_read);
            }
        }
    }
}