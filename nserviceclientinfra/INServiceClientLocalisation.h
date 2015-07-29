//
// Created by strohhalm on 13.07.15.
//

#ifndef NWEBMEDIA_INSERVICECLIENTLOCALISATION_H
#define NWEBMEDIA_INSERVICECLIENTLOCALISATION_H

#include <nserviceclient/NServiceClientDefines.h>
#include <nserviceclient/IIINServiceClient.h>
#include <nserviceinfra/exchange/NServiceLocalisationExchange.h>

using namespace nox::service::exchange::infra;

namespace nox
{
    namespace service
    {
        namespace client
        {
            namespace infra
            {
                class INServiceClientLocalisation : public IIINServiceClient
                {
                public:
                    DeclareServiceClientIFunction(NLocalizeResponse, NLocalizeRequest, localize)
                    DeclareServiceClientIFunction(NLocalisationResponse, NLocalisationRequest, readLocalisation)
                };
            }
        }
    }
}

#endif //NWEBMEDIA_INSERVICECLIENTLOCALISATION_H
