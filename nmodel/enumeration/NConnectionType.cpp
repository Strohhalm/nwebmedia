//
// Created by strohhalm on 06.06.15.
//

#include "NConnectionType.h"

namespace nox
{
    namespace model
    {
        namespace enumeration
        {
            DeclareEnumValue(NConnectionType, UNKNOWN, "unknown")
            DeclareEnumValue(NConnectionType, MYSQL, "MySql")
            DeclareEnumValue(NConnectionType, POSTGRESQL, "PostgreSql")
            DeclareEnumValue(NConnectionType, SQLITE, "Sqlite3")

            NConnectionType::NConnectionType(const NString & name, NString value)
                    : INEnumeration<NConnectionType, NString>(name, value)
            {
            }

            NConnectionType::NConnectionType(const NConnectionType & other) : INEnumeration<NConnectionType, NString>(
                    other)
            {
            }

            NConnectionType::~NConnectionType()
            {
            }
        }
    }
}