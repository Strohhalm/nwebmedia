//
// Created by strohhalm on 24.07.15.
//

#ifndef NWEBMEDIA_NSERVICECLIENTKEYPROVIDER_H
#define NWEBMEDIA_NSERVICECLIENTKEYPROVIDER_H

#include <nserviceclient/INServiceClient.h>
#include <nserviceclientinfra/INServiceClientKeyProvider.h>

namespace nox
{
    namespace service
    {
        namespace client
        {
            namespace infra
            {
                class NServiceClientKeyProvider : public INServiceClient , public INServiceClientKeyProvider
                {
                public:
                    NServiceClientKeyProvider(IINClientSocket * socket);
                    virtual ~NServiceClientKeyProvider();
                    DeclareServiceClientFunction(NKeyProviderResponse, NKeyProviderRequest, determineNextKey);
                    virtual void release();
                    virtual nint compareTo(const INObject * other) const;
                };
            }
        }
    }
}

#endif //NWEBMEDIA_NSERVICECLIENTKEYPROVIDER_H
