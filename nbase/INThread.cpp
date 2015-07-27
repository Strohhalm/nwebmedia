//
// Created by strohhalm on 16.06.15.
//

#include "INThread.h"

namespace nox
{
    INThread::INThread() : INObject()
    {
        m_Thread = NULL;
    }

    INThread::~INThread()
    {
        if (m_Thread != NULL)
        {
            delete m_Thread;
        }
    }

    void INThread::start()
    {
        m_Thread = new boost::thread(boost::bind(&INThread::run, this));
    }

    void INThread::join()
    {
        if (m_Thread != NULL)
            m_Thread->join();
    }

    nint INThread::compareTo(const INObject * other) const
    {
        if (this == other)
            return 0;
        try
        {
            const INThread * obj = dynamic_cast<const INThread *>(other);

            if (obj != NULL)
            {
                if (this > obj)
                    return 1;
                return -1;
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