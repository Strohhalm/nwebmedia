//
// Created by strohhalm on 13.07.15.
//

#include <nserviceclientinfra/NServiceClientInfraFactory.h>

using namespace nox::service::client;
using namespace nox::service::client::infra;

extern "C"
{
    INServiceClientFactory * createServiceClientFactory(const NString & factoryName)
    {
        if (factoryName.compare(NXS(NServiceClientInfraFactory)) == 0)
            return new NServiceClientInfraFactory();
        return NULL;
    }

    void destroyServiceClientFactory(INServiceClientFactory * factory)
    {
        if (factory != NULL)
            delete factory;
    }
}