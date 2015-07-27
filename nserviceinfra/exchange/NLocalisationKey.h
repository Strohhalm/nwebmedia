//
// Created by strohhalm on 16.07.15.
//

#ifndef NWEBMEDIA_NLOCALISATIONKEY_H
#define NWEBMEDIA_NLOCALISATIONKEY_H

#include <nbase/NBase.h>

namespace nox
{
    namespace service
    {
        namespace exchange
        {
            namespace infra
            {
                struct _NLocalisationKey
                {
                    nchar Name[255];
                    nchar Locale[6];
                };

                class NLocalisationKey
                {
                protected:
                    NString * m_Name;
                    NString * m_Locale;
                public:
                    NLocalisationKey();
                    NLocalisationKey(const NString & name, const NString & locale);
                    NLocalisationKey(const NLocalisationKey & other);
                    NLocalisationKey(const _NLocalisationKey & from);
                    virtual ~NLocalisationKey();
                    virtual void setName(const NString & name);
                    virtual const NString & getName();
                    virtual void setLocale(const NString & locale);
                    virtual const NString & getLocale();
                    virtual void toStruct(_NLocalisationKey & input);
                };
            }
        }
    }
}


#endif //NWEBMEDIA_NLOCALISATIONKEY_H
