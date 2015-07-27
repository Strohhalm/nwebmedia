//
// Created by strohhalm on 25.07.15.
//

#ifndef NWEBMEDIA_NINFKEYSMODELACCESS_H
#define NWEBMEDIA_NINFKEYSMODELACCESS_H

#include <nmodel/INModelAccess.h>
#include <nserviceinfra/NServiceInfra.h>
#include <nserviceinfra/model/NInfKeysModel.h>

using namespace nox::model;

namespace nox
{
    namespace infra
    {
        namespace model
        {
            class NInfKeysModelAccess : public INModelAccess
            {
            public:
                NInfKeysModelAccess();
                virtual ~NInfKeysModelAccess();
                virtual void insert(const NInfKeysModel & model);
                virtual void update(const NInfKeysModel & model);
                virtual INTypedResultSet<NInfKeysModel> * read(const NString & keyClass, const NString & component);
                virtual nint compareTo(const INObject * other) const;
            };
        }
    }
}

#endif //NWEBMEDIA_NINFKEYSMODELACCESS_H
