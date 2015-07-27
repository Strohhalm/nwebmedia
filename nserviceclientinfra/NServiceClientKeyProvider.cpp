//
// Created by strohhalm on 24.07.15.
//

#include "NServiceClientKeyProvider.h"

namespace nox
{
    namespace service
    {
        namespace client
        {
            namespace infra
            {
                NServiceClientKeyProvider::NServiceClientKeyProvider(IINClientSocket * socket) : INServiceClient(socket)
                {
                }

                NServiceClientKeyProvider::~NServiceClientKeyProvider()
                {
                }

                DefineServiceClientFunction(NKeyProviderResponse, NKeyProviderRequest, NServiceKeyProvider, NServiceClientKeyProvider, determineNextKey)

                nint NServiceClientKeyProvider::compareTo(const INObject * other) const
                {
                    if (this == other)
                        return 0;
                    try
                    {
                        const NServiceClientKeyProvider * obj = dynamic_cast<const NServiceClientKeyProvider *>(other);

                        if (obj != NULL)
                        {
                            return 0;
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