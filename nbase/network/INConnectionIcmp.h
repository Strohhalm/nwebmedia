//
// Created by strohhalm on 18.06.15.
//

#ifndef INCONNECTIONICMP_H
#define INCONNECTIONICMP_H

#include "INConnection.h"

namespace nox
{
    namespace network
    {
        class INConnectionIcmp : public INConnection<boost::asio::ip::icmp::socket>
        {
        protected:
            boost::asio::ip::icmp::endpoint * m_Endpoint;
        public:
            INConnectionIcmp(boost::asio::ip::icmp::socket * socket, boost::asio::ip::icmp::endpoint * endPoint) : INConnection<boost::asio::ip::icmp::socket>(socket)
            {
                    m_Endpoint = endPoint;
            }
            virtual ~INConnectionIcmp()
            {
                if (m_Endpoint != NULL)
                    delete m_Endpoint;
            }
            virtual boost::asio::ip::icmp::endpoint & getEndpoint()
            {
                return *m_Endpoint;
            }
        };
    }
}


#endif //INCONNECTIONICMP_H
