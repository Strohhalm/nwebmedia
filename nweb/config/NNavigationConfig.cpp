//
// Created by strohhalm on 14.07.15.
//

#include <nbase/collection/NList.h>
#include "NNavigationConfig.h"

namespace nox
{
    namespace web
    {
        namespace configuration
        {
            NNavigationConfig::NNavigationConfig()
            {
                m_View = new NString();
                m_Initial = new NBool();
                m_NavigationRules = NULL;
            }

            NNavigationConfig::NNavigationConfig(const NString & view, const NBool & initial, const INList<NNavigationRuleConfig *> * rules)
            {
                m_View = new NString(view);
                m_Initial = new NBool(initial);
                m_NavigationRules = NULL;
                if (rules != NULL)
                {
                    m_NavigationRules = new NList<NNavigationRuleConfig *>();
                    for (nlong i = 0; i < rules->getSize(); i++)
                    {
                        m_NavigationRules->add(new NNavigationRuleConfig(*rules->get(i)));
                    }
                }
            }

            NNavigationConfig::NNavigationConfig(const NNavigationConfig & other)
            {
                m_View = new NString(*other.m_View);
                m_Initial = new NBool(*other.m_Initial);
                m_NavigationRules = NULL;
                if (other.m_NavigationRules != NULL)
                {
                    m_NavigationRules = new NList<NNavigationRuleConfig *>();
                    for (nlong i = 0; i < other.m_NavigationRules->getSize(); i++)
                    {
                        m_NavigationRules->add(new NNavigationRuleConfig(*other.m_NavigationRules->get(i)));
                    }
                }
            }

            NNavigationConfig::~NNavigationConfig()
            {
                if (m_View != NULL)
                    delete m_View;
                if (m_Initial != NULL)
                    delete m_Initial;
                if (m_NavigationRules != NULL)
                {
                    for (nlong i = 0; i < m_NavigationRules->getSize(); i++)
                    {
                        if (m_NavigationRules->get(i) != NULL)
                            delete m_NavigationRules->get(i);
                    }
                    delete m_NavigationRules;
                }
            }

            void NNavigationConfig::setView(const NString & view)
            {
                m_View->assign(view);
            }

            const NString & NNavigationConfig::getView() const
            {
                return *m_View;
            }

            void NNavigationConfig::setInitial(const NBool & initial)
            {
                m_Initial->setValue(initial);
            }

            const NBool & NNavigationConfig::isInitial() const
            {
                return *m_Initial;
            }

            void NNavigationConfig::setNavigationRules(INList<NNavigationRuleConfig *> * rules)
            {
                if (m_NavigationRules != NULL)
                {
                    for (nlong i = 0; i < m_NavigationRules->getSize(); i++)
                    {
                        if (m_NavigationRules->get(i) != NULL)
                            delete m_NavigationRules->get(i);
                    }
                    delete m_NavigationRules;
                }
                m_NavigationRules = rules;
            }

            INList<NNavigationRuleConfig *> * NNavigationConfig::getNavigationRules() const
            {
                return m_NavigationRules;
            }

            nint NNavigationConfig::compareTo(const INObject * other) const
            {
                if (this == other)
                    return 0;
                try
                {
                    const NNavigationConfig * obj = dynamic_cast<const NNavigationConfig *>(other);

                    if (obj != NULL)
                    {
                        nint result = 0;
                        if ((result = getView().compare(obj->getView())) == 0)
                        {
                            if (isInitial().getValue() == obj->isInitial().getValue())
                            {
                                if (getNavigationRules() != NULL)
                                {
                                    result = getNavigationRules()->compareTo(obj->getNavigationRules());
                                }
                                else
                                {
                                    if (obj->getNavigationRules() == NULL)
                                    {
                                        result = 0;
                                    }
                                    else
                                    {
                                        result = -1;
                                    }
                                }
                            }
                            else
                            {
                                if (isInitial() == true)
                                {
                                    result = 1;
                                }
                                else
                                {
                                    result = -1;
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