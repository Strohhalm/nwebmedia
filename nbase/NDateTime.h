//
// Created by strohhalm on 31.05.15.
//

#ifndef NDATETIME_H
#define NDATETIME_H

#include <nbase/NBase.h>
#include "NDate.h"
#include "NTime.h"

namespace nox
{
    struct ndatetime : public ndate , public ntime
    {

    };

    class NDateTime : public INObject
    {
    public:
        static NDateTime getCurrentDateTime();
    protected:
        NDate m_Date;
        NTime m_Time;
        tm    m_tm;
    public:
        NDateTime();
        NDateTime(const tm & cdate);
        NDateTime(const ndatetime & datetime);
        NDateTime(const NDate & date, const NTime & time);
        NDateTime(const nint year, const nint month, const nint day);
        NDateTime(const nint year, const nint month, const nint day, const nint hour, const nint minute, const nint second, const nint millisecond);
        NDateTime(const NString & dateTimeString);
        NDateTime(const NDateTime & other);
        virtual ~NDateTime();
        virtual const nint getYear() const;
        virtual const nint getMonth() const;
        virtual const nint getDay() const;
        virtual const nint getHour() const;
        virtual const nint getMinute() const;
        virtual const nint getSecond() const;
        virtual const nint getMillisecond() const;
        virtual void addYears(const nint years);
        virtual void addMonths(const nint months);
        virtual void addDays(const nint days);
        virtual void addHours(const nint hours);
        virtual void addMinutes(const nint minutes);
        virtual void addSeconds(const nint seconds);
        virtual void addMilliSeconds(const nint milliseconds);
        virtual tm & to_tm();
        virtual void copy(ndatetime & input);
        virtual NString toString();
        virtual int compareTo(const INObject * other) const;
    };
}


#endif //NDATETIME_H