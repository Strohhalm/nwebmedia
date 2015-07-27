//
// Created by strohhalm on 28.06.15.
//

#ifndef NWEBMEDIA_NSERVICECLIENTFACTORYCONFIGCACHE_H
#define NWEBMEDIA_NSERVICECLIENTFACTORYCONFIGCACHE_H

#include <nbase/config/INConfigurationCache.h>
#include <nserviceclient/config/NServiceClientFactoryConfigFile.h>

using namespace nox::configuration;

namespace nox
{
    namespace service
    {
        namespace client
        {
            namespace configuration
            {
                class NServiceClientFactoryConfigCache : public INConfigurationCache<NString, NServiceClientFactoryConfig>
                {
                public:
                    NServiceClientFactoryConfigCache();
                    virtual ~NServiceClientFactoryConfigCache();
                    virtual void load();
                protected:
                    virtual void loadFile(NServiceClientFactoryConfigFile * file);
                };
            }
        }
    }
}

#endif //NWEBMEDIA_NSERVICECLIENTFACTORYCONFIGCACHE_H
