//
// Created by strohhalm on 22.06.15.
//

#ifndef NSERVICECONFIGCACHE_H
#define NSERVICECONFIGCACHE_H

#include <nbase/config/INConfigurationCache.h>
#include <nservice/config/NServiceConfigFile.h>

using namespace nox::configuration;

namespace nox
{
    namespace service
    {
        namespace configuration
        {
            class NServiceConfigCache : public INConfigurationCache<NString, NServiceConfig>
            {
            public:
                NServiceConfigCache();
                virtual ~NServiceConfigCache();
                virtual void load();
            protected:
                virtual void loadFile(NServiceConfigFile * file);
            };
        }
    }
}

#endif //NSERVICECONFIGURATIONCACHE_H
