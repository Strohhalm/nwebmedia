//
// Created by strohhalm on 20.06.15.
//

#include <nservicesecurity/NServiceUser.h>
#include <nservicesecurity/model/NSecUserModel.h>
#include <nservicesecurity/model/NSecUserModelAccess.h>

#include <nserviceclient/NServiceClientProvider.h>
#include <nserviceclientinfra/INServiceClientKeyProvider.h>

using namespace nox::security::model;
using namespace nox::service::client;
using namespace nox::service::client::infra;

namespace nox
{
    namespace service
    {
        namespace security
        {
            NServiceUser::NServiceUser(NServiceConfig & serviceConfig) : INService(serviceConfig)
            {
                RegisterServiceFunction(loginUser)
                RegisterServiceFunction(createUser)
                RegisterServiceFunction(changeUser)
                RegisterServiceFunction(readUserByName)
                RegisterServiceFunction(deleteUser)
            }

            NServiceUser::~NServiceUser()
            {
                UnRegisterServiceFunction(loginUser)
                UnRegisterServiceFunction(createUser)
                UnRegisterServiceFunction(changeUser)
                UnRegisterServiceFunction(readUserByName)
                UnRegisterServiceFunction(deleteUser)
            }

            NCheckLoginCredentialsResponse * NServiceUser::loginUser(NCheckLoginCredentialsRequest * input)
            {
                NCheckLoginCredentialsResponse * response = NULL;
                INTypedResultSet<NSecUserModel> * resultSet = NULL;
                NSecUserModelAccess access;
                NSecUserModel * result = NULL;

                try
                {
                    response = new NCheckLoginCredentialsResponse();

                    resultSet = access.readUserByName(input->getData().getUsername(), true, NDate::getCurrentDate());
                    if (resultSet != NULL)
                    {
                        if ((result = resultSet->next()) != NULL)
                        {
                            if (result->getPassword() != NULL)
                            {
                                if (result->getPassword()->compare(input->getData().getPassword()) == 0)
                                {
                                    response->getData().setOk(true);
                                    response->getData().setUserId(*result->getId());
                                }
                            }
                            delete result;
                        }
                        delete resultSet;
                    }
                }
                catch (...)
                {
                    if (resultSet != NULL)
                        delete resultSet;
                    if (result != NULL)
                        delete result;
                    if (response != NULL)
                        delete response;

                    throw;
                }
                return response;
            }

            NCreateUserResponse * NServiceUser::createUser(NCreateUserRequest * input)
            {
                INServiceClientKeyProvider * keyProvider = NULL;
                NKeyProviderRequest * keyRequest = NULL;
                NKeyProviderResponse * keyResponse = NULL;
                NCreateUserResponse * response = NULL;
                NSecUserModelAccess access;
                NSecUserModel model;

                try
                {
                    response = new NCreateUserResponse();

                    keyProvider = NServiceClientProvider::getInstance()->getServiceClient<INServiceClientKeyProvider>(NXS(NServiceClientKeyProvider));
                    if (keyProvider != NULL)
                    {
                        keyRequest = new NKeyProviderRequest();
                        keyRequest->getData().setKeyClass(NXS(NOX_SEC_USER));
                        keyRequest->getData().setComponent(NCOMPONENT_SERVICE_SECURITY);

                        keyResponse = keyProvider->determineNextKey(keyRequest);
                    }
                    else
                    {
                        throw NRuntimeException("No key provider available");
                    }

                    model.setId(keyResponse->getData().getKey().as<nint>());
                    model.setValidFrom(input->getData().getValidFrom());
                    if (!input->getData().getValidTo().isEquals(NDate::INVALID))
                        model.setValidTo(input->getData().getValidTo());
                    model.setUserName(input->getData().getUsername());
                    model.setPassword(input->getData().getPassword());
                    model.setFirstName(input->getData().getFirstName());
                    model.setLastName(input->getData().getLastName());
                    model.setEMail(input->getData().getEmail());
                    model.setActive(input->getData().isActive());

                    access.insert(model);

                    response->getData().setId(keyResponse->getData().getKey().as<nint>());
                    response->getData().setValidFrom(input->getData().getValidFrom());
                    response->getData().setValidTo(input->getData().getValidTo());
                    response->getData().setUsername(input->getData().getUsername());
                    response->getData().setFirstName(input->getData().getFirstName());
                    response->getData().setLastName(input->getData().getLastName());
                    response->getData().setEmail(input->getData().getEmail());
                    response->getData().setActive(input->getData().isActive());

                    if (keyRequest != NULL)
                        delete keyRequest;
                    if (keyResponse != NULL)
                        delete keyResponse;
                    if (keyProvider != NULL)
                        keyProvider->release();
                }
                catch (...)
                {
                    if (keyRequest != NULL)
                        delete keyRequest;
                    if (keyResponse != NULL)
                        delete keyResponse;
                    if (keyProvider != NULL)
                        keyProvider->release();
                    if (response != NULL)
                        delete response;

                    throw;
                }

                return response;
            }

            NChangeUserResponse* NServiceUser::changeUser(NChangeUserRequest * input)
            {
                NChangeUserResponse * response = NULL;
                NSecUserModelAccess access;
                NSecUserModel model;

                try
                {
                    response = new NChangeUserResponse();

                    model.setId(input->getData().getId());
                    model.setValidFrom(input->getData().getValidFrom());
                    if (!input->getData().getValidTo().isEquals(NDate::INVALID))
                        model.setValidTo(input->getData().getValidTo());
                    model.setUserName(input->getData().getUsername());
                    model.setFirstName(input->getData().getFirstName());
                    model.setLastName(input->getData().getLastName());
                    model.setEMail(input->getData().getEmail());
                    model.setActive(input->getData().isActive());

                    access.update(model);

                    response->getData().setId(input->getData().getId());
                    response->getData().setValidFrom(input->getData().getValidFrom());
                    response->getData().setValidTo(input->getData().getValidTo());
                    response->getData().setUsername(input->getData().getUsername());
                    response->getData().setFirstName(input->getData().getFirstName());
                    response->getData().setLastName(input->getData().getLastName());
                    response->getData().setEmail(input->getData().getEmail());
                    response->getData().setActive(input->getData().isActive());
                }
                catch (...)
                {
                    if (response != NULL)
                        delete response;

                    throw;
                }

                return response;
            }

            NReadUserByNameResponse * NServiceUser::readUserByName(NReadUserByNameRequest * input)
            {
                NReadUserByNameResponse * response = NULL;
                INTypedResultSet<NSecUserModel> * resultSet = NULL;
                NSecUserModel * result = NULL;

                NSecUserModelAccess access;

                try
                {
                    response = new NReadUserByNameResponse();

                    switch (input->getData().getState())
                    {
                        case ACTIVE:
                        {
                            if (input->getData().getDueDate().isEquals(NDate::INVALID))
                            {
                                resultSet = access.readUserByName(input->getData().getUsername(),
                                                                  true);
                            }
                            else
                            {
                                resultSet = access.readUserByName(input->getData().getUsername(),
                                                                  true,
                                                                  input->getData().getDueDate());
                            }
                            break;
                        }
                        case INACTIVE:
                        {
                            if (input->getData().getDueDate().isEquals(NDate::INVALID))
                            {
                                resultSet = access.readUserByName(input->getData().getUsername(),
                                                                  false);
                            }
                            else
                            {
                                resultSet = access.readUserByName(input->getData().getUsername(),
                                                                  false,
                                                                  input->getData().getDueDate());
                            }
                            break;
                        }
                        case BOTH:
                        {
                            if (input->getData().getDueDate().isEquals(NDate::INVALID))
                            {
                                resultSet = access.readUserByName(input->getData().getUsername());
                            }
                            else
                            {
                                resultSet = access.readUserByName(input->getData().getUsername(),
                                                                  input->getData().getDueDate());
                            }
                            break;
                        }
                    }

                    if (resultSet != NULL)
                    {
                        if ((result = resultSet->next()) != NULL)
                        {
                            response->getData().setId(*result->getId());
                            response->getData().setValidFrom(*result->getValidFrom());
                            if (result->getValidTo() != NULL)
                                response->getData().setValidTo(*result->getValidTo());
                            response->getData().setUsername(*result->getUserName());
                            response->getData().setPassword(*result->getPassword());
                            response->getData().setFirstName(*result->getFirstName());
                            response->getData().setLastName(*result->getLastName());
                            response->getData().setEmail(*result->getEMail());
                            response->getData().setActive(*result->getActive());

                            delete result;
                        }
                        delete resultSet;
                    }
                }
                catch (...)
                {
                    if (resultSet != NULL)
                        delete resultSet;
                    if (result != NULL)
                        delete result;
                    if (response != NULL)
                        delete response;
                }

                return response;
            }

            NCheckLoginCredentialsResponse * NServiceUser::deleteUser(NCheckLoginCredentialsRequest * input)
            {
                NCheckLoginCredentialsResponse * response = NULL;

                return response;
            }
        }
    }
}