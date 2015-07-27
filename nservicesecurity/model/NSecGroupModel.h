//
// Created by strohhalm on 04.06.15.
//

#ifndef NSECGROUPMODEL_H
#define NSECGROUPMODEL_H

#include <nservicesecurity/NServiceSecurity.h>
#include <nmodel/INValidTimeModel.h>

using namespace nox::model;

namespace nox
{
    namespace security
    {
        namespace model
        {
            class NSecGroupModel : public INValidTimeModel
            {
            public:
                DeclareModelValueFunction(ID, Id, NInteger)
                DeclareModelValueFunction(GROUP_NAME, GroupName, NString)
                DeclareModelValueFunction(DESCRIPTION, GroupDescription, NString)
            public:
                NSecGroupModel();
                NSecGroupModel(const NSecGroupModel & other);
                virtual ~NSecGroupModel();
                virtual nint compareTo(INObject * other);
            };
        }
    }
}

#endif //NSECGROUPMODEL_H
