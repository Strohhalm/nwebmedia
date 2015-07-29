//
// Created by strohhalm on 01.07.15.
//

#ifndef NWEBMEDIA_INSERVICECLIENTUSER_H
#define NWEBMEDIA_INSERVICECLIENTUSER_H

#include <nserviceclient/NServiceClientDefines.h>
#include <nserviceclient/IIINServiceClient.h>
#include <nservicesecurity/exchange/NServiceUserExchange.h>

using namespace nox::service::exchange::security;

namespace nox
{
    namespace service
    {
        namespace client
        {
            namespace security
            {
                class INServiceClientUser : public IIINServiceClient
                {
                public:
                    DeclareServiceClientIFunction(NCheckLoginCredentialsResponse, NCheckLoginCredentialsRequest, loginUser);
                    DeclareServiceClientIFunction(NReadUserByNameResponse, NReadUserByNameRequest, readUserByName);
                    DeclareServiceClientIFunction(NCreateUserResponse, NCreateUserRequest, createUser);
                    DeclareServiceClientIFunction(NChangeUserResponse, NChangeUserRequest, changeUser);
                };
            }
        }
    }
}

#endif //NWEBMEDIA_INSERVICECLIENTUSER_H
