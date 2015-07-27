//
// Created by strohhalm on 27.05.15.
//

#include "NRuntimeException.h"

namespace nox
{
    NRuntimeException::NRuntimeException() : NException("Runtime exception")
    {
    }

    NRuntimeException::NRuntimeException(const NString &message) : NException(message)
    {
    }

    NRuntimeException::~NRuntimeException()
    {
    }
}