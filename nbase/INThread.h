//
// Created by strohhalm on 16.06.15.
//

#ifndef INTHREAD_H
#define INTHREAD_H

#include <nbase/NBase.h>
#include "INObject.h"

namespace nox
{
    class INThread : public INObject
    {
    protected:
        boost::thread * m_Thread;
    public:
        INThread();
        virtual ~INThread();
        virtual void start();
        virtual void run() = 0;
        virtual void join();
        virtual nint compareTo(const INObject * other) const;
    };
}


#endif //INTHREAD_H
