//
// Created by strohhalm on 27.06.15.
//

#ifndef NWEBMEDIA_INCLIENTSOCKET_H
#define NWEBMEDIA_INCLIENTSOCKET_H

#include <nbase/NRuntimeException.h>
#include <nbase/enumeration/NNetwork.h>
#include <nbase/network/IINClientSocket.h>

#include <boost/asio.hpp>

using namespace nox::enumeration;

namespace nox
{
    namespace network
    {
        template<class SOCKET, class RESOLVER, class ENDPOINT_ITER>
        class INClientSocket : public IINClientSocket
        {
        protected:
            SOCKET        * m_Socket;
        public:
            INClientSocket(const NString & service, boost::asio::io_service & ioService) : IINClientSocket(service)
            {
                m_Socket = new SOCKET(ioService);
                this->connect();
            }

            INClientSocket(const NString & host, const NString & service, boost::asio::io_service & ioService) : IINClientSocket(host, service)
            {
                m_Socket = new SOCKET(ioService);
                this->connect();
            }

            virtual ~INClientSocket()
            {
                if (m_Socket != NULL)
                {
                    if (isConnected())
                        m_Socket->close();
                    delete m_Socket;
                }
            }

            virtual void connect()
            {
                boost::system::error_code errCode;
                if (m_Socket != NULL)
                {
                    if (!isConnected())
                    {
                        RESOLVER _resolver(m_Socket->get_io_service());
                        ENDPOINT_ITER _iter;

                        if (m_Host == NULL)
                        {
                            typename RESOLVER::query _query(*m_Service);

                            _iter = _resolver.resolve(_query);
                        }
                        else
                        {
                            typename RESOLVER::query _query(*m_Host, *m_Service);

                            _iter = _resolver.resolve(_query);
                        }

                        boost::asio::connect(*m_Socket, _iter, errCode);
                        if (errCode)
                        {
                            throw new NRuntimeException(errCode.message());
                        }
                    }
                }
            }

            virtual void disconnect()
            {
                boost::system::error_code errCode;
                if (m_Socket != NULL)
                {
                    if (isConnected())
                    {
                        m_Socket->close(errCode);
                        if (errCode)
                        {
                            throw new NRuntimeException(errCode.message());
                        }
                    }
                }
            }

            virtual bool isConnected()
            {
                return m_Socket->is_open();
            }

            virtual void send(void * data, nsize size)
            {
                boost::system::error_code errCode;
                if (m_Socket != NULL)
                {
                    if (isConnected())
                    {
                        m_Socket->send(boost::asio::buffer(data, size), boost::asio::socket_base::message_out_of_band, errCode);
                        if (errCode)
                        {
                            throw new NRuntimeException(errCode.message());
                        }
                    }
                }
            }

            virtual void receive(void * data, nsize size)
            {
                boost::system::error_code errCode;
                if (m_Socket != NULL)
                {
                    if (isConnected())
                    {
                        m_Socket->receive(boost::asio::buffer(data, size), boost::asio::socket_base::message_out_of_band, errCode);
                        if (errCode)
                        {
                            throw new NRuntimeException(errCode.message());
                        }
                    }
                }
            }
        };
    }
}

#endif //NWEBMEDIA_INCLIENTSOCKET_H
