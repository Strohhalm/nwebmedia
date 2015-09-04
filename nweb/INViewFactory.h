//
// Created by strohhalm on 29.06.15.
//

#ifndef NWEBMEDIA_INVIEWFACTORY_H
#define NWEBMEDIA_INVIEWFACTORY_H

#include <nbase/INObject.h>
#include <nweb/INView.h>

namespace nox
{
    namespace web
    {
        class INViewFactory : public INObject
        {
        protected:
            NString * m_ComponentName;
            NString * m_FactoryName;
        public:
            INViewFactory(const NString & componentName, const NString & factoryName);
            virtual ~INViewFactory();
            virtual const NString & getComponentName() const;
            virtual const NString & getFactoryName() const;
            virtual INView * createView(const NString & viewName) = 0;
            virtual nint compareTo(const INObject * other) const;
        };
    }
}

#endif //NWEBMEDIA_INVIEWFACTORY_H
