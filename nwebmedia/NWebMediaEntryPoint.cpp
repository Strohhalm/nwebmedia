//
// Created by strohhalm on 16.07.15.
//

#include <nwebmedia/NViewMediaFactory.h>

using namespace nox::web;
using namespace nox::web::media;

extern "C"
{
    INViewFactory * createViewFactory(const NString & factoryName)
    {
        if (factoryName.compare(NXS(NViewMediaFactory)) == 0)
            return new NViewMediaFactory();
        return NULL;
    }

    void destroyViewFactory(INViewFactory * factory)
    {
        if (factory != NULL)
            delete factory;
    }
}