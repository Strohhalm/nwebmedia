//
// Created by strohhalm on 04.09.15.
//

#include <nweb/config/NWidgetConfig.h>
#include <nbase/collection/NList.h>

namespace nox
{
    namespace web
    {
        namespace configuration
        {
            NWidgetConfig::NWidgetConfig()
            {
                m_Name = new NString();
                m_Widget = new NString();
                m_Component = new NString();
                m_Factory = new NString();
            }

            NWidgetConfig::NWidgetConfig(const NString & name, const NString & widget, const NString & component, const NString & factory)
            {
                m_Name = new NString(name);
                m_Widget = new NString(widget);
                m_Component = new NString(component);
                m_Factory = new NString(factory);
            }

            NWidgetConfig::NWidgetConfig(const NWidgetConfig & other)
            {
                m_Name = new NString(*other.m_Name);
                m_Widget = new NString(*other.m_Widget);
                m_Component = new NString(*other.m_Component);
                m_Factory = new NString(*other.m_Factory);
            }

            NWidgetConfig::~NWidgetConfig()
            {
                if (m_Name != NULL)
                    delete m_Name;
                if (m_Widget != NULL)
                    delete m_Widget;
                if (m_Component != NULL)
                    delete m_Component;
                if (m_Factory != NULL)
                    delete m_Factory;
            }

            void NWidgetConfig::setName(const NString & name)
            {
                m_Name->assign(name);
            }

            const NString & NWidgetConfig::getName() const
            {
                return *m_Name;
            }

            void NWidgetConfig::setWidget(const NString & widget)
            {
                m_Widget->assign(widget);
            }

            const NString & NWidgetConfig::getWidget() const
            {
                return *m_Widget;
            }

            void NWidgetConfig::setComponent(const NString & component)
            {
                m_Component->assign(component);
            }

            const NString & NWidgetConfig::getComponent() const
            {
                return *m_Component;
            }

            void NWidgetConfig::setFactory(const NString & factory)
            {
                m_Factory->assign(factory);
            }

            const NString & NWidgetConfig::getFactory() const
            {
                return *m_Factory;
            }

            nint NWidgetConfig::compareTo(const INObject * other) const
            {
                if (this == other)
                    return 0;
                try
                {
                    const NWidgetConfig * obj = dynamic_cast<const NWidgetConfig *>(other);

                    if (obj != NULL)
                    {
                        nint result = 0;
                        if ((result = getName().compare(obj->getName())) == 0)
                        {
                            if ((result = getWidget().compare(obj->getWidget())) == 0)
                            {
                                if ((result = getComponent().compare(obj->getComponent())) == 0)
                                {
                                    result = getFactory().compare(obj->getFactory());
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