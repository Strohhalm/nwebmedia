//
// Created by strohhalm on 13.07.15.
//

#include "NServiceClientInfraFactory.h"
#include "NServiceClientLocalisation.h"
#include "NServiceClientKeyProvider.h"

namespace nox
{
    namespace service
    {
        namespace client
        {
            namespace infra
            {

                NServiceClientInfraFactory::NServiceClientInfraFactory() : INServiceClientFactory(NCOMPONENT_SERVICE_CLIENT_INFRA, NXS(NServiceClientInfraFactory))
                {
                }

                NServiceClientInfraFactory::~NServiceClientInfraFactory()
                {
                }

                INServiceClient * NServiceClientInfraFactory::createServiceClient(IINClientSocket * socket, const NString & serviceName)
                {
                    if (serviceName.compare(NXS(NServiceClientLocalisation)) == 0)
                    {
                        return new NServiceClientLocalisation(socket);
                    }
                    else if (serviceName.compare(NXS(NServiceClientKeyProvider)) == 0)
                    {
                        return new NServiceClientKeyProvider(socket);
                    }
                    return NULL;
                }

                nint NServiceClientInfraFactory::compareTo(const INObject * other) const
                {
                    if (this == other)
                        return 0;
                    try
                    {
                        const NServiceClientInfraFactory * obj = dynamic_cast<const NServiceClientInfraFactory *>(other);

                        if (obj != NULL)
                        {
                            int result = 0;
                            if ((result = getComponentName().compare(obj->getComponentName())) == 0)
                            {
                                result = getFactoryName().compare(obj->getFactoryName());
                            }
                            return result;
                        }
                        else
                        {
                            return 1;
                        }
                    }
                    catch (bad_cast &)
                    {
                        return 1;
                    }
                }
            }
        }
    }
}