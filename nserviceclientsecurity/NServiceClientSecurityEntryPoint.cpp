//
// Created by strohhalm on 28.06.15.
//

#include <nserviceclientsecurity/NServiceClientSecurityFactory.h>

using namespace nox::service::client;
using namespace nox::service::client::security;

extern "C"
{
    INServiceClientFactory * createServiceClientFactory(const NString & factoryName)
    {
        if (factoryName.compare(NXS(NServiceClientSecurityFactory)) == 0)
            return new NServiceClientSecurityFactory();
        return NULL;
    }

    void destroyServiceClientFactory(INServiceClientFactory * factory)
    {
        if (factory != NULL)
            delete factory;
    }
}