//
// Created by strohhalm on 02.07.15.
//

#ifndef NWEBMEDIA_IINSERVICE_H
#define NWEBMEDIA_IINSERVICE_H

#include <nbase/INObject.h>
#include <nservice/exchange/INServiceExchange.h>

using namespace nox::service::exchange;

namespace nox
{
    namespace service
    {
        class IINService : public INObject
        {
        public:
            IINService();
            virtual ~IINService();
            virtual _IINServiceResponse * call(_IINServiceRequest * input, size_t size) = 0;
        };
    }
}


#endif //NWEBMEDIA_IINSERVICE_H
