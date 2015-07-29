//
// Created by strohhalm on 29.05.15.
//

#ifndef INOBJECT_H
#define INOBJECT_H

#include <nbase/NBase.h>
#include <nbase/NTypes.h>

namespace nox
{
    class NOX_BASE_API INObject
    {
    public:
        INObject();
        virtual ~INObject();
        virtual nbool operator==(const INObject & other) const;
        virtual nbool operator==(const INObject * other) const;
        virtual nbool operator!=(const INObject & other) const;
        virtual nbool operator!=(const INObject * other) const;
        virtual nbool operator<(const INObject & other) const;
        virtual nbool operator<(const INObject * other) const;
        virtual nbool operator>(const INObject & other) const;
        virtual nbool operator>(const INObject * other) const;
        virtual nbool operator<=(const INObject & other) const;
        virtual nbool operator<=(const INObject * other) const;
        virtual nbool operator>=(const INObject & other) const;
        virtual nbool operator>=(const INObject * other) const;
        virtual nbool isEquals(const INObject & other) const;
        virtual nbool isEquals(const INObject * other) const;
        virtual nint compareTo(const INObject & other) const;
        virtual nint compareTo(const INObject * other) const = 0;
    };
}


#endif //INOBJECT_H

