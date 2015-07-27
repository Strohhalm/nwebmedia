//
// Created by strohhalm on 28.06.15.
//

#include <nserviceclientsecurity/NServiceClientSecurityFactory.h>
#include <nserviceclientsecurity/NServiceClientUser.h>

namespace nox
{
    namespace service
    {
        namespace client
        {
            namespace security
            {
                NServiceClientSecurityFactory::NServiceClientSecurityFactory() : INServiceClientFactory(NCOMPONENT_SERVICE_CLIENT_SECURIY, NXS(NServiceClientSecurityFactory))
                {
                }

                NServiceClientSecurityFactory::~NServiceClientSecurityFactory()
                {
                }


                INServiceClient * NServiceClientSecurityFactory::createServiceClient(IINClientSocket * socket, const NString & serviceName)
                {
                    if (serviceName.compare(NXS(NServiceClientUser)) == 0)
                    {
                        return new NServiceClientUser(socket);
                    }
                    return NULL;
                }

                nint NServiceClientSecurityFactory::compareTo(const INObject * other) const
                {
                    if (this == other)
                        return 0;
                    try
                    {
                        const NServiceClientSecurityFactory * obj = dynamic_cast<const NServiceClientSecurityFactory *>(other);

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