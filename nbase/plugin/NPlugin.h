//
// Created by strohhalm on 21.06.15.
//

#ifndef NPLUGIN_H
#define NPLUGIN_H

#include <nbase/resource/INResource.h>
#include <nbase/collection/INMap.h>

using namespace nox::resource;
using namespace nox::collection;

namespace nox
{
    namespace plugin
    {
        class NPlugin : public INResource
        {
        protected:
            NString                * m_LibraryName;
            INMap<NString, void *> * m_LibraryFunctionMap;
            void                   * m_LibraryPointer;
        public:
            NPlugin(const NString & libraryName);
            virtual ~NPlugin();
            virtual const NString & getLibraryName();
            virtual void * getFunction(const NString & functionName);
            template<class RESULT, class... ARGS>
            RESULT executeFunction(const NString & functionName, ARGS... parameters) {
                return ((RESULT(*)(ARGS...))getFunction(functionName))(parameters...);
            }
            virtual nint compareTo(const INObject * other) const;
        };
    }
}

#endif //NPLUGIN_H
