//
// Created by strohhalm on 18.06.15.
//

#include "INServerSocketTcp.h"

namespace nox
{
    namespace network
    {
        INServerSocketTcp::INServerSocketTcp(boost::asio::ip::tcp::endpoint * endpoint)
                : INServerSocket<boost::asio::ip::tcp::endpoint>(endpoint)
        {
            m_Acceptor = new boost::asio::ip::tcp::acceptor(*m_IoService, *endpoint);
            m_Acceptor->listen();
        }

        INServerSocketTcp::~INServerSocketTcp()
        {
            if (m_Acceptor != NULL)
            {
                if (m_Acceptor->is_open())
                {
                    m_Acceptor->cancel();
                    m_Acceptor->close();
                }
                delete m_Acceptor;
            }
        }

        void INServerSocketTcp::run(bool async)
        {
            INConnectionTcp * newConnection = createConnection(
                    new boost::asio::ip::tcp::socket(m_Acceptor->get_io_service()));
            if (async)
            {
                m_Acceptor->async_accept(newConnection->getSocket(),
                                         boost::bind(&INServerSocketTcp::handleReceive, this,
                                                     boost::asio::placeholders::error, async, newConnection, 0));
            }
            else
            {
                boost::system::error_code errCode;
                this->handleReceive(m_Acceptor->accept(newConnection->getSocket(), errCode), async, newConnection, 0);
            }
        }

        void INServerSocketTcp::handleReceive(const boost::system::error_code & errorCode, bool async, INConnectionTcp * connection, nsize bytesRead)
        {
            if (!errorCode)
            {
                bytesRead = connection->getSocket().receive(boost::asio::buffer(connection->getBuffer()));
            }
            INServerSocket<boost::asio::ip::tcp::endpoint>::handleReceive(errorCode, async, connection, bytesRead);
        }
    }
}