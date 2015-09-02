//
// Created by strohhalm on 29.06.15.
//

#ifndef NWEBMEDIA_NVIEWCONFIG_H
#define NWEBMEDIA_NVIEWCONFIG_H

#include <nbase/INObject.h>
#include <nbase/NBaseType.h>

namespace nox
{
    namespace web
    {
        namespace configuration
        {
            class NViewConfig : public INObject
            {
            protected:
                NString * m_Name;
                NString * m_View;
                NString * m_Component;
                NString * m_Factory;
            public:
                NViewConfig();
                NViewConfig(const NString & name, const NString & view, const NString & component, const NString & factory);
                NViewConfig(const NViewConfig & other);
                virtual ~NViewConfig();
                virtual void setName(const NString & name);
                virtual const NString & getName() const;
                virtual void setView(const NString & view);
                virtual const NString & getView() const;
                virtual void setComponent(const NString & component);
                virtual const NString & getComponent() const;
                virtual void setFactory(const NString & factory);
                virtual const NString & getFactory() const;
                virtual nint compareTo(const INObject * other) const;
            };
        }
    }
}

#endif //NWEBMEDIA_NVIEWCONFIG_H
