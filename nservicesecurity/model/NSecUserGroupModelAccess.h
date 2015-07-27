//
// Created by strohhalm on 10.06.15.
//

#ifndef NSECUSERGROUPMODELACCESS_H
#define NSECUSERGROUPMODELACCESS_H

#include <nmodel/INModelAccess.h>
#include <nservicesecurity/model/NSecUserGroupModel.h>

using namespace nox::model;

namespace nox
{
    namespace security
    {
        namespace model
        {
            class NSecUserGroupModelAccess : public INModelAccess
            {
            public:
                NSecUserGroupModelAccess();
                virtual ~NSecUserGroupModelAccess();
                virtual void insert(NSecUserGroupModel * model);
                virtual void update(NSecUserGroupModel * model);
                virtual INTypedResultSet<NSecUserGroupModel> * read(NInteger * userId, NInteger * groupId);
            };
        }
    }
}


#endif //NSECUSERGROUPMODELACCESS_H
