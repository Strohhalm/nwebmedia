//
// Created by strohhalm on 16.06.15.
//

#include <nservice/INService.h>
#include <nmodel/NTransactionPool.h>
#include <nservice/network/NServiceServerSocketTcp.h>
#include <nservice/network/NServiceServerSocketUdp.h>

using namespace nox::model;
using namespace nox::service::network;

namespace nox
{
    namespace service
    {
        nint INService::IINServiceCallBack::compareTo(const INObject * other) const
        {
            if (this == other)
                return 0;
            if (this > other)
                return 1;
            return -1;
        }

        INService::INService(NServiceConfig & serviceConfig) : IINService()
        {
            m_ServiceName = new NString(serviceConfig.getService());
            m_FunctionMap = new NMap<NString, IINServiceCallBack *>();
            if (serviceConfig.getProtocol() == NProtocol::TCP)
            {
                m_Socket = new NServiceServerSocketTcp(this, serviceConfig);
            }
            else
            {
                m_Socket = new NServiceServerSocketUdp(this, serviceConfig);
            }
        }

        INService::~INService()
        {
            if (m_ServiceName != NULL)
                delete m_ServiceName;
            if (m_FunctionMap != NULL)
                delete m_FunctionMap;
        }

        void INService::registerFunction(const NString & name, IINServiceCallBack * callBack)
        {
            if (!m_FunctionMap->contains(name))
            {
                m_FunctionMap->add(name, callBack);
            }
            else
            {
                if (callBack != NULL)
                    delete callBack;
                throw NRuntimeException("Function is allready registered");
            }
        }

        void INService::unRegisterFunction(const NString & name)
        {
            if (m_FunctionMap->contains(name))
            {
                m_FunctionMap->remove(name);
            }
        }

        INService::IINServiceCallBack * INService::getFunction(const NString & name)
        {
            if (m_FunctionMap->contains(name))
                return m_FunctionMap->get(name);
            return NULL;
        }

        _IINServiceResponse * INService::call(_IINServiceRequest * input, size_t size)
        {
            _IINServiceResponse * result = NULL;
            if (input->Head.Control.Size != size)
                throw NRuntimeException("Request is incomplete");
            if (m_FunctionMap->contains(input->Head.Control.FunctionName)) {
                try
                {
                    NTransactionPool::getInstance()->createTransaction();

                    result = m_FunctionMap->get(input->Head.Control.FunctionName)->call(input);

                    NTransactionPool::getInstance()->getCurrentTransaction()->commit();
                    NTransactionPool::getInstance()->destroyCurrentTransaction();
                }
                catch (...)
                {
                    NTransactionPool::getInstance()->getCurrentTransaction()->rollback();
                    NTransactionPool::getInstance()->destroyCurrentTransaction();

                    throw;
                }
            } else {
                throw NRuntimeException(NString("Servicefunction ").append(input->Head.Control.FunctionName).append(" is unknown"));
            }
            return result;
        }

        void INService::listen()
        {
            m_Socket->run(true);
        }

        const NString & INService::getServiceName() const
        {
            return *m_ServiceName;
        }

        nint INService::compareTo(const INObject * other) const
        {
            if (this == other)
                return 0;
            try
            {
                const INService * obj = dynamic_cast<const INService *>(other);
                if (obj != NULL)
                {
                    return getServiceName().compare(obj->getServiceName());
                }
                else
                {
                    return 1;
                }
            }
            catch (bad_cast &)
            {
                return 1;
            }
        }
    }
}