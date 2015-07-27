//
// Created by strohhalm on 27.05.15.
//

#ifndef NINDEXOUTOFBOUNDSEXCEPTION_H
#define NINDEXOUTOFBOUNDSEXCEPTION_H

#include <nbase/NRuntimeException.h>

namespace nox
{
    class NIndexOutOfBoundsException : public NRuntimeException
    {
    public:
        NIndexOutOfBoundsException();
        NIndexOutOfBoundsException(const NString & message);
        virtual ~NIndexOutOfBoundsException();
    };
}


#endif //NINDEXOUTOFBOUNDSEXCEPTION_H
