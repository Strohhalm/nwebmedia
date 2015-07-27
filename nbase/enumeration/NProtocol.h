//
// Created by strohhalm on 16.06.15.
//

#ifndef NPROTOCOL_H
#define NPROTOCOL_H

#include <nbase/enumeration/INEnumeration.h>

using namespace nox::enumeration;

namespace nox
{
    namespace enumeration
    {
        class NProtocol : public INEnumeration<NProtocol, int>
        {
            friend class INEnumeration<NProtocol, int>;
        public:
            DefineEnumValue(NProtocol, UNKNOWN)
            DefineEnumValue(NProtocol, TCP)
            DefineEnumValue(NProtocol, UDP)
            DefineEnumValue(NProtocol, ICMP)
        protected:
            NProtocol(const NString & name, int value);
            NProtocol(const NProtocol & other);
            virtual ~NProtocol();
        };
    }
}

#endif //NPROTOCOL_H
