//
// Created by strohhalm on 20.06.15.
//

#ifndef NNETWORK_H
#define NNETWORK_H

#include <nbase/enumeration/INEnumeration.h>

using namespace nox::enumeration;

namespace nox
{
    namespace enumeration
    {
        class NNetwork : public INEnumeration<NNetwork, int>
        {
            friend class INEnumeration<NNetwork, int>;
        public:
            DefineEnumValue(NNetwork, IPV4);
            DefineEnumValue(NNetwork, IPV6);
        protected:
            NNetwork(const NString & name, int value);
            NNetwork(const NNetwork & other);
            virtual ~NNetwork();
        };
    }
}

#endif //NNETWORK_H
