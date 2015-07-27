//
// Created by strohhalm on 28.06.15.
//

#include "NBackendApplication.h"

namespace nox
{
    NBackendApplication::NBackendApplication() : INServiceApplication<NBackendApplication>()
    {
    }

    NBackendApplication::~NBackendApplication()
    {
    }

    nint NBackendApplication::compareTo(const INObject * other) const
    {
        if (this == other)
            return 0;
        try
        {
            const NBackendApplication * obj = dynamic_cast<const NBackendApplication *>(other);

            if (obj != NULL)
            {
                if (this > obj)
                    return 1;
                return -1;
            }
            else
            {
                return 1;
            }
        }
        catch (bad_cast &)
        {
            return 1;
        }
    }
}