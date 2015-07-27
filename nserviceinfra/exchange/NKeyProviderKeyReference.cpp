//
// Created by strohhalm on 24.07.15.
//

#include "NKeyProviderKeyReference.h"

namespace nox
{
    namespace service
    {
        namespace exchange
        {
            namespace infra
            {
                NKeyProviderKeyReference::NKeyProviderKeyReference()
                {
                    m_Component = new NString();
                    m_KeyClass = new NString();
                }

                NKeyProviderKeyReference::NKeyProviderKeyReference(const NString & component, const NString & keyClass)
                {
                    m_Component = new NString(component);
                    m_KeyClass = new NString(keyClass);
                }

                NKeyProviderKeyReference::NKeyProviderKeyReference(const NKeyProviderKeyReference & other)
                {
                    m_Component = new NString(*other.m_Component);
                    m_KeyClass = new NString(*other.m_KeyClass);
                }

                NKeyProviderKeyReference::NKeyProviderKeyReference(const _NKeyProviderKeyReference & from)
                {
                    m_Component = new NString(from.Component);
                    m_KeyClass = new NString(from.KeyClass);
                }

                NKeyProviderKeyReference::~NKeyProviderKeyReference()
                {
                    if (m_Component != NULL)
                        delete m_Component;
                    if (m_KeyClass != NULL)
                        delete m_KeyClass;
                }

                void NKeyProviderKeyReference::setComponent(const NString & component)
                {
                    m_Component->assign(component);
                }

                const NString & NKeyProviderKeyReference::getComponent()
                {
                    return *m_Component;
                }

                void NKeyProviderKeyReference::setKeyClass(const NString & keyClass)
                {
                    m_KeyClass->assign(keyClass);
                }

                const NString & NKeyProviderKeyReference::getKeyClass()
                {
                    return *m_KeyClass;
                }

                void NKeyProviderKeyReference::toStruct(_NKeyProviderKeyReference & input)
                {
                    memset(&input, 0, sizeof(_NKeyProviderKeyReference));

                    getComponent().copy(input.Component, getComponent().length());
                    getKeyClass().copy(input.KeyClass, getKeyClass().length());
                }
            }
        }
    }
}