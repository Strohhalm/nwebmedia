//
// Created by strohhalm on 27.06.15.
//

#include "INServiceClientFactory.h"

namespace nox
{
    namespace service
    {
        namespace client
        {
            INServiceClientFactory::INServiceClientFactory(const NString & componentName, const NString & factoryName) : INObject()
            {
                m_ComponentName = new NString(componentName);
                m_FactoryName = new NString(factoryName);
                m_IoService = new boost::asio::io_service();
                m_IoServiceWork = new boost::asio::io_service::work(*m_IoService);
                m_Thread = new boost::thread(boost::bind(&boost::asio::io_service::run, m_IoService));
            }

            INServiceClientFactory::~INServiceClientFactory()
            {
                if (m_ComponentName != NULL)
                    delete m_ComponentName;
                if (m_FactoryName != NULL)
                    delete m_FactoryName;
                if (m_IoServiceWork != NULL)
                    delete m_IoServiceWork;
                if (m_Thread != NULL)
                {
                    m_Thread->join();
                    delete m_Thread;
                }
                if (m_IoService != NULL)
                    delete m_IoService;
            }

            const NString& INServiceClientFactory::getComponentName() const
            {
                return *m_ComponentName;
            }

            const NString& INServiceClientFactory::getFactoryName() const
            {
                return *m_FactoryName;
            }

            INServiceClient * INServiceClientFactory::createServiceClient(const NString & serviceName, const NProtocol * protocol, const NString & service)
            {
                if (protocol == NProtocol::TCP)
                {
                    return createServiceClient(new NClientSocketTcp(service, *m_IoService), serviceName);
                }
                else if (protocol == NProtocol::UDP)
                {
                    return createServiceClient(new NClientSocketUdp(service, *m_IoService), serviceName);
                }
                else
                {
                    throw NRuntimeException("Unsupported Protocol");
                }
            }
            INServiceClient * INServiceClientFactory::createServiceClient(const NString & serviceName, const NProtocol * protocol, const NString & host, const NString & service)
            {
                if (protocol == NProtocol::TCP)
                {
                    return createServiceClient(new NClientSocketTcp(host, service, *m_IoService), serviceName);
                }
                else if (protocol == NProtocol::UDP)
                {
                    return createServiceClient(new NClientSocketUdp(host, service, *m_IoService), serviceName);
                }
                else
                {
                    throw NRuntimeException("Unsupported Protocol");
                }
            }
        }
    }
}