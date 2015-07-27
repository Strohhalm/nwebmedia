//
// Created by strohhalm on 29.06.15.
//

#include "INViewFactory.h"

namespace nox
{
    namespace web
    {
        INViewFactory::INViewFactory(const NString & componentName, const NString & factoryName) : INObject()
        {
            m_ComponentName = new NString(componentName);
            m_FactoryName = new NString(factoryName);
        }

        INViewFactory::~INViewFactory()
        {
            if (m_ComponentName != NULL)
                delete m_ComponentName;
            if (m_FactoryName != NULL)
                delete m_FactoryName;
        }

        const NString& INViewFactory::getComponentName() const
        {
            return *m_ComponentName;
        }

        const NString& INViewFactory::getFactoryName() const
        {
            return *m_FactoryName;
        }

        nint INViewFactory::compareTo(const INObject * other) const
        {
            if (this == other)
                return 0;
            try
            {
                const INViewFactory * obj = dynamic_cast<const INViewFactory *>(other);

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