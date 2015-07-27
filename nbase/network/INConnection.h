//
// Created by strohhalm on 18.06.15.
//

#ifndef NCONNECTION_H
#define NCONNECTION_H

#include <boost/asio.hpp>
#include <boost/array.hpp>
#include <nbase/NException.h>
#include <nbase/NAssert.h>
#include "IINConnection.h"

namespace nox
{
    namespace network
    {
        template<class SOCKET>
        class INConnection : public IINConnection
        {
        protected:
            NStaticAssert(!is_pointer<SOCKET>::value);
            boost::array<nchar, 8192> * m_Buffer;
            SOCKET * m_Socket;
        public:
            INConnection(SOCKET * socket) : IINConnection()
            {
                m_Socket    = socket;
                m_Buffer    = new boost::array<nchar, 8192>();
                m_BytesRead = 0;
            }
            virtual ~INConnection()
            {
                if (m_Buffer != NULL)
                    delete m_Buffer;
            }
            virtual SOCKET & getSocket()
            {
                return *m_Socket;
            }
            virtual boost::array<nchar, 8192> & getBuffer()
            {
                return *m_Buffer;
            }
            virtual nint compareTo(const INObject * other) const
            {
                if (this == other)
                    return 0;
                try
                {
                    const INConnection<SOCKET> * obj = dynamic_cast<const INConnection<SOCKET> *>(other);

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
        };
    }
}


#endif //NCONNECTION_H
