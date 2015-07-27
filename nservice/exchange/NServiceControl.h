//
// Created by strohhalm on 16.07.15.
//

#ifndef NWEBMEDIA_NSERVICECONTROL_H
#define NWEBMEDIA_NSERVICECONTROL_H

#include <nbase/NBaseType.h>

namespace nox
{
    namespace service
    {
        namespace exchange
        {
            struct _NServiceControl
            {
                nchar  ServiceName[256];
                nchar  FunctionName[256];
                nulong Size;
            };

            class NServiceControl
            {
            protected:
                NString * m_ServiceName;
                NString * m_FunctionName;
            public:
                NServiceControl();
                NServiceControl(const NString & serviceName, const NString & functionName);
                NServiceControl(const NServiceControl & other);
                NServiceControl(const _NServiceControl & from);
                virtual ~NServiceControl();
                virtual void setServiceName(const NString & serviceName);
                virtual const NString & getServiceName();
                virtual void setFunctionName(const NString & functionName);
                virtual const NString & getFunctionName();
                virtual void toStruct(_NServiceControl & input);
            };
        }
    }
}

#endif //NWEBMEDIA_NSERVICECONTROL_H
