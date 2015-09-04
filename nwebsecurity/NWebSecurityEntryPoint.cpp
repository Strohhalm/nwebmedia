//
// Created by strohhalm on 30.06.15.
//

#include <nwebsecurity/NViewSecurityFactory.h>
#include <nwebsecurity/NWidgetSecurityFactory.h>

using namespace nox::web;
using namespace nox::web::security;

extern "C"
{
    INViewFactory * createViewFactory(const NString & factoryName)
    {
        if (factoryName.compare(NXS(NViewSecurityFactory)) == 0)
            return new NViewSecurityFactory();
        return NULL;
    }

    void destroyViewFactory(INViewFactory * factory)
    {
        if (factory != NULL)
            delete factory;
    }

    INWidgetFactory * createWidgetFactory(const NString & factoryName)
    {
        if (factoryName.compare(NXS(NWidgetSecurityFactory)) == 0)
            return new NWidgetSecurityFactory();
        return NULL;
    }

    void destroyWidgetFactory(INWidgetFactory * factory)
    {
        if (factory != NULL)
            delete factory;
    }
}