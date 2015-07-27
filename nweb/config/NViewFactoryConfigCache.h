//
// Created by strohhalm on 29.06.15.
//

#ifndef NWEBMEDIA_NVIEWFACTORYCONFIGCACHE_H
#define NWEBMEDIA_NVIEWFACTORYCONFIGCACHE_H

#include <nbase/config/INConfigurationCache.h>
#include <nweb/config/NViewFactoryConfigFile.h>

using namespace nox::configuration;

namespace nox
{
    namespace web
    {
        namespace configuration
        {
            class NViewFactoryConfigCache : public INConfigurationCache<NString, NViewFactoryConfig>
            {
            public:
                NViewFactoryConfigCache();
                virtual ~NViewFactoryConfigCache();
                virtual void load();
            protected:
                virtual void loadFile(NViewFactoryConfigFile * file);
            };
        }
    }
}


#endif //NWEBMEDIA_NVIEWFACTORYCONFIGCACHE_H
