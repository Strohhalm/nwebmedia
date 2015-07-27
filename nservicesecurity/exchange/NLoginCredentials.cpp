//
// Created by strohhalm on 16.07.15.
//

#include "NLoginCredentials.h"

namespace nox
{
    namespace service
    {
        namespace exchange
        {
            namespace security
            {
                NLoginCredentials::NLoginCredentials()
                {
                    m_Username = new NString();
                    m_Password = new NString();
                }

                NLoginCredentials::NLoginCredentials(const NString & username, const NString & password)
                {
                    m_Username = new NString(username);
                    m_Password = new NString(password);
                }

                NLoginCredentials::NLoginCredentials(const NLoginCredentials & other)
                {
                    m_Username = new NString(*other.m_Username);
                    m_Password = new NString(*other.m_Password);
                }

                NLoginCredentials::NLoginCredentials(const _NLoginCredentials & from)
                {
                    m_Username = new NString(from.Username);
                    m_Password = new NString(from.Password);
                }

                NLoginCredentials::~NLoginCredentials()
                {
                    if (m_Username != NULL)
                        delete m_Username;
                    if (m_Password != NULL)
                        delete m_Password;
                }

                void NLoginCredentials::setUsername(const NString & username)
                {
                    m_Username->assign(username);
                }

                const NString & NLoginCredentials::getUsername()
                {
                    return *m_Username;
                }

                void NLoginCredentials::setPassword(const NString & password)
                {
                    m_Password->assign(password);
                }

                const NString & NLoginCredentials::getPassword()
                {
                    return *m_Password;
                }

                void NLoginCredentials::toStruct(_NLoginCredentials & input)
                {
                    memset(&input, 0, sizeof(_NLoginCredentials));

                    getUsername().copy(input.Username, getUsername().length());
                    getPassword().copy(input.Password, getPassword().length());
                }
            }
        }
    }
}