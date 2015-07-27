//
// Created by strohhalm on 21.06.15.
//

#ifndef NSERVICECONFIGFILE_H
#define NSERVICECONFIGFILE_H

#include <nbase/collection/NList.h>
#include <nbase/resource/INXmlInputFile.h>
#include <nservice/config/NServiceConfig.h>

using namespace nox::collection;
using namespace nox::resource;

namespace nox
{
    namespace service
    {
        namespace configuration
        {
            class NServiceConfigFile : public INXmlInputFile<INList<NServiceConfig *>>
            {
            public:
                NServiceConfigFile(const NString & fileName);
                virtual ~NServiceConfigFile();
            protected:
                virtual INList<NServiceConfig *> * parseXmlDocument(pugi::xml_document * document);
                virtual NServiceConfig * parseConfigEntry(pugi::xml_node & node);
            };
        }
    }
}

#endif //NSERVICECONFIGFILE_H
