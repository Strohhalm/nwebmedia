//
// Created by strohhalm on 28.06.15.
//

#ifndef NWEBMEDIA_NSERVICECLIENTFACTORYCONFIG_H
#define NWEBMEDIA_NSERVICECLIENTFACTORYCONFIG_H

#include <nbase/INObject.h>

namespace nox
{
    namespace service
    {
        namespace client
        {
            namespace configuration
            {
                class NServiceClientFactoryConfig : public INObject
                {
                protected:
                    NString * m_Name;
                    NString * m_Factory;
                    NString * m_Component;
                    NString * m_Library;
                public:
                    NServiceClientFactoryConfig();
                    NServiceClientFactoryConfig(const NString & name, const NString & factory, const NString & component, const NString & library);
                    NServiceClientFactoryConfig(const NServiceClientFactoryConfig & other);
                    virtual ~NServiceClientFactoryConfig();
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
}


#endif //NWEBMEDIA_NSERVICECLIENTFACTORYCONFIG_H
