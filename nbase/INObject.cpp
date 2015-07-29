//
// Created by strohhalm on 29.05.15.
//

#include <nbase/INObject.h>

namespace nox
{
    INObject::INObject()
    {
    }

    INObject::~INObject()
    {
    }

    nbool INObject::operator==(const INObject & other) const
    {
        return isEquals(other);
    }

    nbool INObject::operator==(const INObject * other) const
    {
        return isEquals(other);
    }

    nbool INObject::operator!=(const INObject & other) const
    {
        return !isEquals(other);
    }

    nbool INObject::operator!=(const INObject * other) const
    {
        return !isEquals(other);
    }

    nbool INObject::operator<(const INObject & other) const
    {
        return compareTo(other) < 0;
    }

    nbool INObject::operator<(const INObject * other) const
    {
        return compareTo(other) < 0;
    }

    nbool INObject::operator>(const INObject & other) const
    {
        return compareTo(other) > 0;
    }

    nbool INObject::operator>(const INObject * other) const
    {
        return compareTo(other) > 0;
    }

    nbool INObject::operator>=(const INObject & other) const
    {
        return compareTo(other) >= 0;
    }

    nbool INObject::operator>=(const INObject * other) const
    {
        return compareTo(other) >= 0;
    }

    nbool INObject::operator<=(const INObject & other) const
    {
        return compareTo(other) <= 0;
    }

    nbool INObject::operator<=(const INObject * other) const
    {
        return compareTo(other) <= 0;
    }

    nbool INObject::isEquals(const INObject & other) const
    {
        return compareTo(other) == 0;
    }

    nbool INObject::isEquals(const INObject * other) const
    {
        return compareTo(other) == 0;
    }

    nint INObject::compareTo(const INObject & other) const
    {
        return compareTo(&other);
    }
}
