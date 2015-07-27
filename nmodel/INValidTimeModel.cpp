//
// Created by strohhalm on 04.06.15.
//

#include "INValidTimeModel.h"

namespace nox
{
    namespace model
    {
        INValidTimeModel::INValidTimeModel(const NString &tableName) : INModel(tableName)
        {
            CreateModelColumn(VALID_FROM, NDate)
            CreateModelColumn(VALID_TO, NDate)
            CreateModelColumn(ACTIVE, NBool)
        }

        INValidTimeModel::INValidTimeModel(const INValidTimeModel & other) : INModel(other)
        {
            CreateModelColumn(VALID_FROM, NDate)
            CreateModelColumn(VALID_TO, NDate)
            CreateModelColumn(ACTIVE, NBool)

            if (other.getValidFrom() != NULL)
                setValidFrom(new NDate(*other.getValidFrom()));
            if (other.getValidTo() != NULL)
                setValidTo(new NDate(*other.getValidTo()));
            if (other.getActive() != NULL)
                setActive(new NBool(*other.getActive()));
        }

        INValidTimeModel::~INValidTimeModel()
        {

        }

        DefineModelValueFunction(INValidTimeModel, VALID_FROM, ValidFrom, NDate)
        DefineModelValueFunction(INValidTimeModel, VALID_TO, ValidTo, NDate)
        DefineModelValueFunction(INValidTimeModel, ACTIVE, Active, NBool)

        nint INValidTimeModel::compareTo(const INObject * other) const
        {
            if (this == other)
                return 0;
            try
            {
                const INValidTimeModel * obj = dynamic_cast<const INValidTimeModel *>(other);

                if (obj != NULL)
                {
                    nint result = 0;
                    if ((result = compare(getValidFrom(), obj->getValidFrom())) == 0)
                    {
                        if ((result = compare(getValidTo(), obj->getValidTo())) == 0)
                        {
                            result = compare(getActive(), obj->getActive());
                        }
                    }
                    return result;
                }
                else
                {
                    return 1;
                }
            }
            catch (bad_cast &)
            {
                return 1;
            }
        }
    }
}