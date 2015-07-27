//
// Created by strohhalm on 16.07.15.
//

#ifndef NWEBMEDIA_NLOCALISATIONPORTION_H
#define NWEBMEDIA_NLOCALISATIONPORTION_H

#include <nbase/NBaseType.h>

namespace nox
{
    namespace service
    {
        namespace exchange
        {
            namespace infra
            {
                struct _NLocalisationPortion
                {
                    nulong from;
                    nulong count;
                };

                class NLocalisationPortion
                {
                protected:
                    NUnsignedLong * m_From;
                    NUnsignedLong * m_Count;
                public:
                    NLocalisationPortion();
                    NLocalisationPortion(const NUnsignedLong & from, const NUnsignedLong & count);
                    NLocalisationPortion(const NLocalisationPortion & other);
                    NLocalisationPortion(const _NLocalisationPortion & from);
                    virtual ~NLocalisationPortion();
                    virtual void setFrom(const NUnsignedLong & from);
                    virtual const NUnsignedLong & getFrom();
                    virtual void setCount(const NUnsignedLong & to);
                    virtual const NUnsignedLong & getCount();
                    virtual void toStruct(_NLocalisationPortion & input);
                };
            }
        }
    }
}


#endif //NWEBMEDIA_NLOCALISATIONPORTION_H
