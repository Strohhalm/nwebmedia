//
// Created by strohhalm on 25.07.15.
//

#include "NReadUserByNameParam.h"

namespace nox
{
    namespace service
    {
        namespace exchange
        {
            namespace security
            {
                NReadUserByNameParam::NReadUserByNameParam()
                {
                    m_Username = new NString();
                    m_DueDate = new NDate();
                    m_State = BOTH;
                }

                NReadUserByNameParam::NReadUserByNameParam(const NString & username, const NDate & dueDate, const nstate state)
                {
                    m_Username = new NString(username);
                    m_DueDate = new NDate(dueDate);
                    m_State = state;
                }

                NReadUserByNameParam::NReadUserByNameParam(const NReadUserByNameParam & other)
                {
                    m_Username = new NString(*other.m_Username);
                    m_DueDate = new NDate(*other.m_DueDate);
                    m_State = other.m_State;
                }

                NReadUserByNameParam::NReadUserByNameParam(const _NReadUserByNameParam & from)
                {
                    m_Username = new NString(from.Username);
                    m_DueDate = new NDate(from.DueDate);
                    m_State = from.State;
                }

                NReadUserByNameParam::~NReadUserByNameParam()
                {
                    if (m_Username != NULL)
                        delete m_Username;
                    if (m_DueDate != NULL)
                        delete m_DueDate;
                }

                void NReadUserByNameParam::setUsername(const NString & username)
                {
                    m_Username->assign(username);
                }

                const NString & NReadUserByNameParam::getUsername()
                {
                    return *m_Username;
                }

                void NReadUserByNameParam::setDueDate(const NDate & dueDate)
                {
                    m_DueDate->set(dueDate);
                }

                const NDate & NReadUserByNameParam::getDueDate()
                {
                    return *m_DueDate;
                }

                void NReadUserByNameParam::setState(const nstate state)
                {
                    m_State = state;
                }

                const nstate NReadUserByNameParam::getState()
                {
                    return m_State;
                }

                void NReadUserByNameParam::toStruct(_NReadUserByNameParam & input)
                {
                    memset(&input, 0, sizeof(_NReadUserByNameParam));

                    getUsername().copy(input.Username, getUsername().length());
                    getDueDate().copy(input.DueDate);
                    input.State = getState();
                }
            }
        }
    }
}
