//
// Created by strohhalm on 17.06.15.
//

#ifndef NSERVICEPROVIDER_H
#define NSERVICEPROVIDER_H

#include <boost/asio/io_service.hpp>

#include <nbase/INSingleton.h>
#include <nbase/plugin/NPlugin.h>
#include <nbase/collection/NMap.h>
#include <nservice/IINServiceFactory.h>
#include <nservice/config/NServiceFactoryConfigCache.h>
#include <nservice/config/NServiceConfigCache.h>

using namespace nox::plugin;
using namespace nox::collection;
using namespace nox::service::configuration;

namespace nox
{
    namespace service
    {
        class NServiceProvider : public INSingleton<NServiceProvider>
        {
            friend class INSingleton<NServiceProvider>;
        protected:
            INMap<NString, NPlugin *>           * m_PluginMap;
            INMap<NString, IINServiceFactory *> * m_FactoryMap;
            INMap<NString, INService *>         * m_ServiceMap;
            NServiceConfigCache                 * m_ServiceConfigCache;
            NServiceFactoryConfigCache          * m_FactoryConfigCache;
        protected:
            NServiceProvider();
            virtual ~NServiceProvider();
            virtual void init();
            virtual void loadFactories();
            virtual void loadServices();
            virtual NPlugin * loadPlugin(const NString & libName);
        public:
            virtual void run();
            virtual nint compareTo(const INObject * other) const;
        };
    }
}

#endif //NSERVICEPROVIDER_H
