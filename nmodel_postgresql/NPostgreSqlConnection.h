//
// Created by strohhalm on 09.07.15.
//

#ifndef NWEBMEDIA_NPOSTGRESQLCONNECTION_H
#define NWEBMEDIA_NPOSTGRESQLCONNECTION_H

#include <nmodel/INConnection.h>
#include <nmodel_postgresql/NModelPostgreSql.h>

namespace nox
{
    namespace model
    {
        namespace postgresql
        {
            class NPostgreSqlConnection : public INConnection
            {
            protected:
                pqxx::connection  * m_Connection;
                pqxx::work        * m_Transaction;
                nbool               m_IsTransactionOpen;
            public:
                NPostgreSqlConnection(const NString & host, const NUnsignedShort & port, const NString & user, const NString & password, const NString & database);
                virtual ~NPostgreSqlConnection();
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


#endif //NWEBMEDIA_NPOSTGRESQLCONNECTION_H
