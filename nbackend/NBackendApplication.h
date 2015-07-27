//
// Created by strohhalm on 28.06.15.
//

#ifndef NWEBMEDIA_NBACKENDAPPLICATION_H
#define NWEBMEDIA_NBACKENDAPPLICATION_H

#include <nservice/INServiceApplication.h>

using namespace nox::service;

namespace nox
{
    class NBackendApplication : public INServiceApplication<NBackendApplication>
    {
        friend class INSingleton<NBackendApplication>;
    protected:
        NBackendApplication();
        virtual ~NBackendApplication();
        virtual nint compareTo(const INObject * other) const;
    };
}


#endif //NWEBMEDIA_NBACKENDAPPLICATION_H
