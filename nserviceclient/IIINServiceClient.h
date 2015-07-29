//
// Created by strohhalm on 29.07.15.
//

#ifndef NWEBMEDIA_IIINSERVICECLIENT_H
#define NWEBMEDIA_IIINSERVICECLIENT_H

namespace nox
{
    namespace service
    {
        namespace client
        {
            class IIINServiceClient
            {
            public:
                virtual void release() = 0;
            };
        }
    }
}

#endif //NWEBMEDIA_IIINSERVICECLIENT_H
