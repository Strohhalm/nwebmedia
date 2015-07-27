//
// Created by strohhalm on 25.07.15.
//

#include "NUserData.h"

namespace nox
{
    namespace service
    {
        namespace exchange
        {
            namespace security
            {
                NUserData::NUserData()
                {
                    m_Id = new NInteger();
                    m_ValidFrom = new NDate();
                    m_ValidTo = new NDate();
                    m_Username = new NString();
                    m_Password = new NString();
                    m_FirstName = new NString();
                    m_LastName = new NString();
                    m_Email = new NString();
                    m_Active = new NBool();
                }

                NUserData::NUserData(const NInteger & id, const NDate & validFrom, const NDate & validTo, const NString & username, const NString & password, const NString & firstName, const NString & lastName, const NString & email, const NBool & active)
                {
                    m_Id = new NInteger(id);
                    m_ValidFrom = new NDate(validFrom);
                    m_ValidTo = new NDate(validTo);
                    m_Username = new NString(username);
                    m_Password = new NString(password);
                    m_FirstName = new NString(firstName);
                    m_LastName = new NString(lastName);
                    m_Email = new NString(email);
                    m_Active = new NBool(active);
                }

                NUserData::NUserData(const NUserData & other)
                {
                    m_Id = new NInteger(*other.m_Id);
                    m_ValidFrom = new NDate(*other.m_ValidFrom);
                    m_ValidTo = new NDate(*other.m_ValidTo);
                    m_Username = new NString(*other.m_Username);
                    m_Password = new NString(*other.m_Password);
                    m_FirstName = new NString(*other.m_FirstName);
                    m_LastName = new NString(*other.m_LastName);
                    m_Email = new NString(*other.m_Email);
                    m_Active = new NBool(*other.m_Active);
                }

                NUserData::NUserData(const _NUserData & from)
                {
                    m_Id = new NInteger(from.Id);
                    m_ValidFrom = new NDate(from.ValidFrom);
                    m_ValidTo = new NDate(from.ValidTo);
                    m_Username = new NString(from.Username);
                    m_Password = new NString(from.Password);
                    m_FirstName = new NString(from.FirstName);
                    m_LastName = new NString(from.LastName);
                    m_Email = new NString(from.Email);
                    m_Active = new NBool(from.Active);
                }

                NUserData::~NUserData()
                {
                    if (m_Id != NULL)
                        delete m_Id;
                    if (m_ValidFrom != NULL)
                        delete m_ValidFrom;
                    if (m_ValidTo != NULL)
                        delete m_ValidTo;
                    if (m_Username != NULL)
                        delete m_Username;
                    if (m_Password != NULL)
                        delete m_Password;
                    if (m_FirstName != NULL)
                        delete m_FirstName;
                    if (m_LastName != NULL)
                        delete m_LastName;
                    if (m_Email != NULL)
                        delete m_Email;
                    if (m_Active != NULL)
                        delete m_Active;
                }

                void NUserData::setId(const NInteger & id)
                {
                    m_Id->setValue(id);
                }

                const NInteger & NUserData::getId()
                {
                    return *m_Id;
                }

                void NUserData::setValidFrom(const NDate & validFrom)
                {
                    if (m_ValidFrom != NULL)
                        delete m_ValidFrom;
                    m_ValidFrom = new NDate(validFrom);
                }

                const NDate & NUserData::getValidFrom()
                {
                    return *m_ValidFrom;
                }

                void NUserData::setValidTo(const NDate & validTo)
                {
                    if (m_ValidTo != NULL)
                        delete m_ValidTo;
                    m_ValidTo = new NDate(validTo);
                }

                const NDate & NUserData::getValidTo()
                {
                    return *m_ValidTo;
                }

                void NUserData::setUsername(const NString & username)
                {
                    m_Username->assign(username);
                }

                const NString & NUserData::getUsername()
                {
                    return *m_Username;
                }

                void NUserData::setPassword(const NString & password)
                {
                    m_Password->assign(password);
                }

                const NString & NUserData::getPassword()
                {
                    return *m_Password;
                }

                void NUserData::setFirstName(const NString & firstName)
                {
                    m_FirstName->assign(firstName);
                }

                const NString & NUserData::getFirstName()
                {
                    return *m_FirstName;
                }

                void NUserData::setLastName(const NString & lastName)
                {
                    m_LastName->assign(lastName);
                }

                const NString & NUserData::getLastName()
                {
                    return *m_LastName;
                }

                void NUserData::setEmail(const NString & email)
                {
                    m_Email->assign(email);
                }

                const NString & NUserData::getEmail()
                {
                    return *m_Email;
                }

                void NUserData::setActive(const NBool & active)
                {
                    m_Active->setValue(active);
                }

                const NBool & NUserData::isActive()
                {
                    return *m_Active;
                }

                void NUserData::toStruct(_NUserData & input)
                {
                    memset(&input, 0, sizeof(_NUserData));

                    input.Id = getId().getValue();
                    getValidFrom().copy(input.ValidFrom);
                    getValidTo().copy(input.ValidTo);
                    getUsername().copy(input.Username, getUsername().length());
                    getPassword().copy(input.Password, getPassword().length());
                    getFirstName().copy(input.FirstName, getPassword().length());
                    getLastName().copy(input.LastName, getLastName().length());
                    getEmail().copy(input.Email, getEmail().length());
                    input.Active = isActive().getValue();
                }
            }
        }
    }
}