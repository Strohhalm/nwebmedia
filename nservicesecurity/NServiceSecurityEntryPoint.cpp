//
// Created by strohhalm on 21.06.15.
//

#include "NServiceSecurityFactory.h"

using namespace nox::service;
using namespace nox::service::security;

extern "C"
{
    IINServiceFactory * createServiceFactory(const NString & factoryName)
    {
        if (factoryName.compare(NXS(NServiceSecurityFactory)) == 0)
            return new NServiceSecurityFactory();
        return NULL;
    }

    void destroyServiceFactory(IINServiceFactory * factory)
    {
        if (factory != NULL)
            delete factory;
    }
}