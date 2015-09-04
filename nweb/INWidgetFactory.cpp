//
// Created by strohhalm on 04.09.15.
//

#include <nweb/INWidgetFactory.h>

namespace nox
{
    namespace web
    {
        INWidgetFactory::INWidgetFactory(const NString & componentName, const NString & factoryName) : INObject()
        {
            m_ComponentName = new NString(componentName);
            m_FactoryName = new NString(factoryName);
        }

        INWidgetFactory::~INWidgetFactory()
        {
            if (m_ComponentName != NULL)
                delete m_ComponentName;
            if (m_FactoryName != NULL)
                delete m_FactoryName;
        }

        const NString& INWidgetFactory::getComponentName() const
        {
            return *m_ComponentName;
        }

        const NString& INWidgetFactory::getFactoryName() const
        {
            return *m_FactoryName;
        }

        nint INWidgetFactory::compareTo(const INObject * other) const
        {
            if (this == other)
                return 0;
            try
            {
                const INWidgetFactory * obj = dynamic_cast<const INWidgetFactory *>(other);

                if (obj != NULL)
                {
                    nint result = 0;
                    if ((result = getComponentName().compare(obj->getComponentName())) == 0)
                    {
                        result = getFactoryName().compare(obj->getFactoryName());
                    }
                    return result;
                }
                else
                {
                    return 1;
                }
            }
            catch (bad_cast &)
            {
                return 1;
            }
        }
    }
}