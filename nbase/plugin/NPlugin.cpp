//
// Created by strohhalm on 21.06.15.
//

#include "NPlugin.h"

#include <locale>

#ifdef WINDOWS
    #error "Implement Windows path for library loading"

    #define SHARED_LIB_EXTENSION ".dll"
#else
    #include <dlfcn.h>

    #define SHARED_LIB_EXTENSION ".so"
#endif
#include <nbase/NBaseType.h>
#include <nbase/NRuntimeException.h>
#include <nbase/collection/NMap.h>


namespace nox
{
    namespace plugin
    {
        NPlugin::NPlugin(const NString & libraryName) : INResource(libraryName)
        {
            m_LibraryName = new NString(libraryName);

            string sharedLibrary = libraryName;

            m_LibraryPointer = dlopen(sharedLibrary.c_str(), RTLD_LAZY);
            if (m_LibraryPointer == NULL)
            {
                throw NRuntimeException(dlerror());
            }
            m_LibraryFunctionMap = new NMap<NString, void *>();
        }

        NPlugin::~NPlugin()
        {
            if (m_LibraryFunctionMap != NULL)
                delete m_LibraryFunctionMap;
            if (dlclose(m_LibraryPointer) != 0)
            {
                throw NRuntimeException(dlerror());
            }
        }

        const NString& NPlugin::getLibraryName()
        {
            return *m_LibraryName;
        }

        void* NPlugin::getFunction(const NString & functionName)
        {
            if (!m_LibraryFunctionMap->contains(functionName))
            {
                string funcName = functionName;
                void * function = NULL;

                function = dlsym(m_LibraryPointer, funcName.c_str());
                if (function == NULL)
                {
                    throw NRuntimeException(dlerror());
                }
                m_LibraryFunctionMap->add(functionName, function);
            }
            return m_LibraryFunctionMap->get(functionName);
        }

        nint NPlugin::compareTo(const INObject * other) const
        {
            if (this == other)
                return 0;
            if (this > other)
                return 1;
            return -1;
        }
    }
}