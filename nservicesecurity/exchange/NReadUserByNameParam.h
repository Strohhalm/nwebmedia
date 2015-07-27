//
// Created by strohhalm on 25.07.15.
//

#ifndef NWEBMEDIA_NREADUSERBYNAMEPARAM_H
#define NWEBMEDIA_NREADUSERBYNAMEPARAM_H

#include <nbase/NBaseType.h>

namespace nox
{
    namespace service
    {
        namespace exchange
        {
            namespace security
            {
                enum nstate
                {
                    BOTH = 0,
                    ACTIVE = 1,
                    INACTIVE = 2
                };

                struct _NReadUserByNameParam
                {
                    nchar Username[50];
                    ndate DueDate;
                    nstate State;
                };

                class NReadUserByNameParam
                {
                protected:
                    NString * m_Username;
                    NDate * m_DueDate;
                    nstate  m_State;
                public:
                    NReadUserByNameParam();
                    NReadUserByNameParam(const NString & username, const NDate & dueDate, const nstate state = BOTH);
                    NReadUserByNameParam(const NReadUserByNameParam & other);
                    NReadUserByNameParam(const _NReadUserByNameParam & from);
                    virtual ~NReadUserByNameParam();
                    virtual void setUsername(const NString & username);
                    virtual const NString & getUsername();
                    virtual void setDueDate(const NDate & dueDate);
                    virtual const NDate & getDueDate();
                    virtual void setState(const nstate state);
                    virtual const nstate getState();
                    virtual void toStruct(_NReadUserByNameParam & input);
                };
            }
        }
    }
}


#endif //NWEBMEDIA_NREADUSERBYNAMEPARAM_H
