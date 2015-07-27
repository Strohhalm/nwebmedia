//
// Created by strohhalm on 16.07.15.
//

#include "IINServiceResponse.h"

namespace nox
{
    namespace service
    {
        namespace exchange
        {
            IINServiceResponse::IINServiceResponse()
            {
                m_Head = new NServiceResponseHead();
            }

            IINServiceResponse::IINServiceResponse(const NServiceResponseHead & head)
            {
                m_Head = new NServiceResponseHead(head);
            }

            IINServiceResponse::IINServiceResponse(const IINServiceResponse & other)
            {
                m_Head = new NServiceResponseHead(*other.m_Head);
            }

            IINServiceResponse::IINServiceResponse(const _IINServiceResponse & from)
            {
                m_Head = new NServiceResponseHead(from.Head);
            }

            IINServiceResponse::~IINServiceResponse()
            {
                if (m_Head != NULL)
                    delete m_Head;
            }

            NServiceResponseHead & IINServiceResponse::getHead()
            {
                return *m_Head;
            }
        }
    }
}