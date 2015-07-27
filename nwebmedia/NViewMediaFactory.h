//
// Created by strohhalm on 16.07.15.
//

#ifndef NWEBMEDIA_NVIEWMEDIAFACTORY_H
#define NWEBMEDIA_NVIEWMEDIAFACTORY_H

#include <nweb/INViewFactory.h>
#include <nwebmedia/NWebMedia.h>

namespace nox
{
    namespace web
    {
        namespace media
        {
            class NViewMediaFactory : public INViewFactory
            {
            public:
                NViewMediaFactory();
                virtual ~NViewMediaFactory();
                virtual INView * createView(const NString & viewName);
            };
        }
    }
}


#endif //NWEBMEDIA_NVIEWMEDIAFACTORY_H
