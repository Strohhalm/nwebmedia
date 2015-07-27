//
// Created by strohhalm on 03.06.15.
//

#ifndef NNULLPOINTEREXCEPTION_H
#define NNULLPOINTEREXCEPTION_H

#include <nbase/NRuntimeException.h>

namespace nox
{
    class NNullPointerException : public NRuntimeException
    {
    public:
        NNullPointerException();
        NNullPointerException(const NString & message);
        virtual ~NNullPointerException();
    };
}

#endif //NNULLPOINTEREXCEPTION_H
