//
// Created by strohhalm on 19.06.15.
//

#ifndef IINSERVERSOCKET_H
#define IINSERVERSOCKET_H

#include <nbase/INObject.h>

namespace nox
{
    namespace network
    {
        class IINServerSocket : public INObject
        {
        public:
            virtual void run(bool async) = 0;
            virtual nint compareTo(const INObject * other) const
            {
                if (this == other)
                    return 0;
                if (this > other)
                    return 1;
                return -1;
            }
        };
    }
}


#endif //IINSERVERSOCKET_H
