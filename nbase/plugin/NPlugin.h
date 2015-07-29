//
// Created by strohhalm on 21.06.15.
//

#ifndef NPLUGIN_H
#define NPLUGIN_H

#include <nbase/collection/INMap.h>
#include <nbase/resource/INResource.h>

using namespace nox::collection;
using namespace nox::resource;

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
