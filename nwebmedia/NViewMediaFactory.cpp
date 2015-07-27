//
// Created by strohhalm on 16.07.15.
//

#include "NViewMediaFactory.h"
#include "NMedViewDashBoard.h"

namespace nox
{
    namespace web
    {
        namespace media
        {
            NViewMediaFactory::NViewMediaFactory() : INViewFactory(NCOMPONENT_WEB_MEDIA, NXS(NViewMediaFactory))
            {
            }

            NViewMediaFactory::~NViewMediaFactory()
            {
            }

            INView * NViewMediaFactory::createView(const NString & viewName)
            {
                if (viewName.compare(NXS(NMedViewDashBoard)) == 0)
                    return new NMedViewDashBoard();
                return NULL;
            }
        }
    }
}