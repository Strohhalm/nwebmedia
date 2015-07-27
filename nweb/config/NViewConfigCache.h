//
// Created by strohhalm on 29.06.15.
//

#ifndef NWEBMEDIA_NVIEWCONFIGCACHE_H
#define NWEBMEDIA_NVIEWCONFIGCACHE_H

#include <nbase/config/INConfigurationCache.h>
#include <nweb/config/NViewConfigFile.h>

using namespace nox::configuration;

namespace nox
{
    namespace web
    {
        namespace configuration
        {
            class NViewConfigCache : public INConfigurationCache<NString, NViewConfig>
            {
            public:
                NViewConfigCache();
                virtual ~NViewConfigCache();
                virtual void load();
            protected:
                virtual void loadFile(NViewConfigFile * file);
            };
        }
    }
}


#endif //NWEBMEDIA_NVIEWCONFIGCACHE_H
