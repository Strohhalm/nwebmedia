//
// Created by strohhalm on 31.05.15.
//

#include "NDate.h"
#include "NRuntimeException.h"

namespace nox
{
    NDate NDate::getCurrentDate()
    {
        system_clock::time_point today     = system_clock::now();
        time_t                   _time     = system_clock::to_time_t(today);

        tm  * ctime        = localtime(&_time);

        return NDate(*ctime);
    }

    NDate::NDate() : INObject()
    {
        m_Date.Year = -1;
        m_Date.Month = -1;
        m_Date.Day = -1;
        m_tm = {0};
    }

    NDate::NDate(const NString & dateString) : INObject()
    {
        sscanf(dateString.c_str(), "%i-%i-%i", &m_Date.Year, &m_Date.Month, &m_Date.Day);

        m_tm = {0};
    }

    NDate::NDate(const tm & cdate) : INObject()
    {
        m_Date.Year = cdate.tm_year + 1900;
        m_Date.Month = cdate.tm_mon;
        m_Date.Day = cdate.tm_mday;

        m_tm = {0};
    }

    NDate::NDate(const ndate & date)
    {
        m_Date.Year = date.Year;
        m_Date.Month = date.Month;
        m_Date.Day = date.Day;

        m_tm = {0};
    }

    NDate::NDate(const nint year, const nint month, const nint day) : INObject()
    {
        m_tm = {0};

        set(year, month, day);
    }

    NDate::NDate(const NDate & other) : INObject()
    {
        m_Date.Year = other.m_Date.Year;
        m_Date.Month = other.m_Date.Month;
        m_Date.Day = other.m_Date.Day;
        m_tm  = other.m_tm;
    }

    NDate::~NDate()
    {
    }

    const nint NDate::getYear() const
    {
        return m_Date.Year;
    }

    const nint NDate::getMonth() const
    {
        return m_Date.Month;
    }

    const nint NDate::getDay() const
    {
        return m_Date.Day;
    }

    void NDate::set(const nint year, const nint month, const nint day)
    {
        if (year < 0)
            throw NRuntimeException("Years has to be greater than zero");
        if (month < 1 && month > 12)
            throw NRuntimeException("Month has to be between 1 and 12");
        m_Date.Year = year;
        m_Date.Month = month;

        switch (month)
        {
            case 1:
                if (isLeapYear())
                {
                    if (day < 1 && day > 29)
                    {
                        throw NRuntimeException("Day has to be between 1 and 29");
                    }
                }
                else
                {
                    if (day < 1 && day > 28)
                    {
                        throw NRuntimeException("Day has to be between 1 and 28");
                    }
                }
                break;
            case 3:
            case 5:
            case 8:
            case 10:
                if (day < 1 && day > 30)
                {
                    throw NRuntimeException("Day has to be between 1 and 30");
                }
                break;
            default:
                if (day < 1 && day > 31)
                {
                    throw NRuntimeException("Day has to be between 1 and 31");
                }
                break;
        }
        m_Date.Day = day;
    }

    void NDate::set(const NDate & other)
    {
        m_Date.Year = other.m_Date.Year;
        m_Date.Month = other.m_Date.Month;
        m_Date.Day = other.m_Date.Day;
        m_tm  = other.m_tm;
    }

    void NDate::addYears(const nint years)
    {
        m_Date.Year += years;
    }

    void NDate::addMonths(const nint months)
    {
        m_Date.Month += months;
        while (m_Date.Month > 11)
        {
            m_Date.Month -= 12;
            addYears(1);
        }
        while (m_Date.Month < 0)
        {
            m_Date.Month += 12;
            addYears(-1);
        }
    }

    void NDate::addDays(const nint days)
    {
        nint _days = days;
        nint mDays = 0;
        switch (getMonth())
        {
            case 1:
                if (isLeapYear())
                {
                    mDays = 29;
                }
                else
                {
                    mDays = 28;
                }
                break;
            case 3:
            case 5:
            case 8:
            case 10:
                mDays = 30;
                break;
            default:
                mDays = 31;
                break;
        }
        if (_days > mDays)
        {
            _days -= mDays;

            addMonths(1);
            addDays(_days);
        }
        else if (_days < 1)
        {
            _days += mDays;

            addMonths(-1);
            addDays(_days);
        }
        else
        {
            m_Date.Day += _days;
        }
    }

    nbool NDate::isLeapYear()
    {
        if (m_Date.Year % 4 == 0)
        {
            if (m_Date.Year % 100 == 0)
            {
                if (m_Date.Year % 400 == 0)
                {
                    return true;
                }
            }
            else
            {
                return true;
            }
        }
        return false;
    }

    tm & NDate::to_tm()
    {
        m_tm.tm_year = m_Date.Year - 1900;
        m_tm.tm_mon = m_Date.Month;
        m_tm.tm_mday = m_Date.Day;

        return m_tm;
    }

    void NDate::copy(ndate & input) const
    {
        input.Year = m_Date.Year;
        input.Month = m_Date.Month;
        input.Day = m_Date.Day;
    }

    NString NDate::toString()
    {
        char    _res[100] = "";

        sprintf(_res, "%4.4i-%2.2i-%2.2i", m_Date.Year, m_Date.Month, m_Date.Day);

        return NString(_res);
    }

    nint NDate::compareTo(const INObject * other) const
    {
        if (this == other)
            return 0;
        try
        {
            const NDate * obj = dynamic_cast<const NDate *>(other);

            if (obj != NULL)
            {
                int result = 0;
                if ((result = getYear() - obj->getYear()) == 0)
                {
                    if ((result = getMonth() - obj->getMonth()) == 0)
                    {
                        result = getDay() - obj->getDay();
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