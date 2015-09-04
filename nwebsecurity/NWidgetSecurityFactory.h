//
// Created by strohhalm on 04.09.15.
//

#ifndef NWEBMEDIA_NWIDGETSECURITYFACTORY_H
#define NWEBMEDIA_NWIDGETSECURITYFACTORY_H

#include <nweb/INWidgetFactory.h>
#include <nwebsecurity/NWebSecurity.h>

namespace nox
{
    namespace web
    {
        namespace security
        {
            class NWidgetSecurityFactory : public INWidgetFactory
            {
            public:
                NWidgetSecurityFactory();
                virtual ~NWidgetSecurityFactory();
                virtual INWidget * createWidget(const NString & widgetName);
            };
        }
    }
}

#endif //NWEBMEDIA_NWIDGETSECURITYFACTORY_H
