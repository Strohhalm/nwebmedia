//
// Created by strohhalm on 18.06.15.
//

#ifndef INCONNECTIONUDP_H
#define INCONNECTIONUDP_H

#include "INConnection.h"

namespace nox
{
    namespace network
    {
        class INConnectionUdp : public INConnection<boost::asio::ip::udp::socket>
        {
        protected:
            boost::asio::ip::udp::endpoint * m_Endpoint;
        public:
            INConnectionUdp(boost::asio::ip::udp::socket * socket, boost::asio::ip::udp::endpoint * endPoint) : INConnection<boost::asio::ip::udp::socket>(socket)
            {
                m_Endpoint = endPoint;
            }
            virtual ~INConnectionUdp()
            {
                if (m_Endpoint != NULL)
                    delete m_Endpoint;
            }
            virtual boost::asio::ip::udp::endpoint & getEndpoint()
            {
                return *m_Endpoint;
            }
        };
    }
}


#endif //INCONNECTIONUDP_H
