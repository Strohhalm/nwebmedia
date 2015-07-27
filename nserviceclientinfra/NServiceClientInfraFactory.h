//
// Created by strohhalm on 13.07.15.
//

#ifndef NWEBMEDIA_NSERVICECLIENTINFRAFACTORY_H
#define NWEBMEDIA_NSERVICECLIENTINFRAFACTORY_H

#include <nserviceclient/INServiceClientFactory.h>
#include <nserviceclientinfra/NServiceClientInfra.h>

namespace nox
{
    namespace service
    {
        namespace client
        {
            namespace infra
            {
                class NServiceClientInfraFactory : public INServiceClientFactory
                {
                public:
                    NServiceClientInfraFactory();
                    virtual ~NServiceClientInfraFactory();
                    virtual nint compareTo(const INObject * other) const;
                protected:
                    virtual INServiceClient * createServiceClient(IINClientSocket * socket, const NString & serviceName);
                };
            }
        }
    }
}

#endif //NWEBMEDIA_NSERVICECLIENTINFRAFACTORY_H
