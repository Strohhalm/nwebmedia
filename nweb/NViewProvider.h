//
// Created by strohhalm on 29.06.15.
//

#ifndef NWEBMEDIA_NVIEWPROVIDER_H
#define NWEBMEDIA_NVIEWPROVIDER_H

#include <nbase/INSingleton.h>
#include <nbase/collection/NMap.h>
#include <nbase/plugin/NPlugin.h>
#include <nweb/config/NViewFactoryConfigCache.h>
#include <nweb/config/NViewConfigCache.h>
#include "INViewFactory.h"

using namespace nox::plugin;
using namespace nox::collection;
using namespace nox::web::configuration;

namespace nox
{
    namespace web
    {
        class NViewProvider : public INSingleton<NViewProvider>
        {
            friend class INSingleton<NViewProvider>;
        protected:
            INMap<NString, NPlugin *>       * m_PluginMap;
            INMap<NString, INViewFactory *> * m_FactoryMap;
            NViewFactoryConfigCache         * m_FactoryConfigCache;
            NViewConfigCache                * m_ViewConfigCache;
        protected:
            NViewProvider();
            virtual ~NViewProvider();
            virtual void init();
            virtual NPlugin * loadPlugin(const NString & libName);
        public:
            virtual INView * getView(const NString & viewName);
            virtual nint compareTo(const INObject * other) const;
        };
    }
}


#endif //NWEBMEDIA_NVIEWPROVIDER_H
