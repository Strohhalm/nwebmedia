//
// Created by strohhalm on 15.07.15.
//

#include "NNavigationProvider.h"

namespace nox
{
    namespace web
    {
        NNavigationProvider::NNavigationProvider()
        {
            m_NavigationCache = new NNavigationConfigCache();
        }

        NNavigationProvider::~NNavigationProvider()
        {
            if (m_NavigationCache != NULL)
                delete m_NavigationCache;
        }

        const NString & NNavigationProvider::resolve(const NString & view, const NString & outcome)
        {
            NNavigationConfig * config = m_NavigationCache->get(view);
            if (config != NULL)
            {
                if (config->getNavigationRules() != NULL)
                {
                    NNavigationRuleConfig * ruleConfig = NULL;
                    for (nlong i = 0; i < config->getNavigationRules()->getSize(); i++)
                    {
                        ruleConfig = config->getNavigationRules()->get(i);
                        if (ruleConfig != NULL)
                        {
                            if (ruleConfig->getOutcome().compare(outcome) == 0)
                            {
                                return ruleConfig->getView();
                            }
                        }
                    }
                }
            }
            return outcome;
        }

        const NString & NNavigationProvider::resolveInitialView()
        {
            //TODO
            INList<NNavigationConfig *> * configList = m_NavigationCache->getAll();
            if (configList != NULL)
            {
                for (nlong i = 0; i < configList->getSize(); i++)
                {
                    if (configList->get(i)->isInitial())
                        return configList->get(i)->getView();
                }
            }
            return 0;
        }

        nint NNavigationProvider::compareTo(const INObject * other) const
        {
            if (this == other)
                return 0;
            try
            {
                const NNavigationProvider * obj = dynamic_cast<const NNavigationProvider *>(other);

                if (obj != NULL)
                {
                    return 0;
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