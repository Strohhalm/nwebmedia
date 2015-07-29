//
// Created by strohhalm on 24.07.15.
//

#ifndef NWEBMEDIA_NKEYPROVIDERKEYREFERENCE_H
#define NWEBMEDIA_NKEYPROVIDERKEYREFERENCE_H

#include <nbase/NTypes.h>

namespace nox
{
    namespace service
    {
        namespace exchange
        {
            namespace infra
            {
                struct _NKeyProviderKeyReference
                {
                    nchar Component[51];
                    nchar KeyClass[51];
                };

                class NKeyProviderKeyReference
                {
                protected:
                    NString * m_Component;
                    NString * m_KeyClass;
                public:
                    NKeyProviderKeyReference();
                    NKeyProviderKeyReference(const NString & component, const NString & keyClass);
                    NKeyProviderKeyReference(const NKeyProviderKeyReference & other);
                    NKeyProviderKeyReference(const _NKeyProviderKeyReference & from);
                    virtual ~NKeyProviderKeyReference();
                    virtual void setComponent(const NString & component);
                    virtual const NString & getComponent();
                    virtual void setKeyClass(const NString & keyClass);
                    virtual const NString & getKeyClass();
                    virtual void toStruct(_NKeyProviderKeyReference & input);
                };
            }
        }
    }
}

#endif //NWEBMEDIA_NKEYPROVIDERKEYREFERENCE_H
