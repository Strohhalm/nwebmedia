//
// Created by strohhalm on 30.05.15.
//

#ifndef NSECUSERMODELACCESS_H
#define NSECUSERMODELACCESS_H

#include <nservicesecurity/NServiceSecurity.h>
#include <nmodel/INModelAccess.h>
#include "NSecUserModel.h"

using namespace nox::model;

namespace nox
{
    namespace security
    {
        namespace model
        {
            class NSecUserModelAccess : public INModelAccess
            {
            public:
                NSecUserModelAccess();
                virtual ~NSecUserModelAccess();
                virtual void insert(const NSecUserModel & model);
                virtual void update(const NSecUserModel & model);
                virtual INTypedResultSet<NSecUserModel> * read(const NLong & userId);
                virtual INTypedResultSet<NSecUserModel> * readUserByName(const NString & username);
                virtual INTypedResultSet<NSecUserModel> * readUserByName(const NString & username, const NBool & active, const NDate & date);
                virtual INTypedResultSet<NSecUserModel> * readUserByGroupName(const NString & groupname, const NBool & active, const NDate & date, nlong from = 0, nlong count = LONG_MAX);
                virtual nint compareTo(const INObject * other) const;
            };
        }
    }
}

#endif //NSECUSERMODELACCESS_H
