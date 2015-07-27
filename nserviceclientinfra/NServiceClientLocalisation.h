//
// Created by strohhalm on 13.07.15.
//

#ifndef NWEBMEDIA_NSERVICECLIENTLOCALISATION_H
#define NWEBMEDIA_NSERVICECLIENTLOCALISATION_H

#include <nserviceclient/INServiceClient.h>
#include <nserviceclientinfra/INServiceClientLocalisation.h>

namespace nox
{
    namespace service
    {
        namespace client
        {
            namespace infra
            {
                class NServiceClientLocalisation : public INServiceClient, public INServiceClientLocalisation
                {
                public:
                    NServiceClientLocalisation(IINClientSocket * socket);
                    virtual ~NServiceClientLocalisation();
                    DeclareServiceClientFunction(NLocalizeResponse, NLocalizeRequest, localize);
                    DeclareServiceClientFunction(NLocalisationResponse, NLocalisationRequest, readLocalisation);
                    virtual nint compareTo(const INObject * other) const;
                };
            }
        }
    }
}

#endif //NWEBMEDIA_NSERVICECLIENTLOCALISATION_H
