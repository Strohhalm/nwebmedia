//
// Created by strohhalm on 14.07.15.
//

#include "INMasterView.h"
#include "NNavigationProvider.h"
#include "NViewProvider.h"

namespace nox
{
    namespace web
    {
        INMasterView::INMasterView(const NString & component, const NString & viewName) : INView(component, viewName)
        {
        }

        INMasterView::INMasterView(const NString & component, const NString & viewName, INView * parent) : INView(component, viewName, parent)
        {
        }

        INMasterView::~INMasterView()
        {
        }

        void INMasterView::initialize()
        {
            INView::initialize();

            m_Content = new Wt::WContainerWidget(this);
            m_Content->setId("__content__");

            addWidget(m_Content);
        }

        void INMasterView::setContentAreaStyleClass(const NString & styleClass)
        {
            if (m_Content != NULL) {
                m_Content->setStyleClass(styleClass);
            }
        }

        void INMasterView::navigate(const NString & outcome)
        {
            INView * view = NViewProvider::getInstance()->getView(NNavigationProvider::getInstance()->resolve(getViewName(), outcome));
            if (view != NULL)
            {
                view->setParent(this);

                m_Content->clear();
                m_Content->addWidget(view);
            }
        }
    }
}