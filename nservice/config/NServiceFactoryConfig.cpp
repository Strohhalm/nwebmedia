//
// Created by strohhalm on 21.06.15.
//

#include "NServiceFactoryConfig.h"

namespace nox
{
    namespace service
    {
        namespace configuration
        {
            NServiceFactoryConfig::NServiceFactoryConfig() : INObject()
            {
                m_Factory = new NString();
                m_Component = new NString();
                m_Library = new NString();
            }

            NServiceFactoryConfig::NServiceFactoryConfig(const NString & name, const NString & componentName, const NString & libraryName) : INObject()
            {
                m_Factory = new NString();
                m_Component = new NString(componentName);
                m_Library = new NString(libraryName);
            }

            NServiceFactoryConfig::NServiceFactoryConfig(const NServiceFactoryConfig & other) : INObject()
            {
                m_Factory = new NString(*other.m_Factory);
                m_Component = new NString(*other.m_Component);
                m_Library = new NString(*other.m_Library);
            }

            NServiceFactoryConfig::~NServiceFactoryConfig()
            {
                if (m_Factory != NULL)
                    delete m_Factory;
                if (m_Component != NULL)
                    delete m_Component;
                if (m_Library != NULL)
                    delete m_Library;
            }

            void NServiceFactoryConfig::setFactory(const NString & factory)
            {
                m_Factory->assign(factory);
            }

            const NString & NServiceFactoryConfig::getFactory() const
            {
                return *m_Factory;
            }

            void NServiceFactoryConfig::setComponent(const NString & component)
            {
                m_Component->assign(component);
            }

            const NString & NServiceFactoryConfig::getComponent() const
            {
                return *m_Component;
            }

            void NServiceFactoryConfig::setLibrary(const NString & library)
            {
                m_Library->assign(library);
            }

            const NString & NServiceFactoryConfig::getLibrary() const
            {
                return *m_Library;
            }

            nint NServiceFactoryConfig::compareTo(const INObject * other) const
            {
                if (this == other)
                    return 0;
                try
                {
                    const NServiceFactoryConfig * obj = dynamic_cast<const NServiceFactoryConfig*>(other);

                    if (obj != NULL)
                    {
                        int result = 0;
                        if ((result = getFactory().compare(obj->getFactory())) == 0)
                        {
                            if ((result = getComponent().compare(obj->getComponent())) == 0)
                            {
                                result = getLibrary().compare(obj->getLibrary());
                            }
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
}