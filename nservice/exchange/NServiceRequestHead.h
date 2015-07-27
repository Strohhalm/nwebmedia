//
// Created by strohhalm on 16.07.15.
//

#ifndef NWEBMEDIA_NSERVICEREQUESTHEAD_H
#define NWEBMEDIA_NSERVICEREQUESTHEAD_H

#include <nservice/exchange/NServiceControl.h>
#include <nservice/exchange/NServiceContext.h>

namespace nox
{
    namespace service
    {
        namespace exchange
        {
            struct _NServiceRequestHead
            {
                _NServiceControl Control;
                _NServiceContext Context;
            };

            class NServiceRequestHead
            {
            protected:
                NServiceControl * m_Control;
                NServiceContext * m_Context;
            public:
                NServiceRequestHead();
                NServiceRequestHead(const NServiceControl & control, const NServiceContext & context);
                NServiceRequestHead(const NServiceRequestHead & other);
                NServiceRequestHead(const _NServiceRequestHead & from);
                virtual ~NServiceRequestHead();
                virtual NServiceControl & getControl();
                virtual NServiceContext & getContext();
                virtual void toStruct(_NServiceRequestHead & input);
            };
        }
    }
}

#endif //NWEBMEDIA_NSERVICEREQUESTHEAD_H
