//
// Created by strohhalm on 09.06.15.
//

#ifndef INSINGLETON_H
#define INSINGLETON_H

#include <nbase/INObject.h>

namespace nox
{
    template<class SINGLETON>
    class INSingleton : public INObject
    {
    protected:
        static SINGLETON * s_Instance;
        static boost::mutex     * s_Mutex;
    public:
        static SINGLETON * getInstance()
        {
            s_Mutex->lock();
            {
                if (s_Instance == NULL)
                    s_Instance = new SINGLETON();
            }
            s_Mutex->unlock();

            return s_Instance;
        }
        static void release()
        {
            s_Mutex->lock();
            {
                if (s_Instance != NULL)
                    delete s_Instance;
                s_Instance = NULL;
            }
            s_Mutex->unlock();
        }
    protected:
        INSingleton() : INObject()
        {
        }
        virtual ~INSingleton()
        {
        }
    };

    template<class SINGLETON>
    SINGLETON * INSingleton<SINGLETON>::s_Instance = NULL;

    template<class SINGLETON>
    boost::mutex * INSingleton<SINGLETON>::s_Mutex = new boost::mutex();
}

#endif //INSINGLETON_H
