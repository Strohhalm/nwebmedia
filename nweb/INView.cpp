//
// Created by strohhalm on 30.05.15.
//

#include <nweb/localisation/NLocalisationProvider.h>
#include "INView.h"
#include "NViewProvider.h"

using namespace nox::web::localisation;

namespace nox
{
    namespace web
    {
        INView::INView(const NString & component, const NString & viewName) : INObject(), Wt::WContainerWidget()
        {
            m_Component = new NString(component);
            m_ViewName = new NString(viewName);
            m_Session = NULL;
            m_Parent = NULL;
        }

        INView::INView(const NString & component, const NString & viewName, INView * parent) : INObject(), Wt::WContainerWidget(parent)
        {
            m_Component = new NString(component);
            m_ViewName = new NString(viewName);
            m_Session = NULL;
            m_Parent = parent;
        }

        INView::~INView()
        {
            if (m_Component != NULL)
                delete m_Component;
            if (m_ViewName != NULL)
                delete m_ViewName;
        }

        const NString & INView::getViewName() const
        {
            return *m_ViewName;
        }

        const NString & INView::getComponent() const
        {
            return *m_Component;
        }

        INSession * INView::getSession()
        {
            if (m_Session == NULL)
                m_Session = static_cast<INSession *>(Wt::WApplication::instance());
            return m_Session;
        }

        const NString INView::localize(const NString & name)
        {
            return localize(name, getSession()->locale().name());
        }

        const NString INView::localize(const NString & name, const NString & locale)
        {
            return NLocalisationProvider::getInstance()->localize(name, locale);
        }

        void INView::navigate(const NString & outcome)
        {
            if (getParent() != NULL)
            {
                getParent()->navigate(outcome);
            }
            else
            {
                getSession()->navigateByRule(getViewName(), outcome);
            }
        }

        void INView::initialize()
        {
            createView();
        }

        void INView::setParent(INView * parent)
        {
            m_Parent = parent;
        }

        INView * INView::getParent()
        {
            return m_Parent;
        }

        INView * INView::getView(const NString & viewName)
        {
            return NViewProvider::getInstance()->getView(viewName);
        }
    }
}