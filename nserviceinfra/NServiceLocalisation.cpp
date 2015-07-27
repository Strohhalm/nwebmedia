//
// Created by strohhalm on 12.07.15.
//

#include <nserviceinfra/model/NInfLocalisationModelAccess.h>
#include "NServiceLocalisation.h"

using namespace nox::infra::model;

namespace nox
{
    namespace service
    {
        namespace infra
        {
            NServiceLocalisation::NServiceLocalisation(NServiceConfig & serviceConfig) : INService(serviceConfig)
            {
                RegisterServiceFunction(readLocalisation)
                RegisterServiceFunction(localize)
            }

            NServiceLocalisation::~NServiceLocalisation()
            {
                UnRegisterServiceFunction(readLocalisation)
                UnRegisterServiceFunction(localize)
            }

            NLocalizeResponse * NServiceLocalisation::localize(NLocalizeRequest * input)
            {
                NInfLocalisationModelAccess access;
                INTypedResultSet<NInfLocalisationModel> * resultSet = NULL;
                NInfLocalisationModel * result = NULL;

                NAssertNull(input)

                NLocalizeResponse * response = new NLocalizeResponse();

                try
                {
                    resultSet = access.read(input->getData().getName(), input->getData().getLocale());
                    if (resultSet != NULL)
                    {
                        result = resultSet->next();
                        if (result != NULL)
                        {
                            response->getData().setText(*result->getText());
                        }
                    }
                    if (resultSet != NULL)
                        delete resultSet;
                    if (result != NULL)
                        delete result;
                }
                catch (exception & exp)
                {
                    if (resultSet != NULL)
                        delete resultSet;
                    if (result != NULL)
                        delete result;

                    response->getHead().getError().setErrorCode(12);
                    response->getHead().getError().setMessage(exp.what());
                }

                return response;
            }

            NLocalisationResponse * NServiceLocalisation::readLocalisation(NLocalisationRequest * input)
            {
                NInfLocalisationModelAccess access;
                INTypedResultSet<NInfLocalisationModel> * resultSet = NULL;
                NInfLocalisationModel * result = NULL;

                NAssertNull(input)

                NLocalisationResponse * response = new NLocalisationResponse();
                NLocalisationEntry * entry = NULL;
                try
                {
                    resultSet = access.readAll(input->getPortion().getFrom(), input->getPortion().getCount());
                    if (resultSet != NULL)
                    {
                        while ((result = resultSet->next()) != NULL)
                        {
                            entry = new NLocalisationEntry();
                            entry->setName(*result->getName());
                            entry->setLocale(*result->getLocale());
                            entry->setText(*result->getText());

                            response->getData().getEntries().add(entry);
                        }
                    }
                    if (resultSet != NULL)
                        delete resultSet;
                    if (result != NULL)
                        delete result;
                }
                catch (exception & exp)
                {
                    if (resultSet != NULL)
                        delete resultSet;
                    if (result != NULL)
                        delete result;

                    response->getHead().getError().setErrorCode(12);
                    response->getHead().getError().setMessage(exp.what());
                }

                return response;
            }
        }
    }
}