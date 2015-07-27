//
// Created by strohhalm on 24.07.15.
//

#include "NKeyProviderRequest.h"

namespace nox
{
    namespace service
    {
        namespace exchange
        {
            namespace infra
            {
                NKeyProviderRequest::NKeyProviderRequest() : INServiceRequest<_NKeyProviderRequest>()
                {
                    m_Data = new NKeyProviderKeyReference();
                }

                NKeyProviderRequest::NKeyProviderRequest(const NServiceRequestHead & head, const NKeyProviderKeyReference & data) : INServiceRequest<_NKeyProviderRequest>(head)
                {
                    m_Data = new NKeyProviderKeyReference(data);
                }

                NKeyProviderRequest::NKeyProviderRequest(const NKeyProviderRequest & other) : INServiceRequest<_NKeyProviderRequest>(other)
                {
                    m_Data = new NKeyProviderKeyReference(*other.m_Data);
                }

                NKeyProviderRequest::NKeyProviderRequest(const _NKeyProviderRequest & from) : INServiceRequest<_NKeyProviderRequest>(from)
                {
                    m_Data = new NKeyProviderKeyReference(from.Data);
                }

                NKeyProviderRequest::~NKeyProviderRequest()
                {
                    if (m_Data != NULL)
                        delete m_Data;
                }

                NKeyProviderKeyReference & NKeyProviderRequest::getData()
                {
                    return *m_Data;
                }

                void NKeyProviderRequest::toStruct(_NKeyProviderRequest & input)
                {
                    memset(&input, 0, sizeof(_NKeyProviderRequest));

                    getHead().toStruct(input.Head);
                    getData().toStruct(input.Data);

                    input.Head.Control.Size = sizeof(_NKeyProviderRequest);
                }
            }
        }
    }
}