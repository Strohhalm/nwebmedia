//
// Created by strohhalm on 12.07.15.
//

#include <nserviceinfra/NServiceInfraFactory.h>

using namespace nox::service;
using namespace nox::service::infra;

extern "C"
{
    IINServiceFactory * createServiceFactory(const NString & factoryName)
    {
        if (factoryName.compare(NXS(NServiceInfraFactory)) == 0)
            return new NServiceInfraFactory();
        return NULL;
    }

    void destroyServiceFactory(IINServiceFactory * factory)
    {
        if (factory != NULL)
            delete factory;
    }
}