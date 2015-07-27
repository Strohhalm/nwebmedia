//
// Created by strohhalm on 29.06.15.
//

#include "NViewConfig.h"
#include <nbase/collection/NList.h>

namespace nox
{
    namespace web
    {
        namespace configuration
        {
            NViewConfig::NViewConfig()
            {
                m_View = new NString();
                m_Component = new NString();
                m_Factory = new NString();
            }

            NViewConfig::NViewConfig(const NString & view, const NString & component, const NString & factory)
            {
                m_View = new NString(view);
                m_Component = new NString(component);
                m_Factory = new NString(factory);
            }

            NViewConfig::NViewConfig(const NViewConfig & other)
            {
                m_View = new NString(*other.m_View);
                m_Component = new NString(*other.m_Component);
                m_Factory = new NString(*other.m_Factory);
            }

            NViewConfig::~NViewConfig()
            {
                if (m_View != NULL)
                    delete m_View;
                if (m_Component != NULL)
                    delete m_Component;
                if (m_Factory != NULL)
                    delete m_Factory;
            }

            void NViewConfig::setView(const NString & view)
            {
                m_View->assign(view);
            }

            const NString & NViewConfig::getView() const
            {
                return *m_View;
            }

            void NViewConfig::setComponent(const NString & component)
            {
                m_Component->assign(component);
            }

            const NString & NViewConfig::getComponent() const
            {
                return *m_Component;
            }

            void NViewConfig::setFactory(const NString & factory)
            {
                m_Factory->assign(factory);
            }

            const NString & NViewConfig::getFactory() const
            {
                return *m_Factory;
            }

            nint NViewConfig::compareTo(const INObject * other) const
            {
                if (this == other)
                    return 0;
                try
                {
                    const NViewConfig * obj = dynamic_cast<const NViewConfig *>(other);

                    if (obj != NULL)
                    {
                        nint result = 0;
                        if ((result = getView().compare(obj->getView())) == 0)
                        {
                            if ((result = getComponent().compare(obj->getComponent())) == 0)
                            {
                                result = getFactory().compare(obj->getFactory());
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
