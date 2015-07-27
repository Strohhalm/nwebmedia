//
// Created by strohhalm on 25.07.15.
//

#ifndef NWEBMEDIA_NUSERDATA_H
#define NWEBMEDIA_NUSERDATA_H

#include <nbase/NBaseType.h>

namespace nox
{
    namespace service
    {
        namespace exchange
        {
            namespace security
            {
                struct _NUserData
                {
                    nint  Id;
                    ndate ValidFrom;
                    ndate ValidTo;
                    nchar Username[50];
                    nchar Password[50];
                    nchar FirstName[50];
                    nchar LastName[50];
                    nchar Email[50];
                    nbool Active;
                };

                class NUserData
                {
                protected:
                    NInteger* m_Id;
                    NDate   * m_ValidFrom;
                    NDate   * m_ValidTo;
                    NString * m_Username;
                    NString * m_Password;
                    NString * m_FirstName;
                    NString * m_LastName;
                    NString * m_Email;
                    NBool   * m_Active;
                public:
                    NUserData();
                    NUserData(const NInteger & id, const NDate & validFrom, const NDate & validTo, const NString & username, const NString & password, const NString & firstName, const NString & lastName, const NString & email, const NBool & active);
                    NUserData(const NUserData & other);
                    NUserData(const _NUserData & from);
                    virtual ~NUserData();
                    virtual void setId(const NInteger & id);
                    virtual const NInteger & getId();
                    virtual void setValidFrom(const NDate & validFrom);
                    virtual const NDate & getValidFrom();
                    virtual void setValidTo(const NDate & validTo);
                    virtual const NDate & getValidTo();
                    virtual void setUsername(const NString & username);
                    virtual const NString & getUsername();
                    virtual void setPassword(const NString & password);
                    virtual const NString & getPassword();
                    virtual void setFirstName(const NString & firstName);
                    virtual const NString & getFirstName();
                    virtual void setLastName(const NString & lastName);
                    virtual const NString & getLastName();
                    virtual void setEmail(const NString & email);
                    virtual const NString & getEmail();
                    virtual void setActive(const NBool & active);
                    virtual const NBool & isActive();
                    virtual void toStruct(_NUserData & input);
                };
            }
        }
    }
}


#endif //NWEBMEDIA_NUSERDATA_H
