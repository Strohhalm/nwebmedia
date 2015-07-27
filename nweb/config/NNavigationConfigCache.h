//
// Created by strohhalm on 30.06.15.
//

#ifndef NWEBMEDIA_NNAVIGATIONCONFIGCACHE_H
#define NWEBMEDIA_NNAVIGATIONCONFIGCACHE_H

#include <nbase/config/INConfigurationCache.h>
#include <nweb/config/NNavigationConfigFile.h>

using namespace nox::configuration;

namespace nox
{
    namespace web
    {
        namespace configuration
        {
            class NNavigationConfigCache : public INConfigurationCache<NString, NNavigationConfig>
            {
            public:
                NNavigationConfigCache();
                virtual ~NNavigationConfigCache();
                virtual void load();
            protected:
                virtual void loadFile(NNavigationConfigFile * file);
            };
        }
    }
}


#endif //NWEBMEDIA_NVIEWNAVIGATIONRULECACHE_H
