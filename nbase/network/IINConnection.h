//
// Created by strohhalm on 19.06.15.
//

#ifndef IINCONNECTION_H
#define IINCONNECTION_H

#include <nbase/INThread.h>

namespace nox
{
    namespace network
    {
        class IINConnection : public INThread
        {
        protected:
            nsize m_BytesRead;
        public:
            IINConnection();
            virtual ~IINConnection();
            virtual void setBytesRead(nsize bytesRead);
            virtual nsize getBytesRead();
        };
    }
}


#endif //IINCONNECTION_H
