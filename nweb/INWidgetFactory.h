//
// Created by strohhalm on 04.09.15.
//

#ifndef NWEBMEDIA_INWIDGETFACTORY_H
#define NWEBMEDIA_INWIDGETFACTORY_H

#include <nbase/INObject.h>
#include <nweb/INWidget.h>

namespace nox
{
    namespace web
    {
        class INWidgetFactory : public INObject
        {
        protected:
            NString * m_ComponentName;
            NString * m_FactoryName;
        public:
            INWidgetFactory(const NString & componentName, const NString & factoryName);
            virtual ~INWidgetFactory();
            virtual const NString & getComponentName() const;
            virtual const NString & getFactoryName() const;
            virtual INWidget * createWidget(const NString & viewName) = 0;
            virtual nint compareTo(const INObject * other) const;
        };
    }
}

#endif //NWEBMEDIA_INWIDGETFACTORY_H
