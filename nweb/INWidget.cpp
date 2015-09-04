//
// Created by strohhalm on 04.09.15.
//

#include <nweb/INWidget.h>
#include <nweb/NViewProvider.h>
#include <nweb/NWidgetProvider.h>
#include <nweb/localisation/NLocalisationProvider.h>

using namespace nox::web::localisation;

namespace nox
{
    namespace web
    {
        INWidget::INWidget(const NString & component) : INObject(), Wt::WContainerWidget()
        {
            m_Component = new NString(component);
            m_Session = NULL;
            m_Parent = NULL;
        }

        INWidget::INWidget(const NString & component, INWidget * parent) : INObject(), Wt::WContainerWidget(parent)
        {
            m_Component = new NString(component);
            m_Session = NULL;
            m_Parent = parent;
        }

        INWidget::~INWidget()
        {
            if (m_Component != NULL)
                delete m_Component;
        }

        const NString & INWidget::getComponent() const
        {
            return *m_Component;
        }

        INSession * INWidget::getSession()
        {
            if (m_Session == NULL)
                m_Session = static_cast<INSession *>(Wt::WApplication::instance());
            return m_Session;
        }

        const NString INWidget::localize(const NString & name)
        {
            return localize(name, getSession()->locale().name());
        }

        const NString INWidget::localize(const NString & name, const NString & locale)
        {
            return NLocalisationProvider::getInstance()->localize(name, locale);
        }

        void INWidget::navigate(const NString & outcome)
        {
            if (getParent() != NULL)
            {
                getParent()->navigate(outcome);
            }
            else
            {
                throw new NRuntimeException("No Parent assigned to component");
            }
        }

        void INWidget::initialize()
        {
            createContent();
        }

        void INWidget::setParent(INWidget * parent)
        {
            m_Parent = parent;
        }

        INWidget * INWidget::getParent()
        {
            return m_Parent;
        }

        INWidget * INWidget::getWidget(const NString & viewName)
        {
            return NWidgetProvider::getInstance()->getWidget(viewName);
        }
    }
}
