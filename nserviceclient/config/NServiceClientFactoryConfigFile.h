//
// Created by strohhalm on 28.06.15.
//

#ifndef NWEBMEDIA_NSERVICECLIENTFACTORYCONFIGFILE_H
#define NWEBMEDIA_NSERVICECLIENTFACTORYCONFIGFILE_H

#include <nbase/collection/NList.h>
#include <nbase/resource/INXmlInputFile.h>
#include "NServiceClientFactoryConfig.h"

using namespace nox::collection;
using namespace nox::resource;

namespace nox
{
    namespace service
    {
        namespace client
        {
            namespace configuration
            {
                class NServiceClientFactoryConfigFile : public INXmlInputFile<INList<NServiceClientFactoryConfig *>>
                {
                public:
                    NServiceClientFactoryConfigFile(const NString & fileName);
                    virtual ~NServiceClientFactoryConfigFile();
                protected:
                    virtual INList<NServiceClientFactoryConfig *> * parseXmlDocument(pugi::xml_document * document);
                    virtual NServiceClientFactoryConfig * parseConfigEntry(pugi::xml_node & node);
                };
            }
        }
    }
}


#endif //NWEBMEDIA_NSERVICECLIENTFACTORYCONFIGFILE_H
