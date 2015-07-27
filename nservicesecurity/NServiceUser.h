//
// Created by strohhalm on 20.06.15.
//

#ifndef NSERVICEUSER_H
#define NSERVICEUSER_H

#include <nservice/INService.h>
#include <nservicesecurity/exchange/NServiceUserExchange.h>

using namespace nox::service::exchange::security;

namespace nox
{
    namespace service
    {
        namespace security
        {
            class NServiceUser : public INService
            {
            public:
                NServiceUser(NServiceConfig & serviceConfig);
                virtual ~NServiceUser();
                DeclareServiceFunction(NServiceUser, loginUser, NCheckLoginCredentialsRequest, NCheckLoginCredentialsResponse)
                DeclareServiceFunction(NServiceUser, createUser, NCreateUserRequest, NCreateUserResponse)
                DeclareServiceFunction(NServiceUser, changeUser, NChangeUserRequest, NChangeUserResponse)
                DeclareServiceFunction(NServiceUser, readUserByName, NReadUserByNameRequest, NReadUserByNameResponse)
                DeclareServiceFunction(NServiceUser, deleteUser, NCheckLoginCredentialsRequest, NCheckLoginCredentialsResponse)
            };
        }
    }
}

#endif //NSERVICEUSER_H
