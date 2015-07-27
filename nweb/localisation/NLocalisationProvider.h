//
// Created by strohhalm on 13.07.15.
//

#ifndef NWEBMEDIA_NLOCALISATIONCACHE_H
#define NWEBMEDIA_NLOCALISATIONCACHE_H

#include <nbase/INSingleton.h>
#include <nbase/collection/NMap.h>

using namespace nox::collection;

namespace nox
{
    namespace web
    {
        namespace localisation
        {
            class NLocalisationProvider : public INSingleton<NLocalisationProvider>
            {
                friend class INSingleton<NLocalisationProvider>;
            protected:
                nbool                                        m_Loaded;
                boost::mutex                               * m_Mutex;
                INMap<NString, INMap<NString , NString> *> * m_Cache;
            protected:
                NLocalisationProvider();
                virtual ~NLocalisationProvider();
                virtual void load();
                virtual nbool isLoaded();
            public:
                virtual const NString localize(const NString & name, const NString & locale);
                virtual nint compareTo(const INObject * other) const;
            };
        }
    }
}

#endif //NWEBMEDIA_NLOCALISATIONCACHE_H
