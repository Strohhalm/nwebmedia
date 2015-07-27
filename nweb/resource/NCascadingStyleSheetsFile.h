//
// Created by strohhalm on 18.07.15.
//

#ifndef NWEBMEDIA_NCASCADINGSTYLESHEETSFILE_H
#define NWEBMEDIA_NCASCADINGSTYLESHEETSFILE_H

#include <nbase/resource/INResource.h>

using namespace nox::resource;

namespace nox
{
    namespace web
    {
        namespace resource
        {
            class NCascadingStyleSheetsFile : public INResource
            {
            public:
                NCascadingStyleSheetsFile(const NString & fileName);
                virtual ~NCascadingStyleSheetsFile();
                virtual nint compareTo(const INObject * other) const;
            };
        }
    }
}

#define CSS_SUFFIX ".css"

#endif //NWEBMEDIA_NCASCADINGSTYLESHEETSFILE_H
