//
// Created by strohhalm on 28.06.15.
//

#include "NServiceClientUser.h"

namespace nox
{
    namespace service
    {
        namespace client
        {
            namespace security
            {

                NServiceClientUser::NServiceClientUser(IINClientSocket * socket) : INServiceClient(socket), INServiceClientUser()
                {
                }

                NServiceClientUser::~NServiceClientUser()
                {
                }

                DefineServiceClientFunction(NCheckLoginCredentialsResponse, NCheckLoginCredentialsRequest, NServiceUser, NServiceClientUser, readUserByName);
                DefineServiceClientFunction(NCheckLoginCredentialsResponse, NCheckLoginCredentialsRequest, NServiceUser, NServiceClientUser, loginUser);

                nint NServiceClientUser::compareTo(const INObject * other) const
                {
                    if (this == other)
                        return 0;
                    try
                    {
                        const NServiceClientUser * obj = dynamic_cast<const NServiceClientUser *>(other);

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