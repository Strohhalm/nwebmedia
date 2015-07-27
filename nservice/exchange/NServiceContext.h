//
// Created by strohhalm on 16.07.15.
//

#ifndef NWEBMEDIA_NSERVICECONTEXT_H
#define NWEBMEDIA_NSERVICECONTEXT_H

#include <nbase/NBaseType.h>

namespace nox
{
    namespace service
    {
        namespace exchange
        {
            struct _NServiceContext
            {
                nlong UserId;
                nchar Locale[6];
            };

            class NServiceContext
            {
            protected:
                NString * m_Locale;
                NInteger * m_UserId;
            public:
                NServiceContext();
                NServiceContext(const NInteger & userId, const NString & locale);
                NServiceContext(const NServiceContext & other);
                NServiceContext(const _NServiceContext & from);
                virtual ~NServiceContext();
                virtual void setLocale(const NString & locale);
                virtual const NString & getLocale();
                virtual void setUserId(const NInteger & userId);
                virtual const NInteger & getUserId();
                virtual void toStruct(_NServiceContext & input);
            };
        }
    }
}


#endif //NWEBMEDIA_NSERVICECONTEXT_H
