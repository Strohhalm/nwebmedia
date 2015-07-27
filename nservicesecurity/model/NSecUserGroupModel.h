//
// Created by strohhalm on 04.06.15.
//

#ifndef NSECUSERGROUPMODEL_H
#define NSECUSERGROUPMODEL_H

#include <nservicesecurity/NServiceSecurity.h>
#include <nmodel/INValidTimeModel.h>

using namespace nox::model;

namespace nox
{
    namespace security
    {
        namespace model
        {
            class NSecUserGroupModel : public INValidTimeModel
            {
                friend class NSecUserGroupModelAccess;
            public:
                DeclareModelValueFunction(USER_ID, UserId, NInteger)
                DeclareModelValueFunction(GROUP_ID, GroupId, NInteger)
            public:
                NSecUserGroupModel();
                virtual ~NSecUserGroupModel();
                virtual nint compareTo(INObject * other);
            };
        }
    }
}

#endif //NSECUSERGROUPMODEL_H
