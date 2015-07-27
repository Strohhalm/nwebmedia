//
// Created by strohhalm on 16.07.15.
//

#include "NServiceControl.h"

namespace nox
{
    namespace service
    {
        namespace exchange
        {
            NServiceControl::NServiceControl()
            {
                m_ServiceName = new NString();
                m_FunctionName = new NString();
            }

            NServiceControl::NServiceControl(const NString & serviceName, const NString & functionName)
            {
                m_ServiceName = new NString(serviceName);
                m_FunctionName = new NString(functionName);
            }

            NServiceControl::NServiceControl(const NServiceControl & other)
            {
                m_ServiceName = new NString(*other.m_ServiceName);
                m_FunctionName = new NString(*other.m_FunctionName);
            }

            NServiceControl::NServiceControl(const _NServiceControl & from)
            {
                m_ServiceName = new NString(from.ServiceName);
                m_FunctionName = new NString(from.FunctionName);
            }

            NServiceControl::~NServiceControl()
            {
                if (m_ServiceName != NULL)
                    delete m_ServiceName;
                if (m_FunctionName != NULL)
                    delete m_FunctionName;
            }

            void NServiceControl::setServiceName(const NString & serviceName)
            {
                m_ServiceName->assign(serviceName);
            }

            const NString & NServiceControl::getServiceName()
            {
                return *m_ServiceName;
            }

            void NServiceControl::setFunctionName(const NString & functionName)
            {
                m_FunctionName->assign(functionName);
            }

            const NString & NServiceControl::getFunctionName()
            {
                return *m_FunctionName;
            }

            void NServiceControl::toStruct(_NServiceControl & input)
            {
                memset(&input, 0, sizeof(_NServiceControl));

                getServiceName().copy(input.ServiceName, getServiceName().length());
                getFunctionName().copy(input.FunctionName, getFunctionName().length());
            }
        }
    }
}