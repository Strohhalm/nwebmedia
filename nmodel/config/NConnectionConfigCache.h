//
// Created by strohhalm on 22.06.15.
//

#ifndef NCONNECTIONCONFIGCACHE_H
#define NCONNECTIONCONFIGCACHE_H

#include <nbase/config/INConfigurationCache.h>
#include <nmodel/config/NConnectionConfigFile.h>

using namespace nox::configuration;

namespace nox
{
    namespace model
    {
        namespace configuration
        {
            class NConnectionConfigCache : public INConfigurationCache<NString, NConnectionConfig>
            {
            public:
                NConnectionConfigCache();
                virtual ~NConnectionConfigCache();
                virtual void load();
            protected:
                virtual void loadFile(NConnectionConfigFile * file);
            };
        }
    }
}


#endif //NCONNECTIONCONFIGCACHE_H
