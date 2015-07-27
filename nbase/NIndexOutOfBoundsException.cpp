//
// Created by strohhalm on 27.05.15.
//

#include "NIndexOutOfBoundsException.h"

namespace nox
{
    NIndexOutOfBoundsException::NIndexOutOfBoundsException() : NRuntimeException(NString("Index is out of bounds"))
    {

    }

    NIndexOutOfBoundsException::NIndexOutOfBoundsException(const NString &message) : NRuntimeException(message)
    {
    }

    NIndexOutOfBoundsException::~NIndexOutOfBoundsException()
    {
    }
}