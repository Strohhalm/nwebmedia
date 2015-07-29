//
// Created by strohhalm on 24.07.15.
//

#ifndef NWEBMEDIA_NINFKEYSMODEL_H
#define NWEBMEDIA_NINFKEYSMODEL_H

#include <nmodel/INModel.h>

using namespace nox::model;

namespace nox
{
    namespace infra
    {
        namespace model
        {
            class NInfKeysModel : public INModel
            {
            public:
                DeclareModelValueFunction(KEY_CLASS, KeyClass, NString)
                DeclareModelValueFunction(COMPONENT, Component, NString)
                DeclareModelValueFunction(KEY_VALUE, KeyValue, NLong)
            public:
                NInfKeysModel();
                NInfKeysModel(const NInfKeysModel & other);
                virtual ~NInfKeysModel();
                virtual nint compareTo(const INObject * other) const;
            };
        }
    }
}


#endif //NWEBMEDIA_NINFKEYSMODEL_H
