//
// Created by strohhalm on 21.06.15.
//

#include "INServiceFactory.h"

namespace nox
{
    namespace service
    {
        INServiceFactory::INServiceFactory(const NString & componentName, const NString & factoryName) : IINServiceFactory()
        {
            m_ComponentName = new NString(componentName);
            m_FactoryName = new NString(factoryName);
        }

        INServiceFactory::~INServiceFactory()
        {
            if (m_ComponentName != NULL)
                delete m_ComponentName;
            if (m_FactoryName != NULL)
                delete m_FactoryName;
        }

        const NString & INServiceFactory::getComponentName() const
        {
            return *m_ComponentName;
        }

        const NString& INServiceFactory::getFactoryName() const
        {
            return *m_FactoryName;
        }

        nint INServiceFactory::compareTo(const INObject * other) const
        {
            if (this == other)
                return 0;
            try
            {
                const INServiceFactory * obj = dynamic_cast<const INServiceFactory *>(other);

                if (obj != NULL)
                {
                    int result = 0;
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