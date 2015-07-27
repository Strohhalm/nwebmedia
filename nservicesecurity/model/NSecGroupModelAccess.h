//
// Created by strohhalm on 10.06.15.
//

#ifndef NSECGROUPMODELACCESS_H
#define NSECGROUPMODELACCESS_H

#include <nmodel/INModelAccess.h>
#include <nservicesecurity/model/NSecGroupModel.h>

using namespace nox::model;

namespace nox
{
    namespace security
    {
        namespace model
        {
            class NSecGroupModelAccess : public INModelAccess
            {
            public:
                NSecGroupModelAccess();
                virtual ~NSecGroupModelAccess();
                virtual void insert(NSecGroupModel * model);
                virtual void update(NSecGroupModel * model);
                virtual INTypedResultSet<NSecGroupModel> * read(NInteger * groupId);
                virtual INTypedResultSet<NSecGroupModel> * readGroupByName(NString * groupname, NBool * active, NDate * dueDate);
                virtual INTypedResultSet<NSecGroupModel> * readGroupByUserName(NString * username, NBool * active, NDate * dueDate);
            };
        }
    }
}

#endif //NSECGROUPMODELACCESS_H
