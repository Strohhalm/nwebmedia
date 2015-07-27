//
// Created by strohhalm on 14.07.15.
//

#ifndef NWEBMEDIA_NNAVIGATIONRULECONFIG_H
#define NWEBMEDIA_NNAVIGATIONRULECONFIG_H

#include <nbase/INObject.h>

namespace nox
{
    namespace web
    {
        namespace configuration
        {
            class NNavigationRuleConfig : public INObject
            {
            protected:
                NString * m_Outcome;
                NString * m_View;
            public:
                NNavigationRuleConfig();
                NNavigationRuleConfig(const NString & outcome, const NString & view);
                NNavigationRuleConfig(const NNavigationRuleConfig & other);
                virtual ~NNavigationRuleConfig();
                virtual void setOutcome(const NString & outcome);
                virtual const NString & getOutcome() const;
                virtual void setView(const NString & view);
                virtual const NString & getView() const;
                virtual nint compareTo(const INObject * other) const;
            };
        }
    }
}

#endif //NWEBMEDIA_NNAVIGATIONRULECONFIG_H
