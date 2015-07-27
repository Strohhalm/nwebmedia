//
// Created by strohhalm on 22.06.15.
//

#ifndef NSERVICEFACTORYCONFIGCACHE_H
#define NSERVICEFACTORYCONFIGCACHE_H

#include <nbase/config/INConfigurationCache.h>
#include <nservice/config/NServiceFactoryConfigFile.h>

using namespace nox::configuration;

namespace nox
{
    namespace service
    {
        namespace configuration
        {
            class NServiceFactoryConfigCache : public INConfigurationCache<NString, NServiceFactoryConfig>
            {
            public:
                NServiceFactoryConfigCache();
                virtual ~NServiceFactoryConfigCache();
                virtual void load();
            protected:
                virtual void loadFile(NServiceFactoryConfigFile * file);
            };
        }
    }
}


#endif //NSERVICEFACTORYCONFIGCACHE_H
