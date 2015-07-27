//
// Created by strohhalm on 30.06.15.
//

#ifndef NWEBMEDIA_NVIEWSECURITYFACTORY_H
#define NWEBMEDIA_NVIEWSECURITYFACTORY_H

#include <nweb/INViewFactory.h>
#include <nwebsecurity/NWebSecurity.h>

namespace nox
{
    namespace web
    {
        namespace security
        {
            class NViewSecurityFactory : public INViewFactory
            {
            public:
                NViewSecurityFactory();
                virtual ~NViewSecurityFactory();
                virtual INView * createView(const NString & viewName);
            };
        }
    }
}

#endif //NWEBMEDIA_NVIEWSECURITYFACTORY_H
