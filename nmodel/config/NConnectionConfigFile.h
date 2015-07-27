//
// Created by strohhalm on 06.06.15.
//

#ifndef NCONNECTIONCONFIGFILE_H
#define NCONNECTIONCONFIGFILE_H

#include <nbase/resource/INXmlInputFile.h>
#include <nmodel/config/NConnectionConfig.h>

using namespace nox::resource;

namespace nox
{
    namespace model
    {
        namespace configuration
        {
            class NConnectionConfigFile : public INXmlInputFile<INList<NConnectionConfig *>>
            {
            public:
                NConnectionConfigFile(const NString & fileName);
                virtual ~NConnectionConfigFile();
            protected:
                virtual INList<NConnectionConfig *> * parseXmlDocument(pugi::xml_document * document);
                virtual NConnectionConfig * parseConfigEntry(pugi::xml_node & node);
            };
        }
    }
}

#endif //NCONNECTIONCONFIGFILE_H
