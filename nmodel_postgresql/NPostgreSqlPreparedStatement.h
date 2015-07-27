//
// Created by strohhalm on 10.07.15.
//

#ifndef NWEBMEDIA_NPOSTGRESQLPREPAREDSTATEMENT_H
#define NWEBMEDIA_NPOSTGRESQLPREPAREDSTATEMENT_H

#include <nmodel/INPreparedStatement.h>
#include <nmodel_postgresql/NModelPostgreSql.h>

namespace nox
{
    namespace model
    {
        namespace postgresql
        {
            class NPostgreSqlPreparedStatement : public INPreparedStatement
            {
            protected:
                pqxx::connection      * m_Connection;
                pqxx::work            * m_Transaction;
                pqxx::result            m_Result;
            public:
                NPostgreSqlPreparedStatement(pqxx::connection * connection, pqxx::work * transaction, const NString & name);
                NPostgreSqlPreparedStatement(pqxx::connection * connection, pqxx::work * transaction, const NString & name, const NString & statement);
                virtual ~NPostgreSqlPreparedStatement();
                virtual void prepare();
                virtual nlong execute();
                virtual nbool executeQuery();
                virtual INResultSet * getResultSet();
                virtual void close();
                virtual nint compareTo(const INObject * other) const;
            protected:
                virtual void prepareNamedParameters();
                virtual void prepareStatement();
                virtual pqxx::prepare::invocation applyParameters(pqxx::prepare::invocation _inv);
            };
        }
    }
}

#endif //NWEBMEDIA_NPOSTGRESQLPREPAREDSTATEMENT_H
