//
// Created by strohhalm on 24.07.15.
//

#include "NKeyProviderResponse.h"

namespace nox
{
    namespace service
    {
        namespace exchange
        {
            namespace infra
            {
                NKeyProviderResponse::NKeyProviderResponse() : INServiceResponse<_NKeyProviderResponse>()
                {
                    m_Data = new NKeyProviderKey();
                }

                NKeyProviderResponse::NKeyProviderResponse(const NServiceResponseHead & head, const NKeyProviderKey & data) : INServiceResponse<_NKeyProviderResponse>(head)
                {
                    m_Data = new NKeyProviderKey(data);
                }

                NKeyProviderResponse::NKeyProviderResponse(const NKeyProviderResponse & other) : INServiceResponse<_NKeyProviderResponse>(other)
                {
                    m_Data = new NKeyProviderKey(*other.m_Data);
                }

                NKeyProviderResponse::NKeyProviderResponse(const _NKeyProviderResponse & from) : INServiceResponse<_NKeyProviderResponse>(from)
                {
                    m_Data = new NKeyProviderKey(from.Data);
                }

                NKeyProviderResponse::~NKeyProviderResponse()
                {
                    if (m_Data != NULL)
                        delete m_Data;
                }

                NKeyProviderKey & NKeyProviderResponse::getData()
                {
                    return *m_Data;
                }

                void NKeyProviderResponse::toStruct(_NKeyProviderResponse & input)
                {
                    memset(&input, 0, sizeof(_NKeyProviderResponse));

                    getHead().toStruct(input.Head);
                    getData().toStruct(input.Data);

                    input.Head.Control.Size = sizeof(_NKeyProviderResponse);
                }
            }
        }
    }
}