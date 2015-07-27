//
// Created by strohhalm on 29.06.15.
//

#include "NViewFactoryConfig.h"

namespace nox
{
    namespace web
    {
        namespace configuration
        {
            NViewFactoryConfig::NViewFactoryConfig()
            {
                m_Factory = new NString();
                m_Component = new NString();
                m_Library = new NString();
            }

            NViewFactoryConfig::NViewFactoryConfig(const NString & factory, const NString & component,
                                                   const NString & library)
            {
                m_Factory = new NString(factory);
                m_Component = new NString(component);
                m_Library = new NString(library);
            }

            NViewFactoryConfig::NViewFactoryConfig(const NViewFactoryConfig & other)
            {
                m_Factory = new NString(*other.m_Factory);
                m_Component = new NString(*other.m_Component);
                m_Library = new NString(*other.m_Library);
            }

            NViewFactoryConfig::~NViewFactoryConfig()
            {
                if (m_Factory != NULL)
                    delete m_Factory;
                if (m_Component != NULL)
                    delete m_Component;
                if (m_Library != NULL)
                    delete m_Library;
            }

            void NViewFactoryConfig::setFactory(const NString & name)
            {
                m_Factory->assign(name);
            }

            const NString & NViewFactoryConfig::getFactory() const
            {
                return *m_Factory;
            }

            void NViewFactoryConfig::setComponent(const NString & component)
            {
                m_Component->assign(component);
            }

            const NString & NViewFactoryConfig::getComponent() const
            {
                return *m_Component;
            }

            void NViewFactoryConfig::setLibrary(const NString & library)
            {
                m_Library->assign(library);
            }

            const NString & NViewFactoryConfig::getLibrary() const
            {
                return *m_Library;
            }

            nint NViewFactoryConfig::compareTo(const INObject * other) const
            {
                if (this == other)
                    return 0;
                try
                {
                    const NViewFactoryConfig * obj = dynamic_cast<const NViewFactoryConfig*>(other);

                    if (obj != NULL)
                    {
                        nint result = 0;
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