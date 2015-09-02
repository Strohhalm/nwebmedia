//
// Created by strohhalm on 29.06.15.
//

#ifndef NWEBMEDIA_NVIEWFACTORYCONFIG_H
#define NWEBMEDIA_NVIEWFACTORYCONFIG_H

#include <nbase/INObject.h>

namespace nox
{
    namespace web
    {
        namespace configuration
        {
            class NViewFactoryConfig : public INObject
            {
            protected:
                NString * m_Name;
                NString * m_Factory;
                NString * m_Component;
                NString * m_Library;
            public:
                NViewFactoryConfig();
                NViewFactoryConfig(const NString & name, const NString & factory, const NString & component, const NString & library);
                NViewFactoryConfig(const NViewFactoryConfig & other);
                virtual ~NViewFactoryConfig();
                virtual void setName(const NString & name);
                virtual const NString & getName() const;
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

#endif //NWEBMEDIA_NVIEWFACTORYCONFIG_H
