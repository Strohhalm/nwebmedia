//
// Created by strohhalm on 21.06.15.
//

#include <nbase/plugin/NPlugin.h>

#ifndef WINDOWS
    #include <dlfcn.h>

    #define SHARED_LIB_EXTENSION ".so"
#else
    #include <Winbase.h>

    #define SHARED_LIB_EXTENSION ".dll"
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
#ifndef WINDOWS
            m_LibraryPointer = dlopen(m_LibraryName->c_str(), RTLD_LAZY);
            if (m_LibraryPointer == NULL)
            {
                throw NRuntimeException(dlerror());
            }
#else
            m_LibraryPointer = LoadLibrary(m_LibraryName->c_str());
            if (m_LibraryPointer == NULL)
            {
                DWORD errorCode = GetLastError();
                nchar errorMessage[1024] = "";
                
                DWORD retSize = FormatMessage(FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_ARGUMENT_ARRAY, NULL, errorCode, 0, errorMessage, 1024, NULL);
                if (retSize <= 0)
                {
                    throw NRuntimeException("Unknown Error");   
                }
                throw NRuntimeException(errorMessage);
            }
#endif
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
                void * function = NULL;
#ifndef WINDOWS
                function = dlsym(m_LibraryPointer, functionName.c_str());
                if (function == NULL)
                {
                    throw NRuntimeException(dlerror());
                }
#else
                function = GetProcAddress(m_LibraryPointer, functionName.c_str());
                if (function == NULL)
                {
                    DWORD errorCode = GetLastError();
                    nchar errorMessage[1024] = "";
                
                    DWORD retSize = FormatMessage(FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_ARGUMENT_ARRAY, NULL, errorCode, 0, errorMessage, 1024, NULL);
                    if (retSize <= 0)
                    {
                        throw NRuntimeException("Unknown Error");   
                    }
                    throw NRuntimeException(errorMessage);
                }
#endif
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
