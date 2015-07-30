//
// Created by strohhalm on 30.06.15.
//

#include "INSession.h"
#include "NViewProvider.h"
#include "NNavigationProvider.h"

namespace nox
{
    namespace web
    {
        INSession::INSession(const Wt::WEnvironment & environment) : Wt::WApplication(environment), INObject()
        {
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
                root()->addWidget(createErrorWidget());
            }
        }

        void INSession::notify(const Wt::WEvent & e)
        {
            try
            {
                Wt::WApplication::notify(e);
            }
            catch (exception & exp)
            {

            }
        }
        
        Wt::WWidget * INSession::createErrorWidget()
        {
            
        }
    }
}
