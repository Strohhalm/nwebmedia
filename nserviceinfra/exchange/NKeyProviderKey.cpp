//
// Created by strohhalm on 24.07.15.
//

#include "NKeyProviderKey.h"

namespace nox
{
    namespace service
    {
        namespace exchange
        {
            namespace infra
            {
                NKeyProviderKey::NKeyProviderKey()
                {
                    m_Key = new NLong();
                }

                NKeyProviderKey::NKeyProviderKey(const NLong & key)
                {
                    m_Key = new NLong(key);
                }

                NKeyProviderKey::NKeyProviderKey(const NKeyProviderKey & other)
                {
                    m_Key = new NLong(*other.m_Key);
                }

                NKeyProviderKey::NKeyProviderKey(const _NKeyProviderKey & from)
                {
                    m_Key = new NLong(from.Key);
                }

                NKeyProviderKey::~NKeyProviderKey()
                {
                    if (m_Key != NULL)
                        delete m_Key;
                }

                void NKeyProviderKey::setKey(const NLong & key)
                {
                    m_Key->setValue(key);
                }

                const NLong & NKeyProviderKey::getKey()
                {
                    return *m_Key;
                }

                void NKeyProviderKey::toStruct(_NKeyProviderKey & input)
                {
                    memset(&input, 0, sizeof(_NKeyProviderKey));

                    input.Key = getKey().getValue();
                }
            }
        }
    }
}