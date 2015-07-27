//
// Created by strohhalm on 28.06.15.
//

#ifndef NWEBMEDIA_NSERVICECLIENTSECURITYFACTORY_H
#define NWEBMEDIA_NSERVICECLIENTSECURITYFACTORY_H

#include <nserviceclient/INServiceClientFactory.h>
#include <nserviceclientsecurity/NServiceClientSecurity.h>

namespace nox
{
    namespace service
    {
        namespace client
        {
            namespace security
            {
                class NServiceClientSecurityFactory : public INServiceClientFactory
                {
                public:
                    NServiceClientSecurityFactory();
                    virtual ~NServiceClientSecurityFactory();
                    virtual nint compareTo(const INObject * other) const;
                protected:
                    virtual INServiceClient * createServiceClient(IINClientSocket * socket, const NString & serviceName);
                };
            }
        }
    }
}


#endif //NWEBMEDIA_NSERVICECLIENTSECURITYFACTORY_H
