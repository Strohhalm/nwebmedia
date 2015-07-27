//
// Created by strohhalm on 21.06.15.
//

#ifndef NSERVICEFACTORYCONFIG_H
#define NSERVICEFACTORYCONFIG_H

#include <nbase/INObject.h>

namespace nox
{
    namespace service
    {
        namespace configuration
        {
            class NServiceFactoryConfig : public INObject
            {
            protected:
                NString * m_Factory;
                NString * m_Component;
                NString * m_Library;
            public:
                NServiceFactoryConfig();
                NServiceFactoryConfig(const NString & name, const NString & componentName, const NString & libraryName);
                NServiceFactoryConfig(const NServiceFactoryConfig & other);
                virtual ~NServiceFactoryConfig();
                virtual void setFactory(const NString & factory);
                virtual const NString & getFactory() const;
                virtual void setComponent(const NString & component);
                virtual const NString & getComponent() const;
                virtual void setLibrary(const NString & library);
                virtual const NString & getLibrary() const;
                virtual nint compareTo(const INObject * other) const;
            };
        }
    }
}


#endif //NSERVICEFACTORYCONFIG_H
