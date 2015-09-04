//
// Created by strohhalm on 04.09.15.
//

#ifndef NWEBMEDIA_NWIDGETPROVIDER_H
#define NWEBMEDIA_NWIDGETPROVIDER_H

#include <nbase/INSingleton.h>
#include <nbase/collection/NMap.h>
#include <nbase/plugin/NPlugin.h>
#include <nweb/INWidgetFactory.h>
#include <nweb/config/NWidgetFactoryConfigCache.h>
#include <nweb/config/NWidgetConfigCache.h>

using namespace nox::plugin;
using namespace nox::collection;
using namespace nox::web::configuration;

namespace nox
{
    namespace web
    {
        class NWidgetProvider : public INSingleton<NWidgetProvider>
        {
            friend class INSingleton<NWidgetProvider>;
        protected:
            INMap<NString, NPlugin *>         * m_PluginMap;
            INMap<NString, INWidgetFactory *> * m_FactoryMap;
            NWidgetFactoryConfigCache         * m_FactoryConfigCache;
            NWidgetConfigCache                * m_WidgetConfigCache;
        protected:
            NWidgetProvider();
            virtual ~NWidgetProvider();
            virtual void init();
            virtual NPlugin * loadPlugin(const NString & libName);
        public:
            virtual INWidget * getWidget(const NString & widgetName);
            virtual nint compareTo(const INObject * other) const;
        };
    }
}

#endif //NWEBMEDIA_NWIDGETPROVIDER_H
