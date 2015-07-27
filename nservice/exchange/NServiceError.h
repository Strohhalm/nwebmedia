//
// Created by strohhalm on 16.07.15.
//

#ifndef NWEBMEDIA_NSERVICEERROR_H
#define NWEBMEDIA_NSERVICEERROR_H

#include <nbase/NBaseType.h>

namespace nox
{
    namespace service
    {
        namespace exchange
        {
            struct _NServiceError
            {
                nint Code;
                nchar Message[256];
            };

            class NServiceError
            {
            protected:
                NInteger * m_ErrorCode;
                NString * m_Message;
            public:
                NServiceError();
                NServiceError(const NInteger & errorCode, const NString & message);
                NServiceError(const NServiceError & other);
                NServiceError(const _NServiceError & from);
                virtual ~NServiceError();
                virtual void setErrorCode(const NInteger & errorCode);
                virtual const NInteger & getErrorCode();
                virtual void setMessage(const NString & message);
                virtual const NString & getMessage();
                virtual void toStruct(_NServiceError & input);
            };
        }
    }
}


#endif //NWEBMEDIA_NSERVICEERROR_H
