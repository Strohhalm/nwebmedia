//
// Created by strohhalm on 24.07.15.
//

#include "NServiceKeyProvider.h"
#include <nserviceinfra/model/NInfKeysModelAccess.h>

using namespace nox::infra::model;

namespace nox
{
    namespace service
    {
        namespace infra
        {
            NServiceKeyProvider::NServiceKeyProvider(NServiceConfig & serviceConfig) : INService(serviceConfig)
            {
                m_Mutex = new boost::mutex();
            }

            NServiceKeyProvider::~NServiceKeyProvider()
            {
                if (m_Mutex != NULL)
                    delete m_Mutex;
            }

            NKeyProviderResponse * NServiceKeyProvider::determineNextKey(NKeyProviderRequest * input)
            {
                NKeyProviderResponse * response = NULL;

                m_Mutex->lock();
                {
                    NInfKeysModelAccess access;

                    INTypedResultSet<NInfKeysModel> * resultSet = NULL;
                    NInfKeysModel * result = NULL;

                    try
                    {
                        response = new NKeyProviderResponse();

                        resultSet = access.read(input->getData().getKeyClass(), input->getData().getComponent());
                        if (resultSet != NULL)
                        {
                            result = resultSet->next();
                            if (result != NULL)
                            {
                                *result->getKeyValue() += 1;

                                access.update(*result);
                            }
                            else
                            {
                                result = new NInfKeysModel();
                                result->setKeyClass(new NString(input->getData().getKeyClass()));
                                result->setComponent(new NString(input->getData().getComponent()));
                                result->setKeyValue(new NLong(1));

                                access.insert(*result);
                            }
                            delete resultSet;
                        }
                        else
                        {
                            result = new NInfKeysModel();
                            result->setKeyClass(new NString(input->getData().getKeyClass()));
                            result->setComponent(new NString(input->getData().getComponent()));
                            result->setKeyValue(new NLong(1));

                            access.insert(*result);
                        }

                        response->getData().setKey(*result->getKeyValue());

                        if (result != NULL)
                            delete result;
                    }
                    catch (...)
                    {
                        if (resultSet != NULL)
                            delete resultSet;
                        if (result != NULL)
                            delete result;
                        if (response != NULL)
                            delete response;

                        m_Mutex->unlock();
                        throw;
                    }
                }
                m_Mutex->unlock();

                return response;
            }
        }
    }
}