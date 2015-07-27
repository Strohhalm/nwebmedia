//
// Created by strohhalm on 28.06.15.
//

#ifndef NWEBMEDIA_NSERVICECLIENTCONFIGFILE_H
#define NWEBMEDIA_NSERVICECLIENTCONFIGFILE_H

#include <nbase/resource/INXmlInputFile.h>
#include "NServiceClientConfig.h"

using namespace nox::resource;

namespace nox
{
    namespace service
    {
        namespace client
        {
            namespace configuration
            {
                class NServiceClientConfigFile : public INXmlInputFile<INList<NServiceClientConfig *>>
                {
                public:
                    NServiceClientConfigFile(const NString & fileName);
                    virtual ~NServiceClientConfigFile();
                protected:
                    virtual INList<NServiceClientConfig *> * parseXmlDocument(pugi::xml_document * document);
                    virtual NServiceClientConfig * parseConfigEntry(pugi::xml_node & node);
                };
            }
        }
    }
}


#endif //NWEBMEDIA_NSERVICECLIENTCONFIGFILE_H
