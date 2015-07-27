//
// Created by strohhalm on 24.07.15.
//

#ifndef NWEBMEDIA_NSERVICEKEYPROVIDER_H
#define NWEBMEDIA_NSERVICEKEYPROVIDER_H

#include <nservice/INService.h>
#include <nserviceinfra/exchange/NServiceKeyProviderExchange.h>

using namespace nox::service::exchange::infra;

namespace nox
{
    namespace service
    {
        namespace infra
        {
            class NServiceKeyProvider : public INService
            {
            protected:
                boost::mutex * m_Mutex;
            public:
                NServiceKeyProvider(NServiceConfig & serviceConfig);
                virtual ~NServiceKeyProvider();
                DeclareServiceFunction(NServiceKeyProvider, determineNextKey, NKeyProviderRequest, NKeyProviderResponse);
            };
        }
    }
}


#endif //NWEBMEDIA_NSERVICEKEYPROVIDER_H
