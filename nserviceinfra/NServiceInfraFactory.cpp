//
// Created by strohhalm on 12.07.15.
//

#include "NServiceInfraFactory.h"
#include "NServiceLocalisation.h"
#include "NServiceKeyProvider.h"

namespace nox
{
    namespace service
    {
        namespace infra
        {
            NServiceInfraFactory::NServiceInfraFactory() : INServiceFactory(NCOMPONENT_SERVICE_INFRA, NXS(NServiceInfraFactory))
            {
            }

            NServiceInfraFactory::~NServiceInfraFactory()
            {
            }

            INService * NServiceInfraFactory::createService(NServiceConfig & serviceConfig)
            {
                if (serviceConfig.getService().compare(NXS(NServiceLocalisation)) == 0)
                {
                    return new NServiceLocalisation(serviceConfig);
                }
                else if (serviceConfig.getService().compare(NXS(NServiceKeyProvider)) == 0)
                {
                    return new NServiceKeyProvider(serviceConfig);
                }
                return NULL;
            }
        }
    }
}