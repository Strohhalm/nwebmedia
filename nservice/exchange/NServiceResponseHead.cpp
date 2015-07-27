//
// Created by strohhalm on 16.07.15.
//

#include "NServiceResponseHead.h"

namespace nox
{
    namespace service
    {
        namespace exchange
        {
            NServiceResponseHead::NServiceResponseHead()
            {
                m_Context = new NServiceContext();
                m_Control = new NServiceControl();
                m_Error   = new NServiceError();
            }

            NServiceResponseHead::NServiceResponseHead(const NServiceControl & control, const NServiceContext & context, const NServiceError & error)
            {
                m_Context = new NServiceContext(context);
                m_Control = new NServiceControl(control);
                m_Error   = new NServiceError(error);
            }

            NServiceResponseHead::NServiceResponseHead(const NServiceResponseHead & other)
            {
                m_Context = new NServiceContext(*other.m_Context);
                m_Control = new NServiceControl(*other.m_Control);
                m_Error   = new NServiceError(*other.m_Error);
            }

            NServiceResponseHead::NServiceResponseHead(const _NServiceResponseHead & from)
            {
                m_Context = new NServiceContext(from.Context);
                m_Control = new NServiceControl(from.Control);
                m_Error   = new NServiceError(from.Error);
            }

            NServiceResponseHead::~NServiceResponseHead()
            {
                if (m_Context != NULL)
                    delete m_Context;
                if (m_Control != NULL)
                    delete m_Control;
                if (m_Error != NULL)
                    delete m_Error;
            }

            NServiceControl & NServiceResponseHead::getControl()
            {
                return *m_Control;
            }

            NServiceContext & NServiceResponseHead::getContext()
            {
                return *m_Context;
            }

            NServiceError & NServiceResponseHead::getError()
            {
                return *m_Error;
            }

            void NServiceResponseHead::toStruct(_NServiceResponseHead & input)
            {
                memset(&input, 0, sizeof(_NServiceResponseHead));

                getControl().toStruct(input.Control);
                getContext().toStruct(input.Context);
                getError().toStruct(input.Error);
            }
        }
    }
}