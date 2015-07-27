//
// Created by strohhalm on 04.07.15.
//

#include "NTime.h"
#include "NRuntimeException.h"

namespace nox
{
    NTime NTime::getCurrentTime()
    {
        system_clock::time_point today     = system_clock::now();
        system_clock::duration   Duration  = today.time_since_epoch();
        time_t                   _time     = system_clock::to_time_t(today);

        nint  millisecond  = (Duration.count() % CLOCKS_PER_SEC) / 1000;
        tm  * ctime        = localtime(&_time);

        return NTime(ctime->tm_hour, ctime->tm_min, ctime->tm_sec, millisecond);
    }

    NTime::NTime() : INObject()
    {
        m_Time.Hour = 0;
        m_Time.Minute = 0;
        m_Time.Second = 0;
        m_Time.Millisecond = 0;
        m_tm = {0};
    }

    NTime::NTime(const NString & timeString) : INObject()
    {
        sscanf(timeString.c_str(), "%i:%i:%i", &m_Time.Hour, &m_Time.Minute, &m_Time.Second);

        m_Time.Millisecond = 0;
        m_tm = {0};
    }

    NTime::NTime(const nint hour, const nint minute, const nint second, const nint millisecond) : INObject()
    {
        if (hour < 0 && hour > 23)
            throw NRuntimeException("Hour has to be between 0 and 23");
        if (minute < 0 && minute > 59)
            throw NRuntimeException("Hour has to be between 0 and 59");
        if (second < 0 && second > 59)
            throw NRuntimeException("Hour has to be between 0 and 59");
        if (millisecond < 0 && millisecond > 999)
            throw NRuntimeException("Hour has to be between 0 and 999");

        m_Time.Hour = hour;
        m_Time.Minute = minute;
        m_Time.Second = second;
        m_Time.Millisecond = millisecond;
        m_tm = {0};
    }

    NTime::NTime(const ntime & time) :INObject()
    {
        m_Time.Hour = time.Hour;
        m_Time.Minute = time.Minute;
        m_Time.Second = time.Second;
        m_Time.Millisecond = time.Millisecond;

        m_tm = {0};
    }

    NTime::NTime(const tm & ctime) : INObject()
    {
        m_Time.Hour = ctime.tm_hour;
        m_Time.Minute = ctime.tm_min;
        m_Time.Second = ctime.tm_sec;
        m_Time.Millisecond = 0;

        m_tm = {0};
    }

    NTime::NTime(const NTime & other) : INObject()
    {
        m_Time.Hour = other.m_Time.Hour;
        m_Time.Minute = other.m_Time.Minute;
        m_Time.Second = other.m_Time.Second;
        m_Time.Millisecond = other.m_Time.Millisecond;
        m_tm = {0};
    }

    NTime::~NTime()
    {

    }

    const nint NTime::getHour() const
    {
        return m_Time.Hour;
    }

    const nint NTime::getMinute() const
    {
        return m_Time.Minute;
    }

    const nint NTime::getSecond() const
    {
        return m_Time.Second;
    }

    const nint NTime::getMillisecond() const
    {
        return m_Time.Millisecond;
    }

    void NTime::addHours(const nint hours)
    {
        m_Time.Hour += hours;
        while (m_Time.Hour > 23)
        {
            m_Time.Hour -= 24;
        }
        while (m_Time.Hour < 0)
        {
            m_Time.Hour += 24;
        }
    }

    void NTime::addMinutes(const nint minutes)
    {
        m_Time.Minute += minutes;
        while (m_Time.Minute > 59)
        {
            m_Time.Minute -= 60;
            addHours(1);
        }
        while (m_Time.Second < 0)
        {
            m_Time.Minute += 60;
            addHours(-1);
        }
    }

    void NTime::addSeconds(const nint seconds)
    {
        m_Time.Second += seconds;
        while (m_Time.Second > 59)
        {
            m_Time.Second -= 60;
            addMinutes(1);
        }
        while (m_Time.Second < 0)
        {
            m_Time.Second += 60;
            addMinutes(-1);
        }
    }

    void NTime::addMilliSeconds(const nint milliseconds)
    {
        m_Time.Millisecond += milliseconds;
        while (m_Time.Millisecond > 999)
        {
            m_Time.Millisecond -= 1000;
            addSeconds(1);
        }
        while (m_Time.Millisecond < 0)
        {
            m_Time.Millisecond += 1000;
            addSeconds(-1);
        }
    }

    tm & NTime::to_tm()
    {
        m_tm.tm_hour = m_Time.Hour;
        m_tm.tm_min = m_Time.Minute;
        m_tm.tm_sec = m_Time.Second;

        return m_tm;
    }

    void NTime::copy(ntime & input)
    {
        input.Hour = m_Time.Hour;
        input.Minute  = m_Time.Minute;
        input.Second  = m_Time.Second;
        input.Millisecond = m_Time.Millisecond;
    }

    NString NTime::toString()
    {
        char    _res[100] = "";

        sprintf(_res, "%2.2i-%2.2i-%2.2i", m_Time.Hour, m_Time.Minute, m_Time.Second);

        return NString(_res);
    }

    nint NTime::compareTo(const INObject * other) const
    {
        if (this == other)
            return 0;
        try
        {
            const NTime * obj = dynamic_cast<const NTime *>(other);

            if (obj != NULL)
            {
                nint result = 0;
                if ((result = getHour() - obj->getHour()) == 0)
                {
                    if ((result = getMinute() - obj->getMinute()) == 0)
                    {
                        if ((result = getSecond() - obj->getSecond()) == 0)
                        {
                            result = getMillisecond() - obj->getMillisecond();
                        }
                    }
                }
                return result;
            }
            else
            {
                return 1;
            }
        }
        catch (bad_cast &)
        {
            return 1;
        }
    }
}