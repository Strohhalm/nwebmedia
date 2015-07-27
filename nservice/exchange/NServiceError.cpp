//
// Created by strohhalm on 16.07.15.
//

#include "NServiceError.h"

namespace nox
{
    namespace service
    {
        namespace exchange
        {
            NServiceError::NServiceError()
            {
                m_ErrorCode = new NInteger();
                m_Message   = new NString();
            }

            NServiceError::NServiceError(const NInteger & errorCode, const NString & message)
            {
                m_ErrorCode = new NInteger(errorCode);
                m_Message   = new NString(message);
            }

            NServiceError::NServiceError(const NServiceError & other)
            {
                m_ErrorCode = new NInteger(*other.m_ErrorCode);
                m_Message   = new NString(*other.m_Message);
            }

            NServiceError::NServiceError(const _NServiceError & from)
            {
                m_ErrorCode = new NInteger(from.Code);
                m_Message   = new NString(from.Message);
            }

            NServiceError::~NServiceError()
            {
                if (m_ErrorCode != NULL)
                    delete m_ErrorCode;
                if (m_Message != NULL)
                    delete m_Message;
            }

            void NServiceError::setErrorCode(const NInteger & errorCode)
            {
                m_ErrorCode->setValue(errorCode);
            }

            const NInteger & NServiceError::getErrorCode()
            {
                return *m_ErrorCode;
            }

            void NServiceError::setMessage(const NString & message)
            {
                m_Message->assign(message);
            }

            const NString & NServiceError::getMessage()
            {
                return *m_Message;
            }

            void NServiceError::toStruct(_NServiceError & input)
            {
                memset(&input, 0, sizeof(_NServiceError));

                getMessage().copy(input.Message, getMessage().length());
                input.Code = getErrorCode().getValue();
            }
        }
    }
}