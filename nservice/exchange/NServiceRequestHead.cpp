//
// Created by strohhalm on 16.07.15.
//

#include "NServiceRequestHead.h"

namespace nox
{
    namespace service
    {
        namespace  exchange
        {
            NServiceRequestHead::NServiceRequestHead()
            {
                m_Control = new NServiceControl();
                m_Context = new NServiceContext();
            }

            NServiceRequestHead::NServiceRequestHead(const NServiceControl & control, const NServiceContext & context)
            {
                m_Control = new NServiceControl(control);
                m_Context = new NServiceContext(context);
            }

            NServiceRequestHead::NServiceRequestHead(const NServiceRequestHead & other)
            {
                m_Control = new NServiceControl(*other.m_Control);
                m_Context = new NServiceContext(*other.m_Context);
            }

            NServiceRequestHead::NServiceRequestHead(const _NServiceRequestHead & from)
            {
                m_Control = new NServiceControl(from.Control);
                m_Context = new NServiceContext(from.Context);
            }

            NServiceRequestHead::~NServiceRequestHead()
            {
                if (m_Control != NULL)
                    delete m_Control;
                if (m_Context != NULL)
                    delete m_Context;
            }

            NServiceControl & NServiceRequestHead::getControl()
            {
                return *m_Control;
            }

            NServiceContext & NServiceRequestHead::getContext()
            {
                return *m_Context;
            }

            void NServiceRequestHead::toStruct(_NServiceRequestHead & input)
            {
                memset(&input, 0, sizeof(_NServiceRequestHead));

                getContext().toStruct(input.Context);
                getControl().toStruct(input.Control);
            }
        }
    }
}