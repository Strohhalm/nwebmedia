//
// Created by strohhalm on 04.09.15.
//

#ifndef NWEBMEDIA_NWIDGETFACTORYCONFIGFILE_H
#define NWEBMEDIA_NWIDGETFACTORYCONFIGFILE_H

#include <nbase/collection/NList.h>
#include <nbase/resource/INXmlInputFile.h>
#include <nweb/config/NWidgetFactoryConfig.h>

using namespace nox::collection;
using namespace nox::resource;

namespace nox
{
    namespace web
    {
        namespace configuration
        {
            class NWidgetFactoryConfigFile : public INXmlInputFile<INList<NWidgetFactoryConfig *>>
            {
            public:
                NWidgetFactoryConfigFile(const NString & fileName);
                virtual ~NWidgetFactoryConfigFile();
            protected:
                virtual INList<NWidgetFactoryConfig *> * parseXmlDocument(pugi::xml_document * document);
                virtual NWidgetFactoryConfig * parseConfigEntry(pugi::xml_node & node);
            };
        }
    }
}

#endif //NWEBMEDIA_NWIDGETFACTORYCONFIGFILE_H
