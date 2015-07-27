//
// Created by strohhalm on 21.06.15.
//

#ifndef INSERVICEFACTORY_H
#define INSERVICEFACTORY_H

#include <nbase/NBaseType.h>
#include <nbase/INSingleton.h>
#include <nservice/INService.h>
#include <nservice/IINServiceFactory.h>
#include <nservice/network/NServiceServerSocketUdp.h>
#include <nservice/network/NServiceServerSocketTcp.h>

using namespace nox::network;
using namespace nox::service::network;

namespace nox
{
    namespace service
    {
        class INServiceFactory : public IINServiceFactory
        {
        protected:
            NString * m_ComponentName;
            NString * m_FactoryName;
        protected:
            template<class SERVICE>
            INService * create(NServiceConfig & serviceConfig)
            {
                return new SERVICE(serviceConfig);
            }
        public:
            INServiceFactory(const NString & componentName, const NString & factoryName);
            virtual ~INServiceFactory();
            virtual const NString & getComponentName() const;
            virtual const NString & getFactoryName() const;
            virtual INService * createService(NServiceConfig & serviceConfig) = 0;
            virtual nint compareTo(const INObject * other) const;
        };
    }
}

#define CreateService(SERVICE) \
    if (name.compare(NXS(SERVICE)) == 0) \
        return this->create<SERVICE>(networkConfig);

#endif //INSERVICEFACTORY_H
