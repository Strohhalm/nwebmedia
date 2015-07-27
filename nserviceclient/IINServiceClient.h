//
// Created by strohhalm on 27.06.15.
//

#ifndef NWEBMEDIA_IINSERVICECLIENT_H
#define NWEBMEDIA_IINSERVICECLIENT_H

#include <nbase/INObject.h>

namespace nox
{
    namespace service
    {
        namespace client
        {
            class IINServiceClient : public INObject
            {
            public:
                IINServiceClient();
                virtual ~IINServiceClient();
            };
        }
    }
}


#endif //NWEBMEDIA_IINSERVICECLIENT_H
