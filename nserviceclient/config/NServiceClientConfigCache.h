//
// Created by strohhalm on 28.06.15.
//

#ifndef NWEBMEDIA_NSERVICECLIENTCONFIGCACHE_H
#define NWEBMEDIA_NSERVICECLIENTCONFIGCACHE_H

#include <nbase/config/INConfigurationCache.h>
#include <nserviceclient/config/NServiceClientConfigFile.h>

using namespace nox::configuration;

namespace nox
{
    namespace service
    {
        namespace client
        {
            namespace configuration
            {
                class NServiceClientConfigCache : public INConfigurationCache<NString, NServiceClientConfig>
                {
                public:
                    NServiceClientConfigCache();
                    virtual ~NServiceClientConfigCache();
                    virtual void load();
                protected:
                    virtual void loadFile(NServiceClientConfigFile * file);
                };
            }
        }
    }
}



#endif //NWEBMEDIA_NSERVICECLIENTCONFIGCACHE_H
