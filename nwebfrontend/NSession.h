//
// Created by strohhalm on 30.06.15.
//

#ifndef NWEBMEDIA_NSESSION_H
#define NWEBMEDIA_NSESSION_H

#include <nweb/INSession.h>

using namespace nox::web;

namespace nox
{
    class NSession : public INSession
    {
    public:
        NSession(const Wt::WEnvironment& environment);
        virtual ~NSession();
        virtual nint compareTo(const INObject * other) const;
    };
}


#endif //NWEBMEDIA_NSESSION_H
