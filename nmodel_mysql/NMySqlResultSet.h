//
// Created by strohhalm on 09.07.15.
//

#ifndef NWEBMEDIA_NMYSQLTYPEDRESULTSET_H
#define NWEBMEDIA_NMYSQLTYPEDRESULTSET_H

#include <nbase/NBaseType.h>
#include <nmodel/INResultSet.h>
#include <nmodel_mysql/NModelMySql.h>

namespace nox
{
    namespace model
    {
        namespace mysql
        {
            class NMySqlResultSet : public INResultSet
            {
            protected:
                sql::ResultSet         * m_ResultSet;
                sql::ResultSetMetaData * m_MetaData;
            public:
                NMySqlResultSet(sql::PreparedStatement * statement);
                virtual ~NMySqlResultSet();
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


#endif //NWEBMEDIA_NMYSQLTYPEDRESULTSET_H
