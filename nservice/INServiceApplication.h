//
// Created by strohhalm on 28.06.15.
//

#ifndef NWEBMEDIA_INSERVICEAPPLICATION_H
#define NWEBMEDIA_INSERVICEAPPLICATION_H

#include <nbase/INApplication.h>
#include "NServiceProvider.h"

namespace nox
{
    namespace service
    {
        template<class SINGLETON>
        class INServiceApplication : public INApplication<SINGLETON>
        {
            friend class INSingleton<SINGLETON>;
        protected:
            NServiceProvider * m_ServiceProvider;
        protected:
            INServiceApplication() : INApplication<SINGLETON>()
            {
                m_ServiceProvider = NServiceProvider::getInstance();
            }
            virtual ~INServiceApplication()
            {
                if (m_ServiceProvider != NULL)
                    NServiceProvider::release();
            }
        public:
            virtual NServiceProvider * getServiceProvider()
            {
                return m_ServiceProvider;
            }
            virtual void run(nint argc, char * argv[])
            {
                m_ServiceProvider->run();

                INApplication<SINGLETON>::run(argc, argv);
            }
        };
    }
}


#endif //NWEBMEDIA_INSERVICEAPPLICATION_H
