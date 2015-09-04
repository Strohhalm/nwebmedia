//
// Created by strohhalm on 04.09.15.
//

#ifndef NWEBMEDIA_INWIDGET_H
#define NWEBMEDIA_INWIDGET_H

#include <nweb/NWeb.h>
#include <nweb/INSession.h>
#include <nbase/INObject.h>

namespace nox
{
    namespace web
    {
        class INWidget : public INObject , public Wt::WContainerWidget
        {
        protected:
            NString     * m_Component;
            INSession   * m_Session;
            INWidget    * m_Parent;
        public:
            INWidget(const NString & component);
            INWidget(const NString & component, INWidget * parent);
            virtual ~INWidget();
            virtual void initialize();
            virtual const NString & getComponent() const;
            virtual INSession * getSession();
            virtual void setParent(INWidget * parent);
            virtual INWidget * getParent();
            virtual void navigate(const NString & outcome);
        protected:
            virtual const NString localize(const NString & name);
            virtual const NString localize(const NString & name, const NString & locale);
            virtual INWidget * getWidget(const NString & componentName);
            virtual void createContent() = 0;
        };
    }
}


#endif //NWEBMEDIA_INWIDGET_H
