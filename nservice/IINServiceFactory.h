//
// Created by strohhalm on 21.06.15.
//

#ifndef IINSERVICEFACTORY_H
#define IINSERVICEFACTORY_H

#include <nbase/NBaseType.h>
#include <nservice/config/NServiceConfig.h>
#include <nservice/INService.h>

using namespace nox::service::configuration;

namespace nox
{
    namespace service
    {
        class IINServiceFactory : public INObject
        {
        public:
            IINServiceFactory();
            virtual ~IINServiceFactory();
            virtual const NString & getComponentName() const = 0;
            virtual const NString & getFactoryName() const = 0;
            virtual INService * createService(NServiceConfig & serviceConfig) = 0;
        };
    }
}

#endif //IINSERVICEFACTORY_H
