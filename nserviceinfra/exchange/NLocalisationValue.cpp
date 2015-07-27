//
// Created by strohhalm on 16.07.15.
//

#include "NLocalisationValue.h"

namespace nox
{
    namespace service
    {
        namespace exchange
        {
            namespace infra
            {
                NLocalisationValue::NLocalisationValue()
                {
                    m_Text = new NString();
                }

                NLocalisationValue::NLocalisationValue(const NString & text)
                {
                    m_Text = new NString(text);
                }

                NLocalisationValue::NLocalisationValue(const NLocalisationValue & other)
                {
                    m_Text = new NString(*other.m_Text);
                }

                NLocalisationValue::NLocalisationValue(const _NLocalisationValue & from)
                {
                    m_Text = new NString(from.Text);
                }

                NLocalisationValue::~NLocalisationValue()
                {
                    if (m_Text != NULL)
                        delete m_Text;
                }

                void NLocalisationValue::setText(const NString & text)
                {
                    m_Text->assign(text);
                }

                const NString & NLocalisationValue::getText()
                {
                    return *m_Text;
                }

                void NLocalisationValue::toStruct(_NLocalisationValue & input)
                {
                    memset(&input, 0, sizeof(_NLocalisationValue));

                    getText().copy(input.Text, getText().length());
                }
            }
        }
    }
}