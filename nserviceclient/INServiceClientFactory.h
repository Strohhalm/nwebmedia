//
// Created by strohhalm on 27.06.15.
//

#ifndef NWEBMEDIA_INSERVICECLIENTFACTORY_H
#define NWEBMEDIA_INSERVICECLIENTFACTORY_H

#include <nbase/INObject.h>
#include <nbase/enumeration/NProtocol.h>
#include <nbase/network/NClientSocketTcp.h>
#include <nbase/network/NClientSocketUdp.h>
#include <nserviceclient/INServiceClient.h>

using namespace nox::enumeration;
using namespace nox::network;

namespace nox
{
    namespace service
    {
        namespace client
        {
            class INServiceClientFactory : public INObject
            {
            protected:
                NString * m_ComponentName;
                NString * m_FactoryName;
                boost::asio::io_service * m_IoService;
                boost::asio::io_service::work * m_IoServiceWork;
                boost::thread                 * m_Thread;
            public:
                INServiceClientFactory(const NString & componentName, const NString & factoryName);
                virtual ~INServiceClientFactory();
                virtual const NString & getComponentName() const;
                virtual const NString & getFactoryName() const;
                virtual INServiceClient * createServiceClient(const NString & serviceName, const NProtocol * protocol, const NString & service);
                virtual INServiceClient * createServiceClient(const NString & serviceName, const NProtocol * protocol, const NString & host, const NString & service);
            protected:
                virtual INServiceClient * createServiceClient(IINClientSocket * socket, const NString & serviceName) = 0;
            };
        }
    }
}


#endif //NWEBMEDIA_INSERVICECLIENTFACTORY_H
