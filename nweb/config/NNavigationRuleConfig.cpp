//
// Created by strohhalm on 14.07.15.
//

#include "NNavigationRuleConfig.h"

namespace nox
{
    namespace web
    {
        namespace configuration
        {
            NNavigationRuleConfig::NNavigationRuleConfig() : INObject()
            {
                m_Outcome = new NString();
                m_View = new NString();
            }

            NNavigationRuleConfig::NNavigationRuleConfig(const NString & onOutcome, const NString & toView) : INObject()
            {
                m_Outcome = new NString(onOutcome);
                m_View = new NString(toView);
            }

            NNavigationRuleConfig::NNavigationRuleConfig(const NNavigationRuleConfig & other) : INObject()
            {
                m_Outcome = new NString(*other.m_Outcome);
                m_View = new NString(*other.m_View);
            }

            NNavigationRuleConfig::~NNavigationRuleConfig()
            {
                if (m_Outcome != NULL)
                    delete m_Outcome;
                if (m_View != NULL)
                    delete m_View;
            }

            void NNavigationRuleConfig::setOutcome(const NString & outcome)
            {
                m_Outcome->assign(outcome);
            }

            const NString & NNavigationRuleConfig::getOutcome() const
            {
                return *m_Outcome;
            }

            void NNavigationRuleConfig::setView(const NString & view)
            {
                m_View->assign(view);
            }

            const NString & NNavigationRuleConfig::getView() const
            {
                return *m_View;
            }

            nint NNavigationRuleConfig::compareTo(const INObject * other) const
            {
                if (this == other)
                    return 0;
                try
                {
                    const NNavigationRuleConfig * obj = dynamic_cast<const NNavigationRuleConfig *>(other);

                    if (obj != NULL)
                    {
                        nint result = 0;
                        if ((result = getOutcome().compare(obj->getOutcome())) == 0)
                        {
                            result = getView().compare(obj->getView());
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