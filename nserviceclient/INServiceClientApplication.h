//
// Created by strohhalm on 28.06.15.
//

#ifndef NWEBMEDIA_INSERVICECLIENTAPPLICATION_H
#define NWEBMEDIA_INSERVICECLIENTAPPLICATION_H

#include <nbase/INApplication.h>
#include "NServiceClientProvider.h"

namespace nox
{
    namespace service
    {
        namespace client
        {
            template<class SINGLETON>
            class INServiceClientApplication : public INApplication<SINGLETON>
            {
            protected:
                NServiceClientProvider * m_ServiceClientProvider;
            protected:
                INServiceClientApplication() : INApplication<SINGLETON>()
                {
                    m_ServiceClientProvider = NServiceClientProvider::getInstance();
                }
                virtual ~INServiceClientApplication()
                {
                    if (m_ServiceClientProvider != NULL)
                        NServiceClientProvider::release();
                }
                virtual NServiceClientProvider * getServiceClientProvider()
                {
                    return m_ServiceClientProvider;
                }
            };
        }
    }
}

#endif //NWEBMEDIA_INSERVICECLIENTAPPLICATION_H
