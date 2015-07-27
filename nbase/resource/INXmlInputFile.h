//
// Created by strohhalm on 05.06.15.
//

#ifndef INXMLINPUTFILE_H
#define INXMLINPUTFILE_H

#include <nbase/NRuntimeException.h>
#include <nbase/resource/INResource.h>

namespace nox
{
    namespace resource
    {
        template<class RESULT>
        class INXmlInputFile : public INResource
        {
        protected:
            BOOST_STATIC_ASSERT(!is_pointer<RESULT>::value);
            pugi::xml_document * m_Document;
        public:
            INXmlInputFile(const NString & fileName) : INResource(fileName)
            {
                m_Document = new pugi::xml_document();
            }
            virtual ~INXmlInputFile()
            {
                if (m_Document != NULL)
                    delete m_Document;
            }
            virtual RESULT * parse()
            {
                pugi::xml_parse_result result = m_Document->load_file(m_RelativePath->c_str());
                if (result.status != pugi::status_ok)
                {
                    throw NRuntimeException(result.description());
                }

                return parseXmlDocument(m_Document);
            }
            virtual nint compareTo(const INObject * other) const
            {
                if (this == other)
                    return 0;
                if (this > other)
                    return 1;
                return -1;
            }
        protected:
            virtual RESULT * parseXmlDocument(pugi::xml_document * document) = 0;
        };
    }
}

#define XML_SUFFIX ".xml"

#endif //INXMLINPUTFILE_H
