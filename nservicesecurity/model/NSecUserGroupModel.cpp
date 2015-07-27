//
// Created by strohhalm on 04.06.15.
//

#include "NSecUserGroupModel.h"

namespace nox
{
    namespace security
    {
        namespace model
        {
            NSecUserGroupModel::NSecUserGroupModel() : INValidTimeModel("NOX_SEC_USR_GRP")
            {
                CreateModelColumn(USER_ID, NInteger)
                CreateModelColumn(GROUP_ID, NInteger)
            }

            NSecUserGroupModel::~NSecUserGroupModel()
            {
            }

            DefineModelValueFunction(NSecUserGroupModel, USER_ID, UserId, NInteger)
            DefineModelValueFunction(NSecUserGroupModel, GROUP_ID, GroupId, NInteger)

            nint NSecUserGroupModel::compareTo(INObject * other)
            {
                if (this == other)
                    return 0;
                try
                {
                    nint result = INValidTimeModel::compareTo(other);

                    if (result == 0)
                    {
                        NSecUserGroupModel * obj = dynamic_cast<NSecUserGroupModel *>(other);

                        if (obj != NULL)
                        {
                            if ((result = compare(getUserId(), obj->getUserId())) == 0)
                            {
                                result = compare(getGroupId(), obj->getGroupId());
                            }
                        }
                        else
                        {
                            result = 1;
                        }
                    }
                    return result;
                }
                catch (bad_cast &)
                {
                    return 1;
                }
            }
        }
    }
}