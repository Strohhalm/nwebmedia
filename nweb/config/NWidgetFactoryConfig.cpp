//
// Created by strohhalm on 04.09.15.
//

#include <nweb/config/NWidgetFactoryConfig.h>

namespace nox
{
    namespace web
    {
        namespace configuration
        {
            NWidgetFactoryConfig::NWidgetFactoryConfig()
            {
                m_Name = new NString();
                m_Factory = new NString();
                m_Component = new NString();
                m_Library = new NString();
            }

            NWidgetFactoryConfig::NWidgetFactoryConfig(const NString & name, const NString & factory, const NString & component, const NString & library)
            {
                m_Name = new NString(name);
                m_Factory = new NString(factory);
                m_Component = new NString(component);
                m_Library = new NString(library);
            }

            NWidgetFactoryConfig::NWidgetFactoryConfig(const NWidgetFactoryConfig & other)
            {
                m_Name = new NString(*other.m_Name);
                m_Factory = new NString(*other.m_Factory);
                m_Component = new NString(*other.m_Component);
                m_Library = new NString(*other.m_Library);
            }

            NWidgetFactoryConfig::~NWidgetFactoryConfig()
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

            void NWidgetFactoryConfig::setName(const NString & name)
            {
                m_Name->assign(name);
            }

            const NString & NWidgetFactoryConfig::getName() const
            {
                return *m_Name;
            }

            void NWidgetFactoryConfig::setFactory(const NString & factory)
            {
                m_Factory->assign(factory);
            }

            const NString & NWidgetFactoryConfig::getFactory() const
            {
                return *m_Factory;
            }

            void NWidgetFactoryConfig::setComponent(const NString & component)
            {
                m_Component->assign(component);
            }

            const NString & NWidgetFactoryConfig::getComponent() const
            {
                return *m_Component;
            }

            void NWidgetFactoryConfig::setLibrary(const NString & library)
            {
                m_Library->assign(library);
            }

            const NString & NWidgetFactoryConfig::getLibrary() const
            {
                return *m_Library;
            }

            nint NWidgetFactoryConfig::compareTo(const INObject * other) const
            {
                if (this == other)
                    return 0;
                try
                {
                    const NWidgetFactoryConfig * obj = dynamic_cast<const NWidgetFactoryConfig*>(other);

                    if (obj != NULL)
                    {
                        nint result = 0;
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