//
// Created by strohhalm on 16.07.15.
//

#include "NLoginCredentialsOk.h"

namespace nox
{
    namespace service
    {
        namespace exchange
        {
            namespace security
            {
                NLoginCredentialsOk::NLoginCredentialsOk()
                {
                    m_UserId = new NInteger();
                    m_Ok     = new NBool();
                }

                NLoginCredentialsOk::NLoginCredentialsOk(const NInteger & userId, const NBool & ok)
                {
                    m_UserId = new NInteger(userId);
                    m_Ok = new NBool(ok);
                }

                NLoginCredentialsOk::NLoginCredentialsOk(const NLoginCredentialsOk & other)
                {
                    m_UserId = new NInteger(*other.m_UserId);
                    m_Ok     = new NBool(*other.m_Ok);
                }

                NLoginCredentialsOk::NLoginCredentialsOk(const _NLoginCredentialsOk & from)
                {
                    m_UserId = new NInteger(from.UserId);
                    m_Ok     = new NBool(from.Ok);
                }

                NLoginCredentialsOk::~NLoginCredentialsOk()
                {
                    if (m_UserId != NULL)
                        delete m_UserId;
                    if (m_Ok != NULL)
                        delete m_Ok;
                }

                void NLoginCredentialsOk::setUserId(const NInteger & userId)
                {
                    m_UserId->setValue(userId);
                }

                const NInteger & NLoginCredentialsOk::getUserId()
                {
                    return *m_UserId;
                }

                void NLoginCredentialsOk::setOk(const NBool & ok)
                {
                    m_Ok->setValue(ok);
                }

                const NBool & NLoginCredentialsOk::isOk()
                {
                    return *m_Ok;
                }

                void NLoginCredentialsOk::toStruct(_NLoginCredentialsOk & input)
                {
                    memset(&input, 0, sizeof(_NLoginCredentialsOk));

                    input.UserId = getUserId().getValue();
                    input.Ok     = isOk().getValue();
                }
            }
        }
    }
}