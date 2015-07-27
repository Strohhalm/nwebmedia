//
// Created by strohhalm on 14.07.15.
//

#ifndef NWEBMEDIA_NNAVIGATIONCONFIG_H
#define NWEBMEDIA_NNAVIGATIONCONFIG_H

#include <nbase/INObject.h>
#include <nbase/NBaseType.h>
#include <nbase/collection/INList.h>
#include <nweb/config/NNavigationRuleConfig.h>

using namespace nox::collection;

namespace nox
{
    namespace web
    {
        namespace configuration
        {
            class NNavigationConfig : public INObject
            {
            protected:
                NString * m_View;
                NBool   * m_Initial;
                INList<NNavigationRuleConfig *> * m_NavigationRules;
            public:
                NNavigationConfig();
                NNavigationConfig(const NString & view, const NBool & initial, const INList<NNavigationRuleConfig *> * rules);
                NNavigationConfig(const NNavigationConfig & other);
                virtual ~NNavigationConfig();
                virtual void setView(const NString & view);
                virtual const NString & getView() const;
                virtual void setInitial(const NBool & initial);
                virtual const NBool & isInitial() const;
                virtual void setNavigationRules(INList<NNavigationRuleConfig *> * rules);
                virtual INList<NNavigationRuleConfig *> * getNavigationRules() const;
                virtual nint compareTo(const INObject * other) const;
            };
        }
    }
}

#endif //NWEBMEDIA_NNAVIGATIONCONFIG_H
