//
// Created by strohhalm on 27.05.15.
//

#ifndef NRUNTIMEEXCEPTION_H
#define NRUNTIMEEXCEPTION_H

#include <nbase/NException.h>

namespace nox
{
    class NOX_BASE_API NRuntimeException : public NException
    {
    public:
        NRuntimeException();
        NRuntimeException(const NString & message);
        virtual ~NRuntimeException();
    };
}


#endif //NRUNTIMEEXCEPTION_H
