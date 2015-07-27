//
// Created by strohhalm on 16.07.15.
//

#ifndef NWEBMEDIA_NSERVICERESPONSEHEAD_H
#define NWEBMEDIA_NSERVICERESPONSEHEAD_H

#include <nservice/exchange/NServiceControl.h>
#include <nservice/exchange/NServiceContext.h>
#include <nservice/exchange/NServiceError.h>

namespace nox
{
    namespace service
    {
        namespace exchange
        {
            struct _NServiceResponseHead
            {
                _NServiceControl Control;
                _NServiceContext Context;
                _NServiceError Error;
            };

            class NServiceResponseHead
            {
            protected:
                NServiceControl * m_Control;
                NServiceContext * m_Context;
                NServiceError * m_Error;
            public:
                NServiceResponseHead();
                NServiceResponseHead(const NServiceControl & control, const NServiceContext & context, const NServiceError & error);
                NServiceResponseHead(const NServiceResponseHead & other);
                NServiceResponseHead(const _NServiceResponseHead & from);
                virtual ~NServiceResponseHead();
                virtual NServiceControl & getControl();
                virtual NServiceContext & getContext();
                virtual NServiceError & getError();
                virtual void toStruct(_NServiceResponseHead & input);
            };
        }
    }
}

#endif //NWEBMEDIA_NSERVICERESPONSEHEAD_H
