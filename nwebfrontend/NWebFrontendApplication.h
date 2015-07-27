//
// Created by strohhalm on 28.06.15.
//

#ifndef NWEBMEDIA_NWEBFRONTENDAPPLICATION_H
#define NWEBMEDIA_NWEBFRONTENDAPPLICATION_H

#include <nweb/INWebApplication.h>
#include <nwebfrontend/NSession.h>

using namespace nox::web;

namespace nox
{
    class NWebFrontendApplication : public INWebApplication<NWebFrontendApplication, NSession>
    {
        friend class INSingleton<NWebFrontendApplication>;
    protected:
        NWebFrontendApplication();
        virtual ~NWebFrontendApplication();
        virtual nint compareTo(const INObject * other) const;
    };
}


#endif //NWEBMEDIA_NWEBFRONTENDAPPLICATION_H
