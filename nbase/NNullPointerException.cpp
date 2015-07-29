//
// Created by strohhalm on 03.06.15.
//

#include <nbase/NNullPointerException.h>

namespace nox
{
    NNullPointerException::NNullPointerException() : NRuntimeException()
    {
    }

    NNullPointerException::NNullPointerException(const NString &message) : NRuntimeException(message)
    {
    }

    NNullPointerException::~NNullPointerException()
    {
    }
}
