//
// Created by strohhalm on 13.07.15.
//

#include "NServiceClientLocalisation.h"

namespace nox
{
    namespace service
    {
        namespace client
        {
            namespace infra
            {
                NServiceClientLocalisation::NServiceClientLocalisation(IINClientSocket * socket) : INServiceClient(socket), INServiceClientLocalisation()
                {
                }

                NServiceClientLocalisation::~NServiceClientLocalisation()
                {
                }

                DefineServiceClientFunction(NLocalizeResponse, NLocalizeRequest, NServiceLocalisation, NServiceClientLocalisation, localize);
                DefineServiceClientFunction(NLocalisationResponse, NLocalisationRequest, NServiceLocalisation, NServiceClientLocalisation, readLocalisation);

                nint NServiceClientLocalisation::compareTo(const INObject * other) const
                {
                    if (this == other)
                        return 0;
                    try
                    {
                        const NServiceClientLocalisation * obj = dynamic_cast<const NServiceClientLocalisation *>(other);

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