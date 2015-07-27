//
// Created by strohhalm on 09.07.15.
//

#ifndef NWEBMEDIA_NMYSQLCONNECTION_H
#define NWEBMEDIA_NMYSQLCONNECTION_H

#include <nmodel/INConnection.h>
#include <nmodel_mysql/NModelMySql.h>

namespace nox
{
    namespace model
    {
        namespace mysql
        {
            class NMySqlConnection : public INConnection
            {
            protected:
                sql::Driver     * m_Driver;
                sql::Connection * m_Connection;
            public:
                NMySqlConnection(const NString & host, const NUnsignedShort & port, const NString & user, const NString & password, const NString & database);
                virtual ~NMySqlConnection();
                virtual nbool isConnected() const;
                virtual void connect();
                virtual void rollback();
                virtual void commit();
                virtual void close();
                virtual void * getBackend();
                virtual INPreparedStatement * createPreparedStatement(const NString & name);
                virtual INPreparedStatement * createPreparedStatement(const NString & name, const NString & statement);
                virtual nint compareTo(const INObject * other) const;
            };
        }
    }
}

#endif //NWEBMEDIA_NMYSQLCONNECTION_H
