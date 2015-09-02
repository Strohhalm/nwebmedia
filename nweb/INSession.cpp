//
// Created by strohhalm on 30.06.15.
//

#include <nweb/INSession.h>
#include <nweb/NViewProvider.h>
#include <nweb/NNavigationProvider.h>
#include <nweb/resource/NCascadingStyleSheetsFile.h>
#include <nweb/localisation/NLocalisationProvider.h>

using namespace nox::web::resource;
using namespace nox::web::localisation;

namespace nox
{
    namespace web
    {
        INSession::INSession(const Wt::WEnvironment & environment) : Wt::WApplication(environment), INObject()
        {
            m_MessageBox = NULL;
            m_UserId = new NInteger(-1);

            INList<NCascadingStyleSheetsFile *> * cssFileList = NULL;
            try
            {
                cssFileList = NResourcePool::getResources<NCascadingStyleSheetsFile>("style", CSS_SUFFIX);
                if (cssFileList != NULL)
                {
                    for (nlong i = 0; i < cssFileList->getSize(); i++)
                    {
                        if (cssFileList->get(i) != NULL)
                        {
                            useStyleSheet(cssFileList->get(i)->getRelativePath());
                            delete cssFileList->get(i);
                        }
                    }
                    delete cssFileList;
                }
                navigateByRule("", NNavigationProvider::getInstance()->resolveInitialView());
            }
            catch (...)
            {
                if (cssFileList != NULL)
                {
                    for (nlong i = 0; i < cssFileList->getSize(); i++)
                    {
                        if (cssFileList->get(i) != NULL)
                            delete cssFileList->get(i);
                    }
                    delete cssFileList;
                }
                delete m_UserId;
            }
        }

        INSession::~INSession()
        {
            if (m_UserId != NULL)
                delete m_UserId;
            if (m_MessageBox != NULL)
                delete m_MessageBox;
        }

        void INSession::setUserId(const NInteger & userId)
        {
            m_UserId->setValue(userId);
        }

        const NInteger & INSession::getUserId()
        {
            return *m_UserId;
        }

        void INSession::navigateByRule(const NString & currentView, const NString & outcome)
        {
            INView * view = NViewProvider::getInstance()->getView(NNavigationProvider::getInstance()->resolve(currentView, outcome));
            if (view != NULL)
            {
                root()->clear();
                root()->addWidget(view);
            }
        }

        const NString INSession::localize(const NString & name)
        {
            return localize(name, locale().name());
        }

        const NString INSession::localize(const NString & name, const NString & locale)
        {
            return NLocalisationProvider::getInstance()->localize(name, locale);
        }

        void INSession::notify(const Wt::WEvent & e)
        {
            try
            {
                Wt::WApplication::notify(e);
            }
            catch (exception & exp)
            {
                if (m_MessageBox == NULL)
                {
                    m_MessageBox = new Wt::WMessageBox();

                    m_MessageBox->setId("MessageBox");
                    m_MessageBox->setStyleClass("MessageBox Error");
                    m_MessageBox->addButton(localize("MESSAGE_BOX_BUTTON_OK"), Wt::StandardButton::Ok);
                    m_MessageBox->buttonClicked().connect(std::bind([=]()
                        {
                            if (m_MessageBox->buttonResult() == Wt::StandardButton::Ok)
                                m_MessageBox->hide();
                        }));
                }
                m_MessageBox->setText(exp.what());
                m_MessageBox->setWindowTitle(localize("MESSAGE_BOX_TITLE_CRITICAL_ERROR"));
                m_MessageBox->setIcon(Wt::Icon::Critical);
                m_MessageBox->show();
            }
        }
        
        Wt::WWidget * INSession::createErrorWidget()
        {


            return NULL;
        }
    }
}
