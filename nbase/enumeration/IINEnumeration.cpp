//
// Created by strohhalm on 24.06.15.
//

#include "IINEnumeration.h"

namespace nox
{
    namespace enumeration
    {
        INMap<NString, INList<IINEnumeration *> *>* IINEnumeration::s_EnumMap = NULL;

        INMap<NString, INList<IINEnumeration *> *>* IINEnumeration::getEnumMap()
        {
            if (s_EnumMap == NULL)
                s_EnumMap = new NMap<NString, INList<IINEnumeration *> *>();
            return s_EnumMap;
        }

        IINEnumeration::IINEnumeration() : INObject()
        {
        }

        IINEnumeration::~IINEnumeration()
        {
        }
    }
}