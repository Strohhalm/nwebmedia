//
// Created by strohhalm on 12.07.15.
//

#ifndef NWEBMEDIA_NSERVICELOCALISATION_H
#define NWEBMEDIA_NSERVICELOCALISATION_H

#include <nservice/INService.h>
#include <nserviceinfra/exchange/NServiceLocalisationExchange.h>

using namespace nox::service::exchange::infra;

namespace nox
{
    namespace service
    {
        namespace infra
        {
            class NServiceLocalisation : public INService
            {
            public:
                NServiceLocalisation(NServiceConfig & serviceConfig);
                virtual ~NServiceLocalisation();
                DeclareServiceFunction(NServiceLocalisation, localize, NLocalizeRequest, NLocalizeResponse)
                DeclareServiceFunction(NServiceLocalisation, readLocalisation, NLocalisationRequest, NLocalisationResponse)
            };
        }
    }
}

#endif //NWEBMEDIA_NSERVICELOCALISATION_H
