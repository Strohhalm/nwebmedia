//
// Created by strohhalm on 04.09.15.
//

#ifndef NWEBMEDIA_NWIDGETCONFIG_H
#define NWEBMEDIA_NWIDGETCONFIG_H

#include <nbase/INObject.h>
#include <nbase/NBaseType.h>

namespace nox
{
    namespace web
    {
        namespace configuration
        {
            class NWidgetConfig : public INObject
            {
            protected:
                NString * m_Name;
                NString * m_Widget;
                NString * m_Component;
                NString * m_Factory;
            public:
                NWidgetConfig();
                NWidgetConfig(const NString & name, const NString & widget, const NString & component, const NString & factory);
                NWidgetConfig(const NWidgetConfig & other);
                virtual ~NWidgetConfig();
                virtual void setName(const NString & name);
                virtual const NString & getName() const;
                virtual void setWidget(const NString & widget);
                virtual const NString & getWidget() const;
                virtual void setComponent(const NString & component);
                virtual const NString & getComponent() const;
                virtual void setFactory(const NString & factory);
                virtual const NString & getFactory() const;
                virtual nint compareTo(const INObject * other) const;
            };
        }
    }
}


#endif //NWEBMEDIA_NWIDGETCONFIG_H
