//
// Created by strohhalm on 27.06.15.
//

#ifndef NWEBMEDIA_IINCLIENTSOCKET_H
#define NWEBMEDIA_IINCLIENTSOCKET_H

#include <nbase/INObject.h>
#include <nbase/NBaseType.h>

namespace nox
{
    namespace network
    {
        class IINClientSocket : public INObject
        {
        protected:
            NString * m_Host;
            NString * m_Service;
        public:
            IINClientSocket(const NString & service);
            IINClientSocket(const NString & host, const NString & service);
            virtual ~IINClientSocket();
            virtual void connect() = 0;
            virtual void disconnect() = 0;
            virtual bool isConnected() = 0;
            virtual void send(void * data, nsize size) = 0;
            virtual void receive(void * data, nsize size) = 0;
        };
    }
}


#endif //NWEBMEDIA_IINCLIENTSOCKET_H
