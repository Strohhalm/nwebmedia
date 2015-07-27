//
// Created by strohhalm on 21.06.15.
//

#include "NServiceSecurityFactory.h"
#include "NServiceUser.h"

namespace nox
{
    namespace service
    {
        namespace security
        {
            NServiceSecurityFactory::NServiceSecurityFactory() : INServiceFactory(NCOMPONENT_SERVICE_SECURITY, NXS(NServiceSecurityFactory))
            {
            }

            NServiceSecurityFactory::~NServiceSecurityFactory()
            {
            }

            INService * NServiceSecurityFactory::createService(NServiceConfig & serviceConfig)
            {
                if (serviceConfig.getService().compare(NXS(NServiceUser)) == 0)
                    return new NServiceUser(serviceConfig);
                return NULL;
            }
        }
    }
}