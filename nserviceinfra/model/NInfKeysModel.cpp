//
// Created by strohhalm on 24.07.15.
//

#include "NInfKeysModel.h"

namespace nox
{
    namespace infra
    {
        namespace model
        {
            NInfKeysModel::NInfKeysModel() : INModel("NOX_INF_KEYS")
            {
                CreateModelColumn(KEY_CLASS, NString)
                CreateModelColumn(COMPONENT, NString)
                CreateModelColumn(KEY_VALUE, NLong)
            }

            NInfKeysModel::NInfKeysModel(const NInfKeysModel & other) : INModel(other)
            {
                CreateModelColumn(KEY_CLASS, NString)
                CreateModelColumn(COMPONENT, NString)
                CreateModelColumn(KEY_VALUE, NLong)

                if (other.getKeyClass() != NULL)
                    setKeyClass(new NString(*other.getKeyClass()));
                if (other.getComponent() != NULL)
                    setComponent(new NString(*other.getComponent()));
                if (other.getKeyValue() != NULL)
                    setKeyValue(new NLong(*other.getKeyValue()));
            }

            NInfKeysModel::~NInfKeysModel()
            {
            }

            DefineModelValueFunction(NInfKeysModel, KEY_CLASS, KeyClass, NString)
            DefineModelValueFunction(NInfKeysModel, COMPONENT, Component, NString)
            DefineModelValueFunction(NInfKeysModel, KEY_VALUE, KeyValue, NLong)

            nint NInfKeysModel::compareTo(const INObject * other) const
            {
                if (this == other)
                    return 0;
                try
                {
                    const NInfKeysModel * obj = dynamic_cast<const NInfKeysModel *>(other);

                    if (obj != NULL)
                    {
                        nint result = 0;
                        if ((result = compare(getKeyClass(), obj->getKeyClass())) == 0)
                        {
                            if ((result = compare(getComponent(), obj->getComponent())) == 0)
                            {
                                result = compare(getKeyValue(), obj->getKeyValue());
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
                    return -1;
                }
            }
        }
    }
}