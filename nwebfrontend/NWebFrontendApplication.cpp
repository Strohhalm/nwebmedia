//
// Created by strohhalm on 28.06.15.
//

#include "NWebFrontendApplication.h"

namespace nox
{
    NWebFrontendApplication::NWebFrontendApplication() : INWebApplication<NWebFrontendApplication, NSession>()
    {
    }

    NWebFrontendApplication::~NWebFrontendApplication()
    {
    }

    nint NWebFrontendApplication::compareTo(const INObject * other) const
    {
        if (this == other)
            return 0;
        try
        {
            const NWebFrontendApplication * obj = dynamic_cast<const NWebFrontendApplication *>(other);

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