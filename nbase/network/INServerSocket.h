//
// Created by strohhalm on 18.06.15.
//

#ifndef INSERVERSOCKET_H
#define INSERVERSOCKET_H

#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <nbase/collection/NList.h>
#include <nbase/network/IINServerSocket.h>
#include "IINConnection.h"

using namespace nox::collection;

namespace nox
{
    namespace network
    {
        template<class ENDPOINT>
        class INServerSocket : public IINServerSocket
        {
        protected:
            BOOST_STATIC_ASSERT(!is_pointer<ENDPOINT>::value);
            ENDPOINT                      * m_Endpoint;
            boost::asio::io_service       * m_IoService;
            boost::asio::io_service::work * m_IoServiceWork;
            boost::thread                 * m_Thread;
        public:
            INServerSocket(ENDPOINT * endpoint) : IINServerSocket()
            {
                m_Endpoint       = endpoint;
                m_IoService      = new boost::asio::io_service();
                m_IoServiceWork  = new boost::asio::io_service::work(*m_IoService);
                m_Thread         = new boost::thread(boost::bind(&boost::asio::io_service::run, m_IoService));
            }
            virtual ~INServerSocket()
            {
                if (m_Endpoint != NULL)
                    delete m_Endpoint;
                if (m_IoServiceWork != NULL)
                    delete m_IoServiceWork;
                if (m_Thread != NULL)
                {
                    m_Thread->join();
                    delete m_Thread;
                }
                if (m_IoService != NULL)
                    delete m_IoService;
            }
            virtual void run(bool async) = 0;
            virtual void handleReceive(const boost::system::error_code & errorCode, bool async, IINConnection * connection, nsize bytesRead)
            {
                if (!errorCode)
                {
                    connection->setBytesRead(bytesRead);
                    connection->start();
                }

                run(async);
            }
        };
    }
}

#endif //INSERVERSOCKET_H
