//
// Created by strohhalm on 28.06.15.
//

#ifndef NWEBMEDIA_INAPPLICATION_H
#define NWEBMEDIA_INAPPLICATION_H

#include <nbase/INSingleton.h>
#include <nbase/collection/NList.h>

using namespace nox::collection;

namespace nox
{
    template<class SINGLETON>
    class INApplication : public INSingleton<SINGLETON>
    {
        friend class INSingleton<SINGLETON>;
    protected:
        bool               m_IsTerminated;
        INList<NString>  * m_CommandLineArguments;
    protected:
        INApplication()
        {
            m_IsTerminated  = false;
            m_CommandLineArguments = new NList<NString>();

            signal(SIGTERM, &INApplication::terminateSignal);
            signal(SIGABRT, &INApplication::terminateSignal);
        }
        virtual ~INApplication()
        {
        }
        static void terminateSignal(int signal)
        {
            SINGLETON::getInstance()->terminate();
        }
    public:
        virtual void run(nint argc, char * argv[])
        {
            for (int i = 0; i < argc; i++) {
                m_CommandLineArguments->add(argv[i]);
            }
            while (!m_IsTerminated)
            {
                boost::this_thread::sleep(boost::posix_time::milliseconds(100));
            }
        }
        virtual void terminate()
        {
            m_IsTerminated = true;
        }
    };
}


#endif //NWEBMEDIA_INAPPLICATION_H
