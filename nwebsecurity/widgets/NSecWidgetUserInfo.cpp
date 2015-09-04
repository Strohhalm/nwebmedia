//
// Created by strohhalm on 04.09.15.
//

#include <nwebsecurity/widgets/NSecWidgetUserInfo.h>

namespace nox
{
    namespace web
    {
        namespace security
        {
            namespace widget
            {
                NSecWidgetUserInfo::NSecWidgetUserInfo() : INWidget(NCOMPONENT_WEB_SECURITY)
                {

                }

                NSecWidgetUserInfo::NSecWidgetUserInfo(INWidget * parent) : INWidget(NCOMPONENT_WEB_SECURITY, parent)
                {

                }

                NSecWidgetUserInfo::~NSecWidgetUserInfo()
                {

                }

                void NSecWidgetUserInfo::createContent()
                {

                }

                nint NSecWidgetUserInfo::compareTo(const INObject * other) const
                {
                    return 0;
                }
            }
        }
    }
}