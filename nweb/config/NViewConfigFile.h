//
// Created by strohhalm on 29.06.15.
//

#ifndef NWEBMEDIA_NVIEWCONFIGFILE_H
#define NWEBMEDIA_NVIEWCONFIGFILE_H

#include <nbase/collection/NList.h>
#include <nbase/resource/INXmlInputFile.h>
#include <nweb/config/NViewConfig.h>

using namespace nox::collection;
using namespace nox::resource;

namespace nox
{
    namespace web
    {
        namespace configuration
        {
            class NViewConfigFile : public INXmlInputFile<INList<NViewConfig *>>
            {
            public:
                NViewConfigFile(const NString & fileName);
                virtual ~NViewConfigFile();
            protected:
                virtual INList<NViewConfig *> * parseXmlDocument(pugi::xml_document * document);
                virtual NViewConfig * parseConfigEntry(pugi::xml_node & node);
            };
        }
    }
}


#endif //NWEBMEDIA_NVIEWCONFIGFILE_H
