//
// Created by strohhalm on 09.07.15.
//

#ifndef NWEBMEDIA_NMYSQLTYPEDSTATEMENT_H
#define NWEBMEDIA_NMYSQLTYPEDSTATEMENT_H

#include <nmodel/INPreparedStatement.h>
#include <nmodel_mysql/NModelMySql.h>

namespace nox
{
    namespace model
    {
        namespace mysql
        {
            class NMySqlPreparedStatement : public INPreparedStatement
            {
            protected:
                sql::Connection        * m_Connection;
                sql::PreparedStatement * m_PreparedStatement;
            public:
                NMySqlPreparedStatement(sql::Connection * connection, const NString & name);
                NMySqlPreparedStatement(sql::Connection * connection, const NString & name, const NString & statement);
                virtual ~NMySqlPreparedStatement();
                virtual void prepare();
                virtual nlong execute();
                virtual nbool executeQuery();
                virtual INResultSet * getResultSet();
                virtual void close();
                virtual nint compareTo(const INObject * other) const;
            protected:
                virtual void prepareNamedParameters();
                virtual void applyParameters();
            };
        }
    }
}


#endif //NWEBMEDIA_NMYSQLTYPEDSTATEMENT_H
