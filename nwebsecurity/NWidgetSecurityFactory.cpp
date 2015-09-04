//
// Created by strohhalm on 04.09.15.
//

#include <nwebsecurity/NWidgetSecurityFactory.h>

namespace nox
{
    namespace web
    {
        namespace security
        {
            NWidgetSecurityFactory::NWidgetSecurityFactory() : INWidgetFactory(NCOMPONENT_WEB_SECURITY, NXS(NWidgetSecurityFactory))
            {
            }

            NWidgetSecurityFactory::~NWidgetSecurityFactory()
            {
            }

            INWidget * NWidgetSecurityFactory::createWidget(const NString & widgetName)
            {
                return NULL;
            }
        }
    }
}