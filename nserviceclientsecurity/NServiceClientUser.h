//
// Created by strohhalm on 28.06.15.
//

#ifndef NWEBMEDIA_NSERVICECLIENTUSER_H
#define NWEBMEDIA_NSERVICECLIENTUSER_H

#include <nserviceclient/INServiceClient.h>
#include <nserviceclientsecurity/INServiceClientUser.h>

namespace nox
{
    namespace service
    {
        namespace client
        {
            namespace security
            {
                class NServiceClientUser : public INServiceClient, public INServiceClientUser
                {
                public:
                    NServiceClientUser(IINClientSocket * socket);
                    virtual ~NServiceClientUser();
                    DeclareServiceClientFunction(NCheckLoginCredentialsResponse, NCheckLoginCredentialsRequest, readUserByName);
                    DeclareServiceClientFunction(NCheckLoginCredentialsResponse, NCheckLoginCredentialsRequest, loginUser);
                    virtual nint compareTo(const INObject * other) const;
                };
            }
        }
    }
}

#endif //NWEBMEDIA_NSERVICECLIENTUSER_H
