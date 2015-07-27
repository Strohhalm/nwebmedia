//
// Created by strohhalm on 16.07.15.
//

#include "NMedViewDashBoard.h"

namespace nox
{
    namespace web
    {
        namespace media
        {
            NMedViewDashBoard::NMedViewDashBoard() : INMasterView(NCOMPONENT_WEB_MEDIA, NXS(NMedViewDashBoard))
            {
            }

            NMedViewDashBoard::NMedViewDashBoard(INView * parent) : INMasterView(NCOMPONENT_WEB_MEDIA, NXS(NMedViewDashBoard), parent)
            {
            }

            NMedViewDashBoard::~NMedViewDashBoard()
            {
            }

            void NMedViewDashBoard::createView()
            {
                Wt::WPanel * panHeader = NULL;
                Wt::WPanel * panMenu = NULL;

                panHeader = new Wt::WPanel(this);
                panHeader->setId("__header__");
                panHeader->addStyleClass("panel header");

                panMenu = new Wt::WPanel(this);
                panMenu->setId("__footer__");
                panMenu->addStyleClass("panel footer");

                addWidget(panHeader);
                addWidget(panMenu);
            }

            nint NMedViewDashBoard::compareTo(const INObject * other) const
            {
                return 0;
            }
        }
    }
}