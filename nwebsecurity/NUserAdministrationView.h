//
// Created by strohhalm on 18.07.15.
//

#ifndef NWEBMEDIA_NUSERADMINISTRATIONVIEW_H
#define NWEBMEDIA_NUSERADMINISTRATIONVIEW_H

#include <nweb/INView.h>
#include <nwebsecurity/NWebSecurity.h>

namespace nox
{
    namespace web
    {
        namespace security
        {
            class NUserAdministrationView : public INView
            {
            public:
                NUserAdministrationView();
                virtual ~NUserAdministrationView();
            protected:
                virtual void createView();
            };
        }
    }
}

#endif //NWEBMEDIA_NUSERADMINISTRATIONVIEW_H
