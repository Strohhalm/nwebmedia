//
// Created by strohhalm on 04.07.15.
//

#ifndef NWEBMEDIA_NTIME_H
#define NWEBMEDIA_NTIME_H

#include <nbase/NBase.h>
#include "INObject.h"

namespace nox
{
    struct ntime
    {
        nint Hour;
        nint Minute;
        nint Second;
        nint Millisecond;
    };

    class NTime : public INObject
    {
    public:
        static NTime getCurrentTime();
    protected:
        ntime m_Time;
        tm    m_tm;
    public:
        NTime();
        NTime(const tm & cdate);
        NTime(const ntime & time);
        NTime(const nint hour, const nint minute, const nint second, const nint millisecond);
        NTime(const NString & timeString);
        NTime(const NTime & other);
        virtual ~NTime();
        virtual const nint getHour() const;
        virtual const nint getMinute() const;
        virtual const nint getSecond() const;
        virtual const nint getMillisecond() const;
        virtual void set(const nint hour, const nint minute, const nint second, const nint millisecond);
        virtual void set(const NTime & other);
        virtual void addHours(const nint hours);
        virtual void addMinutes(const nint minutes);
        virtual void addSeconds(const nint seconds);
        virtual void addMilliSeconds(const nint milliseconds);
        virtual tm & to_tm();
        virtual void copy(ntime & input);
        virtual NString toString();
        virtual nint compareTo(const INObject * other) const;
    };
}

#endif //NWEBMEDIA_NTIME_H
