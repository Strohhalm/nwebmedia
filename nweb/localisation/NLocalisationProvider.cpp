//
// Created by strohhalm on 13.07.15.
//

#include <nweb/localisation/NLocalisationProvider.h>
#include <nserviceclient/NServiceClientProvider.h>
#include <nserviceclientinfra/INServiceClientLocalisation.h>

using namespace nox::service::client;
using namespace nox::service::client::infra;

namespace nox
{
    namespace web
    {
        namespace localisation
        {
            NLocalisationProvider::NLocalisationProvider() : INSingleton<NLocalisationProvider>()
            {
                m_Cache  = new NMap<NString, INMap<NString, NString> *>();
                m_Mutex  = new boost::mutex();
                m_Loaded = false;
            }

            NLocalisationProvider::~NLocalisationProvider()
            {
                if (m_Cache != NULL)
                {
                    INList<NString> * keyList = m_Cache->getKeyList();
                    for (nlong i = 0; i < keyList->getSize(); i++)
                    {
                        if (m_Cache->get(keyList->get(i)) != NULL)
                            delete m_Cache->get(keyList->get(i));
                    }
                    delete m_Cache;
                }
                if (m_Mutex != NULL)
                    delete m_Mutex;
            }

            void NLocalisationProvider::load()
            {
                INServiceClientLocalisation * serviceClient = NServiceClientProvider::getInstance()->getServiceClient<INServiceClientLocalisation>("NServiceClientLocalisation");
                if (serviceClient != NULL)
                {
                    NLocalisationRequest  * request  = NULL;
                    NLocalisationResponse * response = NULL;
                    try
                    {
                        NUnsignedLong from(0);
                        NUnsignedLong count(100);

                        request = new NLocalisationRequest();

                        do
                        {
                            if (response != NULL)
                                delete response;
                            response = NULL;

                            request->getPortion().setFrom(from);
                            request->getPortion().setCount(count);

                            response = serviceClient->readLocalisation(request);
                            if (response != NULL)
                            {
                                for (nlong i = 0; i < response->getData().getEntries().getSize(); i++)
                                {
                                    NLocalisationEntry * entry = response->getData().getEntries().get(i);
                                    if (entry != NULL)
                                    {
                                        if (!m_Cache->contains(entry->getLocale()))
                                            m_Cache->add(entry->getLocale(), new NMap<NString, NString>());

                                        if (m_Cache->get(entry->getLocale())->contains(entry->getName()))
                                            m_Cache->get(entry->getLocale())->remove(entry->getName());

                                        m_Cache->get(entry->getLocale())->add(entry->getName(), entry->getText());
                                    }
                                }
                            }

                            from += 100;
                        } while (response->getData().getEntries().getSize() == 100);

                        if (response != NULL)
                            delete response;
                        m_Loaded = true;
                    }
                    catch (NException & exp)
                    {
                        if (request != NULL)
                            delete request;
                        if (response != NULL)
                            delete response;
                    }
                }
            }

            nbool NLocalisationProvider::isLoaded()
            {
                return m_Loaded;
            }

            const NString NLocalisationProvider::localize(const NString & name, const NString & locale)
            {
                m_Mutex->lock();
                {
                    if (!isLoaded())
                    {
                        load();
                    }
                }
                m_Mutex->unlock();
                if (m_Cache->contains(locale))
                {
                    if (m_Cache->get(locale)->contains(name))
                    {
                        return m_Cache->get(locale)->get(name);
                    }
                }
                else
                {
                    nulong sepIndex = locale.find("_");
                    if (sepIndex != -1)
                    {
                        NString _loc = locale.substr(0, sepIndex);
                        return localize(name, _loc);
                    }
                }
                return name;
            }

            nint NLocalisationProvider::compareTo(const INObject * other) const
            {
                if (this == other)
                    return 0;
                try
                {
                    const NLocalisationProvider * obj = dynamic_cast<const NLocalisationProvider *>(other);

                    if (obj != NULL)
                    {
                        if (this > other)
                            return 1;
                        return -1;
                    }
                    else
                    {
                        return 1;
                    }
                }
                catch (bad_cast & )
                {
                    return 1;
                }
            }
        }
    }
}