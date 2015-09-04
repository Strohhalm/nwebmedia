//
// Created by strohhalm on 04.09.15.
//

#ifndef NWEBMEDIA_NWIDGETFACTORYCONFIG_H
#define NWEBMEDIA_NWIDGETFACTORYCONFIG_H

#include <nbase/INObject.h>

namespace nox
{
    namespace web
    {
        namespace configuration
        {
            class NWidgetFactoryConfig : public INObject
            {
            protected:
                NString * m_Name;
                NString * m_Factory;
                NString * m_Component;
                NString * m_Library;
            public:
                NWidgetFactoryConfig();
                NWidgetFactoryConfig(const NString & name, const NString & factory, const NString & component, const NString & library);
                NWidgetFactoryConfig(const NWidgetFactoryConfig & other);
                virtual ~NWidgetFactoryConfig();
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

#endif //NWEBMEDIA_NWIDGETFACTORYCONFIG_H
