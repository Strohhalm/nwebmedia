//
// Created by strohhalm on 16.07.15.
//

#include "NLocalisationEntry.h"

namespace nox
{
    namespace service
    {
        namespace exchange
        {
            namespace infra
            {
                NLocalisationEntry::NLocalisationEntry()
                {
                    m_Name = new NString();
                    m_Locale = new NString();
                    m_Text = new NString();
                }

                NLocalisationEntry::NLocalisationEntry(const NString & name, const NString & locale, const NString & text)
                {
                    m_Name = new NString(name);
                    m_Locale = new NString(locale);
                    m_Text = new NString(text);
                }

                NLocalisationEntry::NLocalisationEntry(const NLocalisationEntry & other)
                {
                    m_Name = new NString(*other.m_Name);
                    m_Locale = new NString(*other.m_Locale);
                    m_Text = new NString(*other.m_Text);
                }

                NLocalisationEntry::NLocalisationEntry(const _NLocalisationEntry & from)
                {
                    m_Name = new NString(from.Name);
                    m_Locale = new NString(from.Locale);
                    m_Text = new NString(from.Text);
                }

                NLocalisationEntry::~NLocalisationEntry()
                {
                    if (m_Name != NULL)
                        delete m_Name;
                    if (m_Locale != NULL)
                        delete m_Locale;
                    if (m_Text != NULL)
                        delete m_Text;
                }

                void NLocalisationEntry::setName(const NString & name)
                {
                    m_Name->assign(name);
                }

                const NString & NLocalisationEntry::getName()
                {
                    return *m_Name;
                }

                void NLocalisationEntry::setLocale(const NString & locale)
                {
                    m_Locale->assign(locale);
                }

                const NString & NLocalisationEntry::getLocale()
                {
                    return *m_Locale;
                }

                void NLocalisationEntry::setText(const NString & text)
                {
                    m_Text->assign(text);
                }

                const NString & NLocalisationEntry::getText()
                {
                    return *m_Text;
                }

                void NLocalisationEntry::toStruct(_NLocalisationEntry & input)
                {
                    memset(&input, 0, sizeof(_NLocalisationEntry));

                    getName().copy(input.Name, getName().length());
                    getLocale().copy(input.Locale, getLocale().length());
                    getText().copy(input.Text, getText().length());
                }
            }
        }
    }
}