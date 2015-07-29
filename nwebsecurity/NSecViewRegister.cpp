//
// Created by strohhalm on 12.07.15.
//

#include <nwebsecurity/NSecViewRegister.h>
#include <nserviceclient/NServiceClientProvider.h>
#include <nserviceclientsecurity/INServiceClientUser.h>

using namespace nox::service::client;
using namespace nox::service::client::security;

namespace nox
{
    namespace web
    {
        namespace security
        {
            NSecViewRegister::NSecViewRegister() : INView(NCOMPONENT_WEB_SECURITY, NXS(NSecViewRegister))
            {
            }

            NSecViewRegister::NSecViewRegister(INView * parent) : INView(NCOMPONENT_WEB_SECURITY, NXS(NSecViewRegister), parent)
            {
            }

            NSecViewRegister::~NSecViewRegister()
            {

            }

            void NSecViewRegister::createView()
            {
                Wt::WPanel * panRegister = NULL;
                Wt::WContainerWidget * conRegisterComplete = NULL;
                Wt::WContainerWidget * conRegisterInput = NULL;
                Wt::WContainerWidget * conRegisterButton = NULL;
                Wt::WVBoxLayout * layRegisterComplete = NULL;
                Wt::WVBoxLayout * layRegisterInput = NULL;
                Wt::WHBoxLayout * layRegisterButton = NULL;
                Wt::WLabel * labRegisterUsername = NULL;
                Wt::WLabel * labRegisterPassword = NULL;
                Wt::WLabel * labRegisterPasswordCheck = NULL;
                Wt::WLabel * labRegisterFirstname = NULL;
                Wt::WLabel * labRegisterLastname = NULL;
                Wt::WLabel * labRegisterEmail = NULL;
                Wt::WPushButton * butRegisterCancel = NULL;
                Wt::WPushButton * butRegisterRegister = NULL;

                panRegister = new Wt::WPanel(this);
                panRegister->setId("panRegister");
                panRegister->addStyleClass("panel register");
                panRegister->setTitle(localize("REGISTER"));

                conRegisterComplete = new Wt::WContainerWidget();
                conRegisterComplete->setId("conRegisterComplete");
                conRegisterComplete->setLayout((layRegisterComplete = new Wt::WVBoxLayout()));

                conRegisterInput = new Wt::WContainerWidget(conRegisterComplete);
                conRegisterInput->setId("conRegisterInput");
                conRegisterInput->setLayout((layRegisterInput = new Wt::WVBoxLayout()));

                labRegisterUsername = new Wt::WLabel(conRegisterInput);
                labRegisterUsername->setId("labRegisterUsername");
                labRegisterUsername->setStyleClass("label small");
                labRegisterUsername->setText(localize("USERNAME"));

                labRegisterPassword = new Wt::WLabel(conRegisterInput);
                labRegisterPassword->setId("labRegisterPassword");
                labRegisterPassword->setStyleClass("label small");
                labRegisterPassword->setText(localize("PASSWORD"));

                labRegisterPasswordCheck = new Wt::WLabel(conRegisterInput);
                labRegisterPasswordCheck->setId("labRegisterPasswordCheck");
                labRegisterPasswordCheck->setStyleClass("label small");
                labRegisterPasswordCheck->setText(localize("PASSWORD_CHECK"));

                labRegisterFirstname = new Wt::WLabel(conRegisterInput);
                labRegisterFirstname->setId("labRegisterFirstname");
                labRegisterFirstname->setStyleClass("label small");
                labRegisterFirstname->setText(localize("FIRSTNAME"));

                labRegisterLastname = new Wt::WLabel(conRegisterInput);
                labRegisterLastname->setId("labRegisterLastname");
                labRegisterLastname->setStyleClass("label small");
                labRegisterLastname->setText(localize("LASTNAME"));

                labRegisterEmail = new Wt::WLabel(conRegisterInput);
                labRegisterEmail->setId("labRegisterEmail");
                labRegisterEmail->setStyleClass("label small");
                labRegisterEmail->setText(localize("EMAIL"));

                m_ledUsername = new Wt::WLineEdit(conRegisterInput);
                m_ledUsername->setId("ledRegisterUsername");
                m_ledUsername->setStyleClass("input");
                m_ledUsername->setMaxLength(50);
                m_ledUsername->setPlaceholderText(localize("USERNAME"));

                m_ledPassword = new Wt::WLineEdit(conRegisterInput);
                m_ledPassword->setId("ledRegisterPassword");
                m_ledPassword->setStyleClass("input password");
                m_ledPassword->setEchoMode(Wt::WLineEdit::EchoMode::Password);
                m_ledPassword->setMaxLength(50);
                m_ledPassword->setPlaceholderText(localize("PASSWORD"));

                m_ledPasswordCheck = new Wt::WLineEdit(conRegisterInput);
                m_ledPasswordCheck->setId("ledRegisterPasswordCheck");
                m_ledPasswordCheck->setStyleClass("input password");
                m_ledPasswordCheck->setEchoMode(Wt::WLineEdit::EchoMode::Password);
                m_ledPasswordCheck->setMaxLength(50);
                m_ledPasswordCheck->setPlaceholderText(localize("PASSWORD_CHECK"));

                m_ledFirstName = new Wt::WLineEdit(conRegisterInput);
                m_ledFirstName->setId("ledRegisterFirstName");
                m_ledFirstName->setStyleClass("input");
                m_ledFirstName->setMaxLength(50);
                m_ledFirstName->setPlaceholderText(localize("FIRSTNAME"));

                m_ledLastName = new Wt::WLineEdit(conRegisterInput);
                m_ledLastName->setId("ledRegisterLastName");
                m_ledLastName->setStyleClass("input");
                m_ledLastName->setMaxLength(50);
                m_ledLastName->setPlaceholderText(localize("LASTNAME"));

                m_ledEmail = new Wt::WLineEdit(conRegisterInput);
                m_ledEmail->setId("ledRegisterEmail");
                m_ledEmail->setStyleClass("input");
                m_ledEmail->setMaxLength(50);
                m_ledEmail->setPlaceholderText(localize("EMAIL"));

                layRegisterInput->addWidget(labRegisterUsername);
                layRegisterInput->addWidget(m_ledUsername);
                layRegisterInput->addWidget(labRegisterPassword);
                layRegisterInput->addWidget(m_ledPassword);
                layRegisterInput->addWidget(labRegisterPasswordCheck);
                layRegisterInput->addWidget(m_ledPasswordCheck);
                layRegisterInput->addWidget(labRegisterFirstname);
                layRegisterInput->addWidget(m_ledFirstName);
                layRegisterInput->addWidget(labRegisterLastname);
                layRegisterInput->addWidget(m_ledLastName);
                layRegisterInput->addWidget(labRegisterEmail);
                layRegisterInput->addWidget(m_ledEmail);

                conRegisterButton = new Wt::WContainerWidget(conRegisterComplete);
                conRegisterButton->setId("conRegisterButton");
                conRegisterButton->setLayout((layRegisterButton = new Wt::WHBoxLayout()));

                butRegisterCancel = new Wt::WPushButton(conRegisterButton);
                butRegisterCancel->setId("butRegisterCancel");
                butRegisterCancel->setStyleClass("button");
                butRegisterCancel->setText(localize("CANCEL"));
                butRegisterCancel->clicked().connect(this, &NSecViewRegister::onCancel);

                butRegisterRegister = new Wt::WPushButton(conRegisterButton);
                butRegisterRegister->setId("butRegisterRegister");
                butRegisterRegister->setStyleClass("button");
                butRegisterRegister->setText(localize("REGISTER"));
                butRegisterRegister->clicked().connect(this, &NSecViewRegister::onRegister);

                layRegisterButton->addWidget(butRegisterCancel);
                layRegisterButton->addWidget(butRegisterRegister);

                layRegisterComplete->addWidget(conRegisterInput);
                layRegisterComplete->addWidget(conRegisterButton);

                panRegister->setCentralWidget(conRegisterComplete);

                addWidget(panRegister);
            }

            void NSecViewRegister::onRegister()
            {
                INServiceClientUser * service = NULL;
                NReadUserByNameRequest  * readUserRequest = NULL;
                NReadUserByNameResponse * readUserResponse = NULL;

                NCreateUserRequest  * createUserRequest = NULL;
                NCreateUserResponse * createUserResponse = NULL;

                try
                {
                    service = NServiceClientProvider::getInstance()->getServiceClient<INServiceClientUser>(NXS(NServiceClientUser));
                    if (service != NULL)
                    {
                        readUserRequest = new NReadUserByNameRequest();
                        readUserRequest->getData().setUsername(m_ledUsername->text().toUTF8());
                        readUserRequest->getData().setState(BOTH);

                        readUserResponse = service->readUserByName(readUserRequest);

                        if (readUserResponse != NULL)
                        {
                            if (readUserResponse->getData().getId() != NInteger(0))
                            {
                                throw NRuntimeException("User does already exist");
                            }
                            else
                            {
                                createUserRequest = new NCreateUserRequest();
                                createUserRequest->getData().setValidFrom(NDate::getCurrentDate());
                                createUserRequest->getData().setUsername(m_ledUsername->text().toUTF8());
                                createUserRequest->getData().setPassword(m_ledPassword->text().toUTF8());
                                createUserRequest->getData().setFirstName(m_ledFirstName->text().toUTF8());
                                createUserRequest->getData().setLastName(m_ledLastName->text().toUTF8());
                                createUserRequest->getData().setEmail(m_ledEmail->text().toUTF8());
                                createUserRequest->getData().setActive(false);

                                createUserResponse = service->createUser(createUserRequest);

                                if (createUserResponse != NULL)
                                {
                                    if (createUserRequest->getData().getId() == NInteger(0))
                                    {
                                       navigate("SUCCESS");
                                    }
                                    else
                                    {
                                        throw NRuntimeException(createUserResponse->getHead().getError().getMessage());
                                    }
                                    delete createUserResponse;
                                }
                                delete createUserRequest;
                            }
                            delete readUserResponse;
                        }
                        delete readUserRequest;
                        service->release();
                    }
                }
                catch (exception & exp)
                {
                    if (readUserRequest != NULL)
                        delete readUserRequest;
                    if (readUserResponse != NULL)
                        delete readUserResponse;
                    if (createUserRequest != NULL)
                        delete createUserRequest;
                    if (createUserResponse != NULL)
                        delete createUserResponse;
                    if (service != NULL)
                        service->release();
                    throw;
                }
            }

            void NSecViewRegister::onCancel()
            {
                navigate("CANCEL");
            }

            nint NSecViewRegister::compareTo(const INObject * other) const
            {
                return 0;
            }
        }
    }
}