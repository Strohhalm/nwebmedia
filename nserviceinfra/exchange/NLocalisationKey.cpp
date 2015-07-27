//
// Created by strohhalm on 16.07.15.
//

#include "NLocalisationKey.h"

namespace nox
{
    namespace service
    {
        namespace exchange
        {
            namespace infra
            {
                NLocalisationKey::NLocalisationKey()
                {
                    m_Name = new NString();
                    m_Locale = new NString();
                }

                NLocalisationKey::NLocalisationKey(const NString & name, const NString & locale)
                {
                    m_Name = new NString(name);
                    m_Locale = new NString(locale);
                }

                NLocalisationKey::NLocalisationKey(const NLocalisationKey & other)
                {
                    m_Name = new NString(*other.m_Name);
                    m_Locale = new NString(*other.m_Locale);
                }

                NLocalisationKey::NLocalisationKey(const _NLocalisationKey & from)
                {
                    m_Name = new NString(from.Name);
                    m_Locale = new NString(from.Locale);
                }

                NLocalisationKey::~NLocalisationKey()
                {
                    if (m_Name != NULL)
                        delete m_Name;
                    if (m_Locale != NULL)
                        delete m_Locale;
                }

                void NLocalisationKey::setName(const NString & name)
                {
                    m_Name->assign(name);
                }

                const NString & NLocalisationKey::getName()
                {
                    return *m_Name;
                }

                void NLocalisationKey::setLocale(const NString & locale)
                {
                    m_Locale->assign(locale);
                }

                const NString & NLocalisationKey::getLocale()
                {
                    return *m_Locale;
                }

                void NLocalisationKey::toStruct(_NLocalisationKey & input)
                {
                    memset(&input, 0, sizeof(_NLocalisationKey));

                    getName().copy(input.Name, getName().length());
                    getLocale().copy(input.Locale, getLocale().length());
                }
            }
        }
    }
}
