//
// Created by strohhalm on 28.06.15.
//

#ifndef NWEBMEDIA_NSERVICECLIENTPROVIDER_H
#define NWEBMEDIA_NSERVICECLIENTPROVIDER_H

#include <nbase/INSingleton.h>
#include <nbase/collection/INMap.h>
#include <nbase/plugin/NPlugin.h>
#include <nserviceclient/INServiceClientFactory.h>
#include <nserviceclient/config/NServiceClientConfigCache.h>
#include <nserviceclient/config/NServiceClientFactoryConfigCache.h>

using namespace nox::collection;
using namespace nox::plugin;
using namespace nox::service::client::configuration;

namespace nox
{
    namespace service
    {
        namespace client
        {
            class NServiceClientProvider : public INSingleton<NServiceClientProvider>
            {
                friend class INSingleton<NServiceClientProvider>;
            protected:
                INMap<NString, INServiceClientFactory *> * m_FactoryMap;
                INMap<NString, NPlugin *>                * m_PluginMap;
                NServiceClientConfigCache                * m_ServiceConfigCache;
                NServiceClientFactoryConfigCache         * m_FactoryConfigCache;
            protected:
                NServiceClientProvider();
                virtual ~NServiceClientProvider();
                virtual void init();
                virtual NPlugin * loadPlugin(const NString & libName);
                virtual INServiceClient * loadServiceClient(const NString & serviceClientName);
            public:
                template<class SERVICE_CLIENT_INTERFACE>
                SERVICE_CLIENT_INTERFACE * getServiceClient(const NString & serviceClientName)
                {
                    return dynamic_cast<SERVICE_CLIENT_INTERFACE *>(loadServiceClient(serviceClientName));
                }
                virtual nint compareTo(const INObject * other) const;
            };
        }
    }
}


#endif //NWEBMEDIA_NSERVICECLIENTPROVIDER_H
