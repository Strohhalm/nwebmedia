//
// Created by strohhalm on 30.05.15.
//

#ifndef NSECUSERMODEL_H
#define NSECUSERMODEL_H

#include <nservicesecurity/NServiceSecurity.h>
#include <nmodel/INValidTimeModel.h>

using namespace nox::model;

namespace nox
{
    namespace security
    {
        namespace model
        {
            class NSecUserModel : public INValidTimeModel
            {
                friend class NSecUserModelAccess;
            public:
                DeclareModelValueFunction(ID, Id, NInteger)
                DeclareModelValueFunction(USER_NAME, UserName, NString)
                DeclareModelValueFunction(PASSWORD, Password, NString)
                DeclareModelValueFunction(FIRST_NAME, FirstName, NString)
                DeclareModelValueFunction(LAST_NAME, LastName, NString)
                DeclareModelValueFunction(EMAIL, EMail, NString)
            public:
                NSecUserModel();
                virtual ~NSecUserModel();
                virtual nint compareTo(const INObject * other) const;
            };
        }
    }
}

#endif //NSECUSERMODEL_H

