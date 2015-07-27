//
// Created by strohhalm on 30.06.15.
//

#ifndef NWEBMEDIA_NNAVIGATIONCONFIGFILE_H
#define NWEBMEDIA_NNAVIGATIONCONFIGFILE_H

#include <nbase/resource/INXmlInputFile.h>
#include <nweb/config/NNavigationConfig.h>

using namespace nox::resource;

namespace nox
{
    namespace web
    {
        namespace configuration
        {
            class NNavigationConfigFile : public INXmlInputFile<INList<NNavigationConfig *>>
            {
            public:
                NNavigationConfigFile(const NString & fileName);
                virtual ~NNavigationConfigFile();
            protected:
                virtual INList<NNavigationConfig*> * parseXmlDocument(pugi::xml_document * document);
                virtual NNavigationConfig * parseConfigEntry(pugi::xml_node & node);
                virtual NNavigationRuleConfig * parseSubConfigEntry(pugi::xml_node & node);
            };
        }
    }
}


#endif //NWEBMEDIA_NNAVIGATIONCONFIGFILE_H
