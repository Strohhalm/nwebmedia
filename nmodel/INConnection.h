//
// Created by strohhalm on 09.07.15.
//

#ifndef NWEBMEDIA_INCONNECTION_H
#define NWEBMEDIA_INCONNECTION_H

#include <nbase/INObject.h>
#include <nbase/NBaseType.h>
#include "INPreparedStatement.h"

namespace nox
{
    namespace model
    {
        class INConnection : public INObject
        {
        protected:
            NString * m_Host;
            NUnsignedShort * m_Port;
            NString * m_User;
            NString * m_Password;
            NString * m_Database;
        public:
            INConnection(const NString & host, const NUnsignedShort & port, const NString & user, const NString & password, const NString & database);
            virtual ~INConnection();
            virtual const NString & getHost() const;
            virtual const NUnsignedShort & getPort() const;
            virtual const NString & getUser() const;
            virtual const NString & getPassword() const;
            virtual const NString & getDatabase() const;
            virtual nbool isConnected() const = 0;
            virtual void connect() = 0;
            virtual void rollback() = 0;
            virtual void commit() = 0;
            virtual void close() = 0;
            virtual INPreparedStatement * createPreparedStatement(const NString & name) = 0;
            virtual INPreparedStatement * createPreparedStatement(const NString & name, const NString & statement) = 0;
            virtual void * getBackend() = 0;
        };
    }
}


#endif //NWEBMEDIA_INCONNECTION_H
