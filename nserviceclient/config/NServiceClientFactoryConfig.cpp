//
// Created by strohhalm on 28.06.15.
//

#include "NServiceClientFactoryConfig.h"

namespace nox
{
    namespace service
    {
        namespace client
        {
            namespace configuration
            {
                NServiceClientFactoryConfig::NServiceClientFactoryConfig() : INObject()
                {
                    m_Name = new NString();
                    m_Factory = new NString();
                    m_Component = new NString();
                    m_Library = new NString();
                }

                NServiceClientFactoryConfig::NServiceClientFactoryConfig(const NString & name,
                                                                         const NString & factory,
                                                                         const NString & component,
                                                                         const NString & library) : INObject()
                {
                    m_Name = new NString(name);
                    m_Factory = new NString(factory);
                    m_Component = new NString(component);
                    m_Library = new NString(library);
                }

                NServiceClientFactoryConfig::NServiceClientFactoryConfig(const NServiceClientFactoryConfig & other) : INObject()
                {
                    m_Name = new NString(*other.m_Name);
                    m_Factory = new NString(*other.m_Factory);
                    m_Component = new NString(*other.m_Component);
                    m_Library = new NString(*other.m_Library);
                }

                NServiceClientFactoryConfig::~NServiceClientFactoryConfig()
                {
                    if (m_Name != NULL)
                        delete m_Name;
                    if (m_Factory != NULL)
                        delete m_Factory;
                    if (m_Component != NULL)
                        delete m_Component;
                    if (m_Library != NULL)
                        delete m_Library;
                }

                void NServiceClientFactoryConfig::setName(const NString & name)
                {
                    m_Name->assign(name);
                }

                const NString & NServiceClientFactoryConfig::getName() const
                {
                    return *m_Name;
                }

                void NServiceClientFactoryConfig::setFactory(const NString & factory)
                {
                    m_Factory->assign(factory);
                }

                const NString & NServiceClientFactoryConfig::getFactory() const
                {
                    return *m_Factory;
                }

                void NServiceClientFactoryConfig::setComponent(const NString & component)
                {
                    m_Component->assign(component);
                }

                const NString & NServiceClientFactoryConfig::getComponent() const
                {
                    return *m_Component;
                }

                void NServiceClientFactoryConfig::setLibrary(const NString & library)
                {
                    m_Library->assign(library);
                }

                const NString & NServiceClientFactoryConfig::getLibrary() const
                {
                    return *m_Library;
                }

                nint NServiceClientFactoryConfig::compareTo(const INObject * other) const
                {
                    if (this == other)
                        return 0;
                    try
                    {
                        const NServiceClientFactoryConfig * obj = dynamic_cast<const NServiceClientFactoryConfig*>(other);

                        if (obj != NULL)
                        {
                            int result = 0;
                            if ((result = getName().compare(obj->getName())) == 0)
                            {
                                if ((result = getFactory().compare(obj->getFactory())) == 0)
                                {
                                    if ((result = getComponent().compare(obj->getComponent())) == 0)
                                    {
                                        result = getLibrary().compare(obj->getLibrary());
                                    }
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
}