//
// Created by strohhalm on 10.07.15.
//

#ifndef NWEBMEDIA_INRESULTSET_H
#define NWEBMEDIA_INRESULTSET_H

#include <nbase/INObject.h>
#include <nbase/NBaseType.h>
#include <nmodel/NResultType.h>

namespace nox
{
    namespace model
    {
        class INResultSet : public INObject
        {
        public:
            INResultSet();
            virtual ~INResultSet();
            virtual nbool first() = 0;
            virtual nbool previous() = 0;
            virtual nbool next() = 0;
            virtual nbool last() = 0;
            virtual nlong getColumnCount() = 0;
            virtual const NString getColumnName(nuint index) = 0;
            virtual NResultType getColumnType(nuint index) = 0;
            virtual NString getString(nuint index) = 0;
            virtual NDateTime getDateTime(nuint index) = 0;
            virtual NDate getDate(nuint index) = 0;
            virtual NTime getTime(nuint index) = 0;
            virtual NLongDouble getDouble(nuint index) = 0;
            virtual NLong getLong(nuint index) = 0;
            virtual NUnsignedLong getUnsignedLong(nuint index) = 0;
            virtual NInteger getInteger(nuint index) = 0;
            virtual NUnsignedInteger getUnsignedInteger(nuint index) = 0;
            virtual NShort getShort(nuint index) = 0;
            virtual NUnsignedShort getUnsignedShort(nuint index) = 0;
            virtual NBool getBool(nuint index) = 0;
            virtual nbool isNull(nuint index) = 0;
            virtual void close() = 0;
        };
    }
}

#endif //NWEBMEDIA_INRESULTSET_H
