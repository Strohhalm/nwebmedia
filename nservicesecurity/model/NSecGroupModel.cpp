//
// Created by strohhalm on 04.06.15.
//

#include "NSecGroupModel.h"

namespace nox
{
    namespace security
    {
        namespace model
        {
            NSecGroupModel::NSecGroupModel() : INValidTimeModel("NOX_SEC_GROUP")
            {
                CreateModelColumn(ID, NInteger)
                CreateModelColumn(GROUP_NAME, NString)
                CreateModelColumn(DESCRIPTION, NString)
            }

            NSecGroupModel::NSecGroupModel(const NSecGroupModel & other) : INValidTimeModel(other)
            {
                CreateModelColumn(ID, NInteger)
                CreateModelColumn(GROUP_NAME, NString)
                CreateModelColumn(DESCRIPTION, NString)

                if (other.getId() != NULL)
                    setId(new NInteger(*other.getId()));
                if (other.getGroupName() != NULL)
                    setGroupName(new NString(*other.getGroupName()));
                if (other.getGroupDescription() != NULL)
                    setGroupDescription(new NString(*other.getGroupDescription()));
            }

            NSecGroupModel::~NSecGroupModel()
            {
            }

            DefineModelValueFunction(NSecGroupModel, ID, Id, NInteger)
            DefineModelValueFunction(NSecGroupModel, GROUP_NAME, GroupName, NString)
            DefineModelValueFunction(NSecGroupModel, DESCRIPTION, GroupDescription, NString)

            nint NSecGroupModel::compareTo(INObject * other)
            {
                if (this == other)
                    return 0;
                try
                {
                    nint result = INValidTimeModel::compareTo(other);

                    if (result == 0)
                    {
                        NSecGroupModel * obj = dynamic_cast<NSecGroupModel *>(other);

                        if (obj != NULL)
                        {
                            if ((result = compare(getId(), obj->getId())) == 0)
                            {
                                if ((result = compare(getGroupName(), obj->getGroupName())) == 0)
                                {
                                    result = compare(getGroupDescription(), obj->getGroupDescription());
                                }
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