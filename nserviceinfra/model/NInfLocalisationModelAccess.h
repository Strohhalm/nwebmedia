//
// Created by strohhalm on 12.07.15.
//

#ifndef NWEBMEDIA_NINFLOCALISATIONMODELACCESS_H
#define NWEBMEDIA_NINFLOCALISATIONMODELACCESS_H

#include <nmodel/INModelAccess.h>
#include <nserviceinfra/NServiceInfra.h>
#include <nserviceinfra/model/NInfLocalisationModel.h>

using namespace nox::model;

namespace nox
{
    namespace infra
    {
        namespace model
        {
            class NInfLocalisationModelAccess : public INModelAccess
            {
            public:
                NInfLocalisationModelAccess();
                virtual ~NInfLocalisationModelAccess();
                virtual INTypedResultSet<NInfLocalisationModel> * read(const NString & name, const NString & locale);
                virtual INTypedResultSet<NInfLocalisationModel> * readAll(const NUnsignedLong from, const NUnsignedLong count);
                virtual nint compareTo(const INObject * other) const;
            };
        }
    }
}

#endif //NWEBMEDIA_NINFLOCALISATIONMODELACCESS_H
