//
// Created by strohhalm on 31.05.15.
//

#include <nbase/NDateTime.h>
#include <nbase/NRuntimeException.h>

namespace nox
{
    NDateTime NDateTime::getCurrentDateTime()
    {
        system_clock::time_point today = system_clock::now();
        system_clock::duration Duration = today.time_since_epoch();
        time_t _time = system_clock::to_time_t(today);

        nint millisecond = (Duration.count() % CLOCKS_PER_SEC) / 1000;
        tm * ctime = localtime(&_time);

        return NDateTime(ctime->tm_year + 1900, ctime->tm_mon, ctime->tm_mday, ctime->tm_hour, ctime->tm_min,
                         ctime->tm_sec, millisecond);
    }

    const NDateTime * NDateTime::INVALID = new NDateTime();

    NDateTime::NDateTime() : INObject(), m_Date(), m_Time()
    {
        m_tm = {0};
    }

    NDateTime::NDateTime(const tm & cdate) : INObject(), m_Date(cdate), m_Time(cdate)
    {
        m_tm = {0};
    }

    NDateTime::NDateTime(const ndatetime & datetime) : INObject(), m_Date(datetime), m_Time(datetime)
    {
        m_tm = {0};
    }

    NDateTime::NDateTime(const NDate & date, const NTime & time) : INObject(), m_Date(date), m_Time(time)
    {
        m_tm = {0};
    }

    NDateTime::NDateTime(const nint year, const nint month, const nint day)
            : INObject(), m_Date(year, month, day), m_Time()
    {
        m_tm = {0};
    }

    NDateTime::NDateTime(const nint year, const nint month, const nint day, const nint hour, const nint minute,
                         const nint second, const nint millisecond)
            : INObject(), m_Date(year, month, day), m_Time(hour, minute, second, millisecond)
    {
        m_tm = {0};
    }

    NDateTime::NDateTime(const NString & dateString)
            : INObject(), m_Date(dateString.substr(0, dateString.find(" "))),
              m_Time(dateString.substr(dateString.find(" ") + 1))
    {
        m_tm = {0};
    }

    NDateTime::NDateTime(const NDateTime & other) : INObject(), m_Date(other.m_Date), m_Time(other.m_Time)
    {
        m_tm = {0};
    }

    NDateTime::~NDateTime()
    {
    }

    const nint NDateTime::getYear() const
    {
        return m_Date.getYear();
    }

    const nint NDateTime::getMonth() const
    {
        return m_Date.getMonth();
    }

    const nint NDateTime::getDay() const
    {
        return m_Date.getDay();
    }

    const nint NDateTime::getHour() const
    {
        return m_Time.getHour();
    }

    const nint NDateTime::getMinute() const
    {
        return m_Time.getMinute();
    }

    const nint NDateTime::getSecond() const
    {
        return m_Time.getSecond();
    }

    const nint NDateTime::getMillisecond() const
    {
        return m_Time.getMillisecond();
    }
    
    void NDateTime::set(const nint year, const nint month, const nint day)
    {
        m_Date.set(year, month, day);
    }
    
    void NDateTime::set(const nint year, const nint month, const nint day, const nint hour, const nint minute, const nint second, const nint millisecond)
    {
        m_Date.set(year, month, day);
        m_Time.set(hour, minute, second, millisecond);
    }
    
    void NDateTime::set(const NDate & date, const NTime & time)
    {
        m_Date.set(date);
        m_Time.set(time);
    }
    
    void NDateTime::set(const NDateTime & dateTime)
    {
        m_Date.set(dateTime.m_Date);
        m_Time.set(dateTime.m_Time);
    }

    void NDateTime::addYears(const nint years)
    {
        m_Date.addYears(years);
    }

    void NDateTime::addMonths(const nint months)
    {
        m_Date.addMonths(months);
    }

    void NDateTime::addDays(const nint days)
    {
        m_Date.addDays(days);
    }

    void NDateTime::addHours(const nint hours)
    {
        nint _hours = hours;
        while (getHour() * _hours > 23)
        {
            _hours -= 24;
            addDays(1);
        }
        while (getHour() + _hours < 0)
        {
            _hours += 24;
            addDays(-1);
        }
        m_Time.addHours(_hours);
    }

    void NDateTime::addMinutes(const nint minutes)
    {
        nint _minutes = minutes;
        while (getMinute() * _minutes > 59)
        {
            _minutes -= 60;
            addHours(1);
        }
        while (getMinute() + _minutes < 0)
        {
            _minutes += 60;
            addHours(-1);
        }
        m_Time.addMinutes(_minutes);
    }

    void NDateTime::addSeconds(const nint seconds)
    {
        nint _seconds = seconds;
        while (getSecond() * _seconds > 59)
        {
            _seconds -= 60;
            addMinutes(1);
        }
        while (getSecond() + _seconds < 0)
        {
            _seconds += 60;
            addMinutes(-1);
        }
        m_Time.addSeconds(_seconds);
    }

    void NDateTime::addMilliSeconds(const nint milliseconds)
    {
        nint _milliseconds = milliseconds;
        while (getMillisecond() * _milliseconds > 999)
        {
            _milliseconds -= 1000;
            addSeconds(1);
        }
        while (getMillisecond() + _milliseconds < 0)
        {
            _milliseconds += 1000;
            addSeconds(-1);
        }
        m_Time.addMilliSeconds(_milliseconds);
    }

    tm & NDateTime::to_tm()
    {
        tm cdate = m_Date.to_tm();
        tm ctime = m_Time.to_tm();

        m_tm.tm_year = cdate.tm_year;
        m_tm.tm_mon = cdate.tm_mon;
        m_tm.tm_mday = cdate.tm_mday;
        m_tm.tm_hour = ctime.tm_hour;
        m_tm.tm_min = ctime.tm_min;
        m_tm.tm_sec = ctime.tm_sec;

        m_tm.tm_isdst = -1;

        return m_tm;
    }

    void NDateTime::copy(ndatetime & input)
    {
        m_Date.copy(input);
        m_Time.copy(input);
    }

    NString NDateTime::toString()
    {
        NString result = "";

        result += m_Date.toString();
        result += " ";
        result += m_Time.toString();

        return result;
    }

    nint NDateTime::compareTo(const INObject * other) const
    {
        if (this == other)
            return 0;
        try
        {
            const NDateTime * obj = dynamic_cast<const NDateTime *>(other);

            if (obj != NULL)
            {
                int result = 0;
                if ((result = getYear() - obj->getYear()) == 0)
                {
                    if ((result = getMonth() - obj->getMonth()) == 0)
                    {
                        if ((result = getDay() - obj->getDay()) == 0)
                        {
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
