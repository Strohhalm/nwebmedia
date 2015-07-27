//
// Created by strohhalm on 06.06.15.
//

#ifndef NCONNECTIONTYPE_H
#define NCONNECTIONTYPE_H

#include <nbase/enumeration/INEnumeration.h>

using namespace nox::enumeration;

namespace nox
{
    namespace model
    {
        namespace enumeration
        {
            class NConnectionType : public INEnumeration<NConnectionType, NString>
            {
                friend class INEnumeration<NConnectionType, NString>;

            public:
                DefineEnumValue(NConnectionType, UNKNOWN)
                DefineEnumValue(NConnectionType, MYSQL)
                DefineEnumValue(NConnectionType, POSTGRESQL)
                DefineEnumValue(NConnectionType, SQLITE)
            protected:
                NConnectionType(const NString & name, NString value);
                NConnectionType(const NConnectionType & other);
                virtual ~NConnectionType();
            };


        }
    }
}
#endif //NCONNECTIONTYPE_H
