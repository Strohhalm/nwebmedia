//
// Created by strohhalm on 16.07.15.
//

#ifndef NWEBMEDIA_NLOCALISATIONENTRY_H
#define NWEBMEDIA_NLOCALISATIONENTRY_H

#include <nbase/NTypes.h>

namespace nox
{
    namespace service
    {
        namespace exchange
        {
            namespace infra
            {
                struct _NLocalisationEntry
                {
                    nchar Name[255];
                    nchar Locale[6];
                    nchar Text[255];
                };

                class NLocalisationEntry
                {
                protected:
                    NString * m_Name;
                    NString * m_Locale;
                    NString * m_Text;
                public:
                    NLocalisationEntry();
                    NLocalisationEntry(const NString & name, const NString & locale, const NString & text);
                    NLocalisationEntry(const NLocalisationEntry & other);
                    NLocalisationEntry(const _NLocalisationEntry & from);
                    virtual ~NLocalisationEntry();
                    virtual void setName(const NString & name);
                    virtual const NString & getName();
                    virtual void setLocale(const NString & locale);
                    virtual const NString & getLocale();
                    virtual void setText(const NString & text);
                    virtual const NString & getText();
                    virtual void toStruct(_NLocalisationEntry & input);
                };
            }
        }
    }
}


#endif //NWEBMEDIA_NLOCALISATIONENTRY_H
