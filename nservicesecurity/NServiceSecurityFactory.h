//
// Created by strohhalm on 21.06.15.
//

#ifndef NSERVICESECURITYFACTORY_H
#define NSERVICESECURITYFACTORY_H

#include <nservice/INServiceFactory.h>
#include <nservicesecurity/NServiceSecurity.h>

namespace nox
{
    namespace service
    {
        namespace security
        {
            class NServiceSecurityFactory : public INServiceFactory
            {
            public:
                NServiceSecurityFactory();
                virtual ~NServiceSecurityFactory();
                virtual INService * createService(NServiceConfig & serviceConfig);
            };
        }
    }
}

#endif //NSERVICEFACTORY_H
