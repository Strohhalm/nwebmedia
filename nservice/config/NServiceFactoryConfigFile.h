//
// Created by strohhalm on 21.06.15.
//

#ifndef NSERVICEFACTORYCONFIGFILE_H
#define NSERVICEFACTORYCONFIGFILE_H

#include <nbase/resource/INXmlInputFile.h>
#include <nbase/collection/NList.h>
#include "NServiceFactoryConfig.h"

using namespace nox::collection;
using namespace nox::resource;

namespace nox
{
    namespace service
    {
        namespace configuration
        {
            class NServiceFactoryConfigFile : public INXmlInputFile<INList<NServiceFactoryConfig *>>
            {
            public:
                NServiceFactoryConfigFile(const NString & fileName);
                virtual ~NServiceFactoryConfigFile();
            protected:
                virtual INList<NServiceFactoryConfig *> * parseXmlDocument(pugi::xml_document * document);
                virtual NServiceFactoryConfig * parseConfigEntry(pugi::xml_node & node);
            };
        }
    }
}


#endif //NSERVICEFACTORYCONFIGFILE_H
