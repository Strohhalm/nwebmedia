//
// Created by strohhalm on 16.07.15.
//

#include "NLocalisationResponse.h"

namespace nox
{
    namespace service
    {
        namespace exchange
        {
            namespace infra
            {
                NLocalisationResponse::NLocalisationResponse() : INServiceResponse<_NLocalisationResponse>()
                {
                    m_Data = new NLocalisationList();
                }

                NLocalisationResponse::NLocalisationResponse(const NServiceResponseHead & head, const NLocalisationList & data) : INServiceResponse<_NLocalisationResponse>(head)
                {
                    m_Data = new NLocalisationList(data);
                }

                NLocalisationResponse::NLocalisationResponse(const NLocalisationResponse & other) : INServiceResponse<_NLocalisationResponse>(other)
                {
                    m_Data = new NLocalisationList(*other.m_Data);
                }

                NLocalisationResponse::NLocalisationResponse(const _NLocalisationResponse & from) : INServiceResponse<_NLocalisationResponse>(from)
                {
                    m_Data = new NLocalisationList(from.Data);
                }

                NLocalisationResponse::~NLocalisationResponse()
                {
                    if (m_Data != NULL)
                        delete m_Data;
                }

                NLocalisationList & NLocalisationResponse::getData()
                {
                    return *m_Data;
                }

                void NLocalisationResponse::toStruct(_NLocalisationResponse & input)
                {
                    memset(&input, 0, sizeof(_NLocalisationResponse));

                    getHead().toStruct(input.Head);
                    getData().toStruct(input.Data);

                    input.Head.Control.Size = sizeof(_NLocalisationResponse);
                }
            }
        }
    }
}