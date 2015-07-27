//
// Created by strohhalm on 10.07.15.
//

#ifndef NWEBMEDIA_NPOSTGRESQLRESULTSET_H
#define NWEBMEDIA_NPOSTGRESQLRESULTSET_H

#include <nmodel/INResultSet.h>
#include <nmodel_postgresql/NModelPostgreSql.h>

namespace nox
{
    namespace model
    {
        namespace postgresql
        {
            class NPostgreSqlResultSet : public INResultSet
            {
            protected:
                pqxx::result m_Result;
                nulong       m_RowIndex;
            public:
                NPostgreSqlResultSet(pqxx::result result);
                virtual ~NPostgreSqlResultSet();
                virtual nbool first();
                virtual nbool previous();
                virtual nbool next();
                virtual nbool last();
                virtual nlong getColumnCount();
                virtual const NString getColumnName(nuint index);
                virtual NResultType getColumnType(nuint index);
                virtual NString getString(nuint index);
                virtual NDateTime getDateTime(nuint index);
                virtual NDate getDate(nuint index);
                virtual NTime getTime(nuint index);
                virtual NLongDouble getDouble(nuint index);
                virtual NLong getLong(nuint index);
                virtual NUnsignedLong getUnsignedLong(nuint index);
                virtual NInteger getInteger(nuint index);
                virtual NUnsignedInteger getUnsignedInteger(nuint index);
                virtual NShort getShort(nuint index);
                virtual NUnsignedShort getUnsignedShort(nuint index);
                virtual NBool getBool(nuint index);
                virtual nbool isNull(nuint index);
                virtual void close();
                virtual nint compareTo(const INObject * other) const;
            };
        }
    }
}

#endif //NWEBMEDIA_NPOSTGRESQLRESULTSET_H
