//
// Created by strohhalm on 04.09.15.
//

#ifndef NWEBMEDIA_NWIDGETCONFIGCACHE_H
#define NWEBMEDIA_NWIDGETCONFIGCACHE_H

#include <nbase/config/INConfigurationCache.h>
#include <nweb/config/NWidgetConfigFile.h>

using namespace nox::configuration;

namespace nox
{
    namespace web
    {
        namespace configuration
        {
            class NWidgetConfigCache : public INConfigurationCache<NString, NWidgetConfig>
            {
            public:
                NWidgetConfigCache();
                virtual ~NWidgetConfigCache();
                virtual void load();
            protected:
                virtual void loadFile(NWidgetConfigFile * file);
            };
        }
    }
}

#endif //NWEBMEDIA_NWIDGETCONFIGCACHE_H
