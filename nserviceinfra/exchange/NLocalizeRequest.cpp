//
// Created by strohhalm on 16.07.15.
//

#include "NLocalizeRequest.h"

namespace nox
{
    namespace service
    {
        namespace exchange
        {
            namespace infra
            {
                NLocalizeRequest::NLocalizeRequest() : INServiceRequest<_NLocalizeRequest>()
                {
                    m_Data = new NLocalisationKey();
                }

                NLocalizeRequest::NLocalizeRequest(const NServiceRequestHead & head, const NLocalisationKey & data) : INServiceRequest<_NLocalizeRequest>(head)
                {
                    m_Data = new NLocalisationKey(data);
                }

                NLocalizeRequest::NLocalizeRequest(const NLocalizeRequest & other) : INServiceRequest<_NLocalizeRequest>(other)
                {
                    m_Data = new NLocalisationKey(*other.m_Data);
                }

                NLocalizeRequest::NLocalizeRequest(const _NLocalizeRequest & from) : INServiceRequest<_NLocalizeRequest>(from)
                {
                    m_Data = new NLocalisationKey(from.Data);
                }

                NLocalizeRequest::~NLocalizeRequest()
                {
                    if (m_Data != NULL)
                        delete m_Data;
                }

                NLocalisationKey & NLocalizeRequest::getData()
                {
                    return *m_Data;
                }

                void NLocalizeRequest::toStruct(_NLocalizeRequest & input)
                {
                    memset(&input, 0, sizeof(_NLocalizeRequest));

                    getHead().toStruct(input.Head);
                    getData().toStruct(input.Data);

                    input.Head.Control.Size = sizeof(_NLocalizeRequest);
                }
            }
        }
    }
}