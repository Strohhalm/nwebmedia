//
// Created by strohhalm on 04.09.15.
//

#ifndef NWEBMEDIA_NSECWIDGETUSERINFO_H
#define NWEBMEDIA_NSECWIDGETUSERINFO_H

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
                class NSecWidgetUserInfo : public INWidget
                {
                public:
                    NSecWidgetUserInfo();
                    NSecWidgetUserInfo(INWidget * parent);
                    virtual ~NSecWidgetUserInfo();
                    virtual nint compareTo(const INObject * other) const;
                protected:
                    virtual void createContent();
                };
            }
        }
    }
}

#endif //NWEBMEDIA_NSECWIDGETUSERINFO_H
