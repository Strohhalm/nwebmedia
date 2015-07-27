//
// Created by strohhalm on 12.07.15.
//

#ifndef NWEBMEDIA_NINFLOCALISATIONMODEL_H
#define NWEBMEDIA_NINFLOCALISATIONMODEL_H

#include <nmodel/INModel.h>

using namespace nox::model;

namespace nox
{
    namespace infra
    {
        namespace model
        {
            class NInfLocalisationModel : public INModel
            {
            public:
                DeclareModelValueFunction(NAME, Name, NString);
                DeclareModelValueFunction(LOCALE, Locale, NString);
                DeclareModelValueFunction(TEXT, Text, NString);
            public:
                NInfLocalisationModel();
                NInfLocalisationModel(const NInfLocalisationModel & other);
                virtual ~NInfLocalisationModel();
                virtual nint compareTo(const INObject * other) const;
            };
        }
    }
}


#endif //NWEBMEDIA_NINFLOCALISATIONMODEL_H
