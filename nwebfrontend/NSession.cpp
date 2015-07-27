//
// Created by strohhalm on 30.06.15.
//

#include "NSession.h"

namespace nox
{
    NSession::NSession(const Wt::WEnvironment & environment) : INSession(environment)
    {
        setCssTheme("polished");
    }

    NSession::~NSession()
    {
    }

    nint NSession::compareTo(const INObject * other) const
    {
        return 0;
    }
}