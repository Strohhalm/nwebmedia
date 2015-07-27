//
// Created by strohhalm on 16.06.15.
//

#include "NProtocol.h"

namespace nox
{
    namespace enumeration
    {
        DeclareEnumValue(NProtocol, UNKNOWN, 0)
        DeclareEnumValue(NProtocol, TCP, 1)
        DeclareEnumValue(NProtocol, UDP, 2)
        DeclareEnumValue(NProtocol, ICMP, 4)

        NProtocol::NProtocol(const NString & name, int value) : INEnumeration<NProtocol, int>(name, value)
        {
        }

        NProtocol::NProtocol(const NProtocol & other) : INEnumeration<NProtocol, int>(other)
        {
        }

        NProtocol::~NProtocol()
        {
        }
    }
}