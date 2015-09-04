//
// Created by strohhalm on 04.09.15.
//

#include <nwebsecurity/widgets/NSecWidgetLogout.h>

namespace nox
{
    namespace web
    {
        namespace security
        {
            namespace widget
            {
                NSecWidgetLogout::NSecWidgetLogout() : INWidget(NCOMPONENT_WEB_SECURITY)
                {
                }

                NSecWidgetLogout::NSecWidgetLogout(INWidget * parent) : INWidget(NCOMPONENT_WEB_SECURITY, parent)
                {
                }

                NSecWidgetLogout::~NSecWidgetLogout()
                {
                }

                void NSecWidgetLogout::createContent()
                {
                }

                nint NSecWidgetLogout::compareTo(const INObject * other) const
                {
                }
            }
        }
    }
}