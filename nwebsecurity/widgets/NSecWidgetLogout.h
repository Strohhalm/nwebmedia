//
// Created by strohhalm on 04.09.15.
//

#ifndef NWEBMEDIA_NSECWIDGETLOGOUT_H
#define NWEBMEDIA_NSECWIDGETLOGOUT_H

#include <nwebsecurity/NWebSecurity.h>
#include <nweb/INWidget.h>

namespace nox
{
    namespace web
    {
        namespace security
        {
            namespace widget
            {
                class NSecWidgetLogout : public INWidget
                {
                public:
                    NSecWidgetLogout();
                    NSecWidgetLogout(INWidget * parent);
                    virtual ~NSecWidgetLogout();
                    virtual nint compareTo(const INObject * other) const;
                protected:
                    virtual void createContent();
                };
            }
        }
    }
}

#endif //NWEBMEDIA_NSECWIDGETLOGOUT_H
