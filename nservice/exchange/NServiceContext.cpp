//
// Created by strohhalm on 16.07.15.
//

#include "NServiceContext.h"

namespace nox
{
    namespace service
    {
        namespace exchange
        {
            NServiceContext::NServiceContext()
            {
                m_Locale = new NString();
                m_UserId = new NInteger();
            }

            NServiceContext::NServiceContext(const NInteger & userId, const NString & locale)
            {
                m_Locale = new NString(locale);
                m_UserId = new NInteger(userId);
            }

            NServiceContext::NServiceContext(const NServiceContext & other)
            {
                m_Locale = new NString(*other.m_Locale);
                m_UserId = new NInteger(*other.m_UserId);
            }

            NServiceContext::NServiceContext(const _NServiceContext & from)
            {
                m_Locale = new NString(from.Locale);
                m_UserId = new NInteger(from.UserId);
            }

            NServiceContext::~NServiceContext()
            {
                if (m_Locale != NULL)
                    delete m_Locale;
                if (m_UserId != NULL)
                    delete m_UserId;
            }

            void NServiceContext::setLocale(const NString & locale)
            {
                m_Locale->assign(locale);
            }

            const NString & NServiceContext::getLocale()
            {
                return *m_Locale;
            }

            void NServiceContext::setUserId(const NInteger & userId)
            {
                m_UserId->setValue(userId);
            }

            const NInteger & NServiceContext::getUserId()
            {
                return *m_UserId;
            }

            void NServiceContext::toStruct(_NServiceContext & input)
            {
                memset(&input, 0, sizeof(_NServiceContext));

                getLocale().copy(input.Locale, getLocale().length());
                input.UserId = getUserId().getValue();
            }
        }
    }
}