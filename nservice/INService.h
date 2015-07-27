//
// Created by strohhalm on 16.06.15.
//

#ifndef INSERVICE_H
#define INSERVICE_H

#include <nbase/NAssert.h>
#include <nbase/INObject.h>
#include <nbase/enumeration/NProtocol.h>
#include <nbase/network/IINServerSocket.h>
#include <nservice/IINService.h>
#include <nservice/NServiceDefines.h>
#include <nservice/config/NServiceConfig.h>
#include <nservice/exchange/INServiceExchange.h>

using namespace nox::enumeration;
using namespace nox::service::configuration;
using namespace nox::service::exchange;
using namespace nox::network;

namespace nox
{
    namespace service
    {
        class INService : public IINService
        {
        public:
            class IINServiceCallBack : public INObject
            {
            public:
                virtual _IINServiceResponse * call(_IINServiceRequest * input) = 0;
                virtual nint compareTo(const INObject * other) const;
            };
            template<class INPUT, class OUTPUT>
            class INServiceCallBack : public IINServiceCallBack
            {
            protected:
                NStaticAssertBaseOf(IINServiceRequest, INPUT);
                NStaticAssertBaseOf(IINServiceResponse, OUTPUT);
                NStaticAssert(!is_pointer<INPUT>::value && !is_pointer<OUTPUT>::value);
            public:
                virtual _IINServiceResponse * call(_IINServiceRequest * input)
                {
                    INPUT  * request  = NULL;
                    OUTPUT * response = NULL;

                    typename INPUT::structType  * _requ = static_cast<typename INPUT::structType *>(input);
                    typename OUTPUT::structType * _resp = NULL;
                    try
                    {
                        request = new INPUT(*_requ);
                        _resp   = new typename OUTPUT::structType();

                        response = callFunction(request);
                        response->toStruct(*_resp);

                        if (request != NULL)
                            delete request;
                        if (response != NULL)
                            delete response;
                    }
                    catch (...)
                    {
                        if (request != NULL)
                            delete request;
                        if (response != NULL)
                            delete response;
                        if (_resp != NULL)
                            delete _resp;

                        throw;
                    }
                    return _resp;
                }
                virtual OUTPUT * callFunction(INPUT * input) = 0;
            };
        protected:
            NString                              * m_ServiceName;
            IINServerSocket                      * m_Socket;
            INMap<NString, IINServiceCallBack *> * m_FunctionMap;
        public:
            INService(NServiceConfig & serviceConfig);
            virtual ~INService();
            virtual const NString & getServiceName() const;
            virtual _IINServiceResponse * call(_IINServiceRequest * input, size_t size);
            virtual void listen();
            virtual nint compareTo(const INObject * other) const;
        protected:
            virtual IINServiceCallBack * getFunction(const NString & name);
            virtual void registerFunction(const NString & name, IINServiceCallBack * callBack);
            virtual void unRegisterFunction(const NString & name);
        };
    }
}

#endif //INSERVICE_H
