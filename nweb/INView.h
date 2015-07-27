//
// Created by strohhalm on 30.05.15.
//

#ifndef INVIEW_H
#define INVIEW_H

#include "NWeb.h"
#include "INSession.h"
#include <nbase/INObject.h>


namespace nox
{
    namespace web
    {
        class INView : public INObject , public Wt::WContainerWidget
        {
        protected:
            NString * m_ViewName;
            NString * m_Component;
            INSession * m_Session;
            INView * m_Parent;
        public:
            INView(const NString & component, const NString & viewName);
            INView(const NString & component, const NString & viewName, INView * parent);
            virtual ~INView();
            virtual void initialize();
            virtual const NString & getViewName() const;
            virtual const NString & getComponent() const;
            virtual INSession * getSession();
            virtual void setParent(INView * parent);
            virtual INView * getParent();
            virtual void navigate(const NString & outcome);
        protected:
            virtual const NString localize(const NString & name);
            virtual const NString localize(const NString & name, const NString & locale);
            virtual INView * getView(const NString & viewName);
            virtual void createView() = 0;
        };
    }
}


#endif //INVIEW_H

