//
// Created by strohhalm on 24.06.15.
//

#ifndef NWEBMEDIA_IINENUMERATION_H
#define NWEBMEDIA_IINENUMERATION_H

#include <nbase/INObject.h>
#include <nbase/collection/NMap.h>

using namespace nox::collection;

namespace nox
{
    namespace enumeration
    {
        class IINEnumeration : public INObject
        {
        protected:
            static INMap<NString, INList<IINEnumeration *> *> * s_EnumMap;
            static INMap<NString, INList<IINEnumeration *> *> * getEnumMap();
        public:
            IINEnumeration();
            virtual ~IINEnumeration();
            virtual const NString & getName() const = 0;
            virtual const NString & getEnumName() const = 0;
        };
    }
}

#endif //NWEBMEDIA_IINENUMERATION_H
