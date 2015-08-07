//
// Created by strohhalm on 22.06.15.
//

#include <nserviceclient/NServiceClientProvider.h>
#include <nserviceclientsecurity/INServiceClientUser.h>
#include <nwebsecurity/NSecViewLogin.h>

using namespace nox::service::client;
using namespace nox::service::client::security;

namespace nox
{
    namespace web
    {
        namespace security
        {
            NSecViewLogin::NSecViewLogin() : INView(NCOMPONENT_WEB_SECURITY, NXS(NSecViewLogin))
            {
            }

            NSecViewLogin::NSecViewLogin(INView * parent) : INView(NCOMPONENT_WEB_SECURITY, NXS(NSecViewLogin), parent)
            {
            }

            NSecViewLogin::~NSecViewLogin()
            {
            }

            void NSecViewLogin::createView()
            {
                Wt::WPanel * panLogin = NULL;
                Wt::WContainerWidget * conLoginComplete = NULL;
                Wt::WContainerWidget * conLoginInput = NULL;
                Wt::WContainerWidget * conLoginButton = NULL;
                Wt::WVBoxLayout * layLoginComplete = NULL;
                Wt::WVBoxLayout * layLoginInput = NULL;
                Wt::WHBoxLayout * layLoginButton = NULL;
                Wt::WLabel * labLoginUsername = NULL;
                Wt::WLabel * labLoginPassword = NULL;
                Wt::WPushButton * butLoginLogin = NULL;
                Wt::WPushButton * butLoginRegister = NULL;
                Wt::WLengthValidator * usernameValidator = NULL;
                Wt::WLengthValidator * passwordValidator = NULL;

                panLogin = new Wt::WPanel(this);
                panLogin->setId("panLogin");
                panLogin->addStyleClass("panel login");
                panLogin->setTitle(localize("LOGIN"));

                conLoginComplete = new Wt::WContainerWidget();
                conLoginComplete->setId("conLoginComplete");
                conLoginComplete->setLayout((layLoginComplete = new Wt::WVBoxLayout()));

                conLoginInput = new Wt::WContainerWidget(conLoginComplete);
                conLoginInput->setId("conLoginInput");
                conLoginInput->setLayout((layLoginInput = new Wt::WVBoxLayout()));

                labLoginUsername = new Wt::WLabel(conLoginInput);
                labLoginUsername->setId("labLoginUsername");
                labLoginUsername->setStyleClass("label small");
                labLoginUsername->setText(localize("USERNAME"));

                labLoginPassword = new Wt::WLabel(conLoginInput);
                labLoginPassword->setId("labLoginPassword");
                labLoginPassword->setStyleClass("label small");
                labLoginPassword->setText(localize("PASSWORD"));

                m_ledUsername = new Wt::WLineEdit(conLoginInput);
                m_ledUsername->setId("ledLoginUsername");
                m_ledUsername->setStyleClass("input");
                m_ledUsername->setMaxLength(50);
                m_ledUsername->setPlaceholderText(localize("USERNAME"));
                
                usernameValidator = new Wt::WLengthValidator();
                usernameValidator->setMandatory(true);
                usernameValidator->setMinimumLength(6);
                usernameValidator->setMaximumLength(50);
                
                m_ledUsername->setValidator(usernameValidator);

                m_ledPassword = new Wt::WLineEdit(conLoginInput);
                m_ledPassword->setId("ledLoginPassword");
                m_ledPassword->setStyleClass("input password");
                m_ledPassword->setEchoMode(Wt::WLineEdit::EchoMode::Password);
                m_ledPassword->setMaxLength(50);
                m_ledPassword->setPlaceholderText(localize("PASSWORD"));
                
                passwordValidator = new Wt::WLengthValidator();
                passwordValidator->setMandatory(true);
                passwordValidator->setMinimumLength(6);
                passwordValidator->setMaximumLength(50);
                
                m_ledPassword->setValidator(passwordValidator);

                layLoginInput->addWidget(labLoginUsername);
                layLoginInput->addWidget(m_ledUsername);
                layLoginInput->addWidget(labLoginPassword);
                layLoginInput->addWidget(m_ledPassword);

                conLoginButton = new Wt::WContainerWidget(conLoginComplete);
                conLoginButton->setId("conLoginButton");
                conLoginButton->setLayout((layLoginButton = new Wt::WHBoxLayout()));

                butLoginLogin = new Wt::WPushButton(conLoginButton);
                butLoginLogin->setId("butLoginLogin");
                butLoginLogin->setStyleClass("button");
                butLoginLogin->setText(localize("LOGIN"));
                butLoginLogin->clicked().connect(this, &NSecViewLogin::onLogin);

                butLoginRegister = new Wt::WPushButton(conLoginButton);
                butLoginRegister->setId("butLoginRegister");
                butLoginRegister->setStyleClass("button");
                butLoginRegister->setText(localize("REGISTER"));
                butLoginRegister->clicked().connect(this, &NSecViewLogin::onRegister);

                layLoginButton->addWidget(butLoginRegister);
                layLoginButton->addWidget(butLoginLogin);

                layLoginComplete->addWidget(conLoginInput);
                layLoginComplete->addWidget(conLoginButton);

                panLogin->setCentralWidget(conLoginComplete);

                addWidget(panLogin);
            }

            void NSecViewLogin::onLogin()
            {
                INServiceClientUser * client = NServiceClientProvider::getInstance()->getServiceClient<INServiceClientUser>("NServiceClientUser");

                if (client != NULL)
                {
                    NCheckLoginCredentialsRequest  * request  = new NCheckLoginCredentialsRequest();
                    NCheckLoginCredentialsResponse * response = NULL;

                    request->getData().setUsername(m_ledUsername->text().toUTF8());
                    request->getData().setPassword(m_ledPassword->text().toUTF8());

                    response = client->loginUser(request);

                    if (response->getData().isOk())
                    {
                        getSession()->setUserId(response->getData().getUserId());

                        navigate("SUCCESS");
                    }

                    delete response;
                    delete request;
                    client->release();
                }
                else
                {

                }
            }

            void NSecViewLogin::onRegister()
            {
                navigate("REGISTER");
            }

            nint NSecViewLogin::compareTo(const INObject * other) const
            {
                if (this == other)
                    return 0;
                try
                {
                    const NSecViewLogin * obj = dynamic_cast<const NSecViewLogin *>(other);

                    if (obj != NULL)
                    {
                        nint result = 0;
                        if ((result = getComponent().compare(obj->getComponent())) == 0)
                        {
                            result = getViewName().compare(obj->getViewName());
                        }
                        return result;
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
