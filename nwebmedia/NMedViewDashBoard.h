//
// Created by strohhalm on 16.07.15.
//

#ifndef NMEDVIEWDASHBOARD_H
#define NMEDVIEWDASHBOARD_H

#include <nweb/INMasterView.h>
#include <nwebmedia/NWebMedia.h>

namespace nox
{
    namespace web
    {
        namespace media
        {
            class NMedViewDashBoard : public INMasterView
            {
            public:
                NMedViewDashBoard();
                NMedViewDashBoard(INView * parent);
                virtual ~NMedViewDashBoard();
                virtual nint compareTo(const INObject * other) const;
            protected:
                virtual void createView();
            };
        }
    }
}

#endif //NMEDVIEWDASHBOARD_H
