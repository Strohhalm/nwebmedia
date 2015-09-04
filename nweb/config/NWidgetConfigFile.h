//
// Created by strohhalm on 04.09.15.
//

#ifndef NWEBMEDIA_NWIDGETCONFIGFILE_H
#define NWEBMEDIA_NWIDGETCONFIGFILE_H

#include <nbase/collection/NList.h>
#include <nbase/resource/INXmlInputFile.h>
#include <nweb/config/NWidgetConfig.h>

using namespace nox::collection;
using namespace nox::resource;

namespace nox
{
    namespace web
    {
        namespace configuration
        {
            class NWidgetConfigFile : public INXmlInputFile<INList<NWidgetConfig *>>
            {
            public:
                NWidgetConfigFile(const NString & fileName);
                virtual ~NWidgetConfigFile();
            protected:
                virtual INList<NWidgetConfig *> * parseXmlDocument(pugi::xml_document * document);
                virtual NWidgetConfig * parseConfigEntry(pugi::xml_node & node);
            };
        }
    }
}

#endif //NWEBMEDIA_NWIDGETCONFIGFILE_H
