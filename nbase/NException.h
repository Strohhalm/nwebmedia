//
// Created by strohhalm on 27.05.15.
//

#ifndef NEXCEPTION_H
#define NEXCEPTION_H

#include <nbase/INObject.h>

namespace nox
{
    class NException : public INObject, public exception
    {
    protected:
        NString * m_Message;
    public:
        NException();
        NException(const NString & message);
        virtual ~NException();
        virtual bool isCritical() const;
        virtual const NString & getMessage() const;
        virtual const char* what() const _GLIBCXX_USE_NOEXCEPT;
        virtual nint compareTo(const INObject * other) const;
    };
}


#endif //NEXCEPTION_H
