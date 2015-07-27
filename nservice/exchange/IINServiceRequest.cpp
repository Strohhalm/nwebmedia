//
// Created by strohhalm on 16.07.15.
//

#include "IINServiceRequest.h"

namespace nox
{
    namespace service
    {
        namespace exchange
        {
            IINServiceRequest::IINServiceRequest()
            {
                m_Head = new NServiceRequestHead();
            }

            IINServiceRequest::IINServiceRequest(const NServiceRequestHead & head)
            {
                m_Head = new NServiceRequestHead(head);
            }

            IINServiceRequest::IINServiceRequest(const IINServiceRequest & other)
            {
                m_Head = new NServiceRequestHead(*other.m_Head);
            }

            IINServiceRequest::IINServiceRequest(const _IINServiceRequest & from)
            {
                m_Head = new NServiceRequestHead(from.Head);
            }

            IINServiceRequest::~IINServiceRequest()
            {
                if (m_Head != NULL)
                    delete m_Head;
            }

            NServiceRequestHead & IINServiceRequest::getHead()
            {
                return *m_Head;
            }
        }
    }
}