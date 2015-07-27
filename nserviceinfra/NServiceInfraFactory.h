//
// Created by strohhalm on 12.07.15.
//

#ifndef NWEBMEDIA_NSERVICEINFRAFACTORY_H
#define NWEBMEDIA_NSERVICEINFRAFACTORY_H

#include <nservice/INServiceFactory.h>
#include <nserviceinfra/NServiceInfra.h>

namespace nox
{
    namespace service
    {
        namespace infra
        {
            class NServiceInfraFactory : public INServiceFactory
            {
            public:
                NServiceInfraFactory();
                virtual ~NServiceInfraFactory();
                virtual INService * createService(NServiceConfig & serviceConfig);
            };
        }
    }
}

#endif //NWEBMEDIA_NSERVICEINFRAFACTORY_H
