//
// Created by strohhalm on 30.05.15.
//

#include "NSecUserModel.h"

namespace nox
{
    namespace security
    {
        namespace model
        {
            NSecUserModel::NSecUserModel() : INValidTimeModel("NOX_SEC_USER")
            {
                CreateModelColumn(ID, NInteger)
                CreateModelColumn(USER_NAME, NString)
                CreateModelColumn(PASSWORD, NString)
                CreateModelColumn(FIRST_NAME, NString)
                CreateModelColumn(LAST_NAME, NString)
                CreateModelColumn(EMAIL, NString)
            }

            NSecUserModel::~NSecUserModel()
            {
            }

            DefineModelValueFunction(NSecUserModel, ID, Id, NInteger)
            DefineModelValueFunction(NSecUserModel, USER_NAME, UserName, NString)
            DefineModelValueFunction(NSecUserModel, PASSWORD, Password, NString)
            DefineModelValueFunction(NSecUserModel, FIRST_NAME, FirstName, NString)
            DefineModelValueFunction(NSecUserModel, LAST_NAME, LastName, NString)
            DefineModelValueFunction(NSecUserModel, EMAIL, EMail, NString)

            nint NSecUserModel::compareTo(const INObject * other) const
            {
                if (this == other)
                    return 0;
                try
                {
                    nint result = INValidTimeModel::compareTo(other);

                    if (result == 0)
                    {
                        const NSecUserModel * obj = dynamic_cast<const NSecUserModel *>(other);

                        if (obj != NULL)
                        {
                            if ((result = compare(getId(), obj->getId())) == 0)
                            {
                                if ((result = compare(getUserName(), obj->getUserName())) == 0)
                                {
                                    if ((result = compare(getPassword(), obj->getPassword())) == 0)
                                    {
                                        if ((result = compare(getFirstName(), obj->getFirstName())) == 0)
                                        {
                                            if ((result = compare(getLastName(), obj->getLastName())) == 0)
                                            {
                                                result = compare(getEMail(), obj->getEMail());
                                            }
                                        }
                                    }
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