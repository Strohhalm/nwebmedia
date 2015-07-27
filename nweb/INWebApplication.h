//
// Created by strohhalm on 28.06.15.
//

#ifndef NWEBMEDIA_INWEBAPPLICATION_H
#define NWEBMEDIA_INWEBAPPLICATION_H

#include <nbase/INThread.h>
#include <nserviceclient/INServiceClientApplication.h>
#include <nweb/NWeb.h>
#include <nweb/localisation/NLocalisationProvider.h>
#include "NViewProvider.h"
#include "NNavigationProvider.h"

using namespace nox::service::client;
using namespace nox::web::localisation;

namespace nox
{
    namespace web
    {
        template<class SINGLETON, class WT_APPLICATION>
        class INWebApplication : public INServiceClientApplication<SINGLETON>
        {
        protected:
            NStaticAssertBaseOf(Wt::WApplication, WT_APPLICATION)
        protected:
            template<class WT_APP>
            class NWtThread : public INThread
            {
            public:
                static Wt::WApplication * createWtApplication(const Wt::WEnvironment & environment)
                {
                    return new WT_APP(environment);
                }
            protected:
                nint   m_Argc;
                char** m_Argv;
            public:
                NWtThread(nint argc, char * argv[]) : INThread()
                {
                    m_Argc = argc;
                    m_Argv = argv;
                }
                virtual ~NWtThread()
                {
                }
                virtual void run()
                {
                    Wt::WRun(m_Argc, m_Argv, &NWtThread::createWtApplication);
                }
            };
        protected:
            NViewProvider         * m_ViewProvider;
            NLocalisationProvider * m_LocalisationProvider;
            NNavigationProvider   * m_NavigationProvider;
        protected:
            INWebApplication() : INServiceClientApplication<SINGLETON>()
            {
                m_ViewProvider         = NViewProvider::getInstance();
                m_LocalisationProvider = NLocalisationProvider::getInstance();
                m_NavigationProvider   = NNavigationProvider::getInstance();

            }
            virtual ~INWebApplication()
            {
                if (m_ViewProvider != NULL)
                    NViewProvider::release();
                if (m_LocalisationProvider != NULL)
                    NLocalisationProvider::release();
                if (m_NavigationProvider != NULL)
                    NNavigationProvider::release();
            }
        public:
            virtual NViewProvider * getViewProvider()
            {
                return m_ViewProvider;
            }
            virtual void run(nint argc, char * argv[])
            {
                NWtThread<WT_APPLICATION> wtThread(argc, argv);

                wtThread.start();
                INServiceClientApplication<SINGLETON>::run(argc, argv);
                wtThread.join();
            }
            virtual void terminate()
            {
                INServiceClientApplication<SINGLETON>::terminate();

                Wt::WServer::instance()->stop();
            }
        };
    }
}

#endif //NWEBMEDIA_INWEBAPPLICATION_H
