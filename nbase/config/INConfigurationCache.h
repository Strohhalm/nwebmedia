//
// Created by strohhalm on 22.06.15.
//

#ifndef INCONFIGURATIONCACHE_H
#define INCONFIGURATIONCACHE_H

#include <nbase/INObject.h>
#include <nbase/NAssert.h>
#include <nbase/collection/INList.h>
#include <nbase/collection/NMap.h>
#include <nbase/resource/NResourcePool.h>

using namespace nox::collection;
using namespace nox::resource;

namespace nox
{
    namespace configuration
    {
        template<class KEY, class CONFIGURATION>
        class INConfigurationCache : public INObject
        {
        protected:
            NStaticAssertBaseOf(INObject, CONFIGURATION);
            NStaticAssert(!is_pointer<CONFIGURATION>::value);
            NString * m_ConfigurationName;
            INList<CONFIGURATION *> * m_ConfigurationList;
            INMap<KEY, CONFIGURATION *> * m_ConfigurationCache;
        public:
            INConfigurationCache(const NString & configurationName) : INObject()
            {
                m_ConfigurationName = new NString(configurationName);
                m_ConfigurationCache = new NMap<KEY, CONFIGURATION *>();
                m_ConfigurationList = NULL;
            }
            virtual ~INConfigurationCache()
            {
                if (m_ConfigurationName != NULL)
                    delete m_ConfigurationName;
                if (m_ConfigurationList != NULL)
                    delete m_ConfigurationList;
                if (m_ConfigurationCache != NULL)
                {
                    INList<KEY> * keyList = m_ConfigurationCache->getKeyList();
                    for (int i = 0; i < keyList->getSize(); i++)
                    {
                        if (m_ConfigurationCache->get(keyList->get(i)) != NULL)
                            delete m_ConfigurationCache->get(keyList->get(i));
                    }
                    delete m_ConfigurationCache;
                }
            }
            virtual void load() = 0;
            virtual INList<CONFIGURATION *> * getAll()
            {
                if (m_ConfigurationCache->getSize() == 0)
                    this->load();
                if (m_ConfigurationCache != NULL)
                {
                    if (m_ConfigurationList != NULL)
                        delete m_ConfigurationList;
                    m_ConfigurationList = new NList<CONFIGURATION *>();

                    INList<KEY> * keyList = m_ConfigurationCache->getKeyList();
                    for (int i = 0; i < keyList->getSize(); i++)
                    {
                        m_ConfigurationList->add(m_ConfigurationCache->get(keyList->get(i)));
                    }
                }
                return m_ConfigurationList;
            }
            virtual CONFIGURATION * get(KEY key)
            {
                if (m_ConfigurationCache->getSize() == 0)
                    this->load();
                if (m_ConfigurationCache->contains(key))
                    return m_ConfigurationCache->get(key);
                return NULL;
            }
            virtual nint compareTo(const INObject * other) const
            {
                if (this == other)
                    return 0;
                try
                {
                    const INConfigurationCache<KEY, CONFIGURATION> * obj = dynamic_cast<const INConfigurationCache<KEY, CONFIGURATION> *>(other);

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
        };
    }
}

#endif //INCONFIGURATIONCACHE_H
