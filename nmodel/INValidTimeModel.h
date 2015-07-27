//
// Created by strohhalm on 04.06.15.
//

#ifndef INVALIDTIMEMODEL_H
#define INVALIDTIMEMODEL_H

#include <nmodel/INModel.h>

namespace nox
{
    namespace model
    {
        class INValidTimeModel : public INModel
        {
        public:
            DeclareModelValueFunction(VALID_FROM, ValidFrom, NDate)
            DeclareModelValueFunction(VALID_TO, ValidTo, NDate)
            DeclareModelValueFunction(ACTIVE, Active, NBool)
        public:
            INValidTimeModel(const NString & tableName);
            INValidTimeModel(const INValidTimeModel & other);
            virtual ~INValidTimeModel();
            virtual nint compareTo(const INObject * other) const;
        };
    }
}

#endif //INVALIDTIMEMODEL_H
