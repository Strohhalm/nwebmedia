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
        INView::INView(const NString & component) : INWidget(component)
        {
            m_ViewName = new NString();
        }

        INView::INView(const NString & component, INWidget * parent) : INWidget(component, parent)
        {
            m_ViewName = new NString();
        }

        INView::~INView()
        {
            if (m_ViewName != NULL)
                delete m_ViewName;
        }

        void INView::setViewName(const NString & name)
        {
            m_ViewName->assign(name);
        }

        const NString & INView::getViewName() const
        {
            return *m_ViewName;
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

        INView * INView::getView(const NString & viewName)
        {
            return NViewProvider::getInstance()->getView(viewName);
        }
    }
}