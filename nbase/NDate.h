//
// Created by strohhalm on 31.05.15.
//

#ifndef NDATE_H
#define NDATE_H

#include <nbase/NBase.h>
#include "INObject.h"

namespace nox
{
    struct ndate
    {
        nint Day;
        nint Month;
        nint Year;
    };

    class NDate : public INObject
    {
    public:
        static NDate getCurrentDate();
        static const NDate INVALID;
    protected:
        ndate m_Date;
        tm    m_tm;
    public:
        NDate();
        NDate(const tm & cdate);
        NDate(const ndate & date);
        NDate(const nint year, const nint month, const nint day);
        NDate(const NString & dateString);
        NDate(const NDate & other);
        virtual ~NDate();
        virtual const nint getYear() const;
        virtual const nint getMonth() const;
        virtual const nint getDay() const;
        virtual void set(const nint year, const nint month, const nint day);
        virtual void set(const NDate & other);
        virtual void addYears(const nint years);
        virtual void addMonths(const nint months);
        virtual void addDays(const nint days);
        virtual nbool isLeapYear();
        virtual tm & to_tm();
        virtual void copy(ndate & input) const;
        virtual NString toString();
        virtual nint compareTo(const INObject * other) const ;
    };
}


#endif //NDATE_H
