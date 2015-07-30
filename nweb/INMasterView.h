//
// Created by strohhalm on 14.07.15.
//

#ifndef NWEBMEDIA_INMASTERVIEW_H
#define NWEBMEDIA_INMASTERVIEW_H

#include <nweb/INView.h>

namespace nox
{
    namespace web
    {
        class INMasterView : public INView
        {
        protected:
            Wt::WContainerWidget * m_Header;
            Wt::WContainerWidget * m_Content;
        public:
            INMasterView(const NString & component, const NString & viewName);
            INMasterView(const NString & component, const NString & viewName, INView * parent);
            virtual ~INMasterView();
            virtual void initialize();
            virtual void setContentAreaStyleClass(const NString & styleClass);
            virtual void navigate(const NString & outcome);
        };
    }
}


#endif //NWEBMEDIA_INMASTERVIEW_H
