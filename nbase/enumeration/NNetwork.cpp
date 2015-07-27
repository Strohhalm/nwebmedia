//
// Created by strohhalm on 20.06.15.
//

#include "NNetwork.h"

namespace nox
{
    namespace enumeration
    {
        DeclareEnumValue(NNetwork, IPV4, 1)
        DeclareEnumValue(NNetwork, IPV6, 2)

        NNetwork::NNetwork(const NString & name, int value) : INEnumeration<NNetwork, int>(name, value)
        {
        }

        NNetwork::NNetwork(const NNetwork & other) : INEnumeration<NNetwork, int>(other)
        {
        }

        NNetwork::~NNetwork()
        {
        }
    }
}