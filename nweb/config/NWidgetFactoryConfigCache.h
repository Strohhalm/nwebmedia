//
// Created by strohhalm on 04.09.15.
//

#ifndef NWEBMEDIA_NWIDGETFACTORYCONFIGCACHE_H
#define NWEBMEDIA_NWIDGETFACTORYCONFIGCACHE_H

#include <nbase/config/INConfigurationCache.h>
#include <nweb/config/NWidgetFactoryConfigFile.h>

using namespace nox::configuration;

namespace nox
{
    namespace web
    {
        namespace configuration
        {
            class NWidgetFactoryConfigCache : public INConfigurationCache<NString, NWidgetFactoryConfig>
            {
            public:
                NWidgetFactoryConfigCache();
                virtual ~NWidgetFactoryConfigCache();
                virtual void load();
            protected:
                virtual void loadFile(NWidgetFactoryConfigFile * file);
            };
        }
    }
}

#endif //NWEBMEDIA_NWIDGETFACTORYCONFIGCACHE_H
