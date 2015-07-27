//
// Created by strohhalm on 16.07.15.
//

#include "NLocalisationRequest.h"

namespace nox
{
    namespace service
    {
        namespace exchange
        {
            namespace infra
            {
                NLocalisationRequest::NLocalisationRequest() : INServiceRequest<_NLocalisationRequest>()
                {
                    m_Portion = new NLocalisationPortion();
                }

                NLocalisationRequest::NLocalisationRequest(const NServiceRequestHead & head, const NLocalisationPortion & portion) : INServiceRequest<_NLocalisationRequest>(head)
                {
                    m_Portion = new NLocalisationPortion(portion);
                }

                NLocalisationRequest::NLocalisationRequest(const NLocalisationRequest & other) : INServiceRequest<_NLocalisationRequest>(other)
                {
                    m_Portion = new NLocalisationPortion(*other.m_Portion);
                }

                NLocalisationRequest::NLocalisationRequest(const _NLocalisationRequest & from) : INServiceRequest<_NLocalisationRequest>(from)
                {
                    m_Portion = new NLocalisationPortion(from.Portion);
                }

                NLocalisationRequest::~NLocalisationRequest()
                {
                    if (m_Portion != NULL)
                        delete m_Portion;
                }

                NLocalisationPortion & NLocalisationRequest::getPortion()
                {
                    return *m_Portion;
                }

                void NLocalisationRequest::toStruct(_NLocalisationRequest & input)
                {
                    memset(&input, 0, sizeof(_NLocalisationRequest));

                    getHead().toStruct(input.Head);
                    getPortion().toStruct(input.Portion);

                    input.Head.Control.Size = sizeof(_NLocalisationRequest);
                }
            }
        }
    }
}