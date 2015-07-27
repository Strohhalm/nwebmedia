//
// Created by strohhalm on 16.07.15.
//

#include "NLocalizeResponse.h"

namespace nox
{
    namespace service
    {
        namespace exchange
        {
            namespace infra
            {
                NLocalizeResponse::NLocalizeResponse() : INServiceResponse<_NLocalizeResponse>()
                {
                    m_Data = new NLocalisationValue();
                }

                NLocalizeResponse::NLocalizeResponse(const NServiceResponseHead & head, const NLocalisationValue data) : INServiceResponse<_NLocalizeResponse>(head)
                {
                    m_Data = new NLocalisationValue(data);
                }

                NLocalizeResponse::NLocalizeResponse(const NLocalizeResponse & other) : INServiceResponse<_NLocalizeResponse>(other)
                {
                    m_Data = new NLocalisationValue(*other.m_Data);
                }

                NLocalizeResponse::NLocalizeResponse(const _NLocalizeResponse & from) : INServiceResponse<_NLocalizeResponse>(from)
                {
                    m_Data = new NLocalisationValue(from.Data);
                }

                NLocalizeResponse::~NLocalizeResponse()
                {
                    if (m_Data != NULL)
                        delete m_Data;
                }

                NLocalisationValue & NLocalizeResponse::getData()
                {
                    return *m_Data;
                }

                void NLocalizeResponse::toStruct(_NLocalizeResponse & input)
                {
                    memset(&input, 0, sizeof(_NLocalizeResponse));

                    getHead().toStruct(input.Head);
                    getData().toStruct(input.Data);

                    input.Head.Control.Size = sizeof(_NLocalizeResponse);
                }
            }
        }
    }
}