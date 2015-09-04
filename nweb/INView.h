//
// Created by strohhalm on 30.05.15.
//

#ifndef INVIEW_H
#define INVIEW_H

#include "INWidget.h"

namespace nox
{
    namespace web
    {
        class INView : public INWidget
        {
        protected:
            NString   * m_ViewName;
        public:
            INView(const NString & component);
            INView(const NString & component, INWidget * parent);
            virtual ~INView();
            virtual void setViewName(const NString & name);
            virtual const NString & getViewName() const;
            virtual void navigate(const NString & outcome);
        protected:
            virtual INView * getView(const NString & viewName);
        };
    }
}


#endif //INVIEW_H

