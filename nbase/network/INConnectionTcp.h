//
// Created by strohhalm on 18.06.15.
//

#ifndef NCONNECTIONTCP_H
#define NCONNECTIONTCP_H

#include "INConnection.h"

namespace nox
{
    namespace network
    {
        class INConnectionTcp : public INConnection<boost::asio::ip::tcp::socket>
        {
        public:
            INConnectionTcp(boost::asio::ip::tcp::socket * socket) : INConnection<boost::asio::ip::tcp::socket>(socket)
            {
            }
            virtual ~INConnectionTcp()
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
        };
    }
}

#endif //NCONNECTIONTCP_H
