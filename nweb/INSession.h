//
// Created by strohhalm on 30.06.15.
//

#ifndef NWEBMEDIA_INSESSION_H
#define NWEBMEDIA_INSESSION_H

#include <nbase/INObject.h>
#include <nweb/NWeb.h>
#include <nweb/config/NNavigationConfigCache.h>
#include <nweb/resource/NCascadingStyleSheetsFile.h>

using namespace nox::web::configuration;
using namespace nox::web::resource;

namespace nox
{
    namespace web
    {
        class INSession : public Wt::WApplication , public INObject
        {
        protected:
            NInteger                 * m_UserId;
        public:
            INSession(const Wt::WEnvironment& environment);
            virtual ~INSession();
            virtual void setUserId(const NInteger & userId);
            virtual const NInteger & getUserId();
            virtual void navigateByRule(const NString & currentView, const NString & outcome);
            virtual void notify(const Wt::WEvent& e);
        protected:
            virtual Wt::WWidget * createErrorWidget();
        };
    }
}

#endif //NWEBMEDIA_INSESSION_H
