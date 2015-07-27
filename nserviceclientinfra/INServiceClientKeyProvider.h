//
// Created by strohhalm on 24.07.15.
//

#ifndef NWEBMEDIA_INSERVICECLIENTKEYPROVIDER_H
#define NWEBMEDIA_INSERVICECLIENTKEYPROVIDER_H

#include <nserviceclient/NServiceClientDefines.h>
#include <nserviceinfra/exchange/NServiceKeyProviderExchange.h>

using namespace nox::service::exchange::infra;

namespace nox
{
    namespace service
    {
        namespace client
        {
            namespace infra
            {
                class INServiceClientKeyProvider
                {
                public:
                    DeclareServiceClientIFunction(NKeyProviderResponse, NKeyProviderRequest, determineNextKey);
                };
            }
        }
    }
}

#endif //NWEBMEDIA_INSERVICECLIENTKEYPROVIDER_H
