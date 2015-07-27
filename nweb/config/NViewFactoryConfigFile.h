//
// Created by strohhalm on 29.06.15.
//

#ifndef NWEBMEDIA_NVIEWFACTORYCONFIGFILE_H
#define NWEBMEDIA_NVIEWFACTORYCONFIGFILE_H

#include <nbase/collection/NList.h>
#include <nbase/resource/INXmlInputFile.h>
#include <nweb/config/NViewFactoryConfig.h>

using namespace nox::collection;
using namespace nox::resource;

namespace nox
{
    namespace web
    {
        namespace configuration
        {
            class NViewFactoryConfigFile : public INXmlInputFile<INList<NViewFactoryConfig *>>
            {
            public:
                NViewFactoryConfigFile(const NString & fileName);
                virtual ~NViewFactoryConfigFile();
            protected:
                virtual INList<NViewFactoryConfig *> * parseXmlDocument(pugi::xml_document * document);
                virtual NViewFactoryConfig * parseConfigEntry(pugi::xml_node & node);
            };
        }
    }
}

#endif //NWEBMEDIA_NVIEWFACTORYCONFIGFILE_H
