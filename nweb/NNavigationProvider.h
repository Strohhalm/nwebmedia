//
// Created by strohhalm on 15.07.15.
//

#ifndef NWEBMEDIA_NNAVIGATIONPROVIDER_H
#define NWEBMEDIA_NNAVIGATIONPROVIDER_H

#include <nbase/INSingleton.h>
#include <nweb/config/NNavigationConfigCache.h>

using namespace nox::web::configuration;

namespace nox
{
    namespace web
    {
        class NNavigationProvider : public INSingleton<NNavigationProvider>
        {
            friend class INSingleton<NNavigationProvider>;
        protected:
            NNavigationConfigCache * m_NavigationCache;
        protected:
            NNavigationProvider();
            virtual ~NNavigationProvider();
        public:
            virtual const NString & resolve(const NString & view, const NString & outcome);
            virtual const NString & resolveInitialView();
            virtual nint compareTo(const INObject * other) const;
        };
    }
}

#endif //NWEBMEDIA_NNAVIGATIONPROVIDER_H
