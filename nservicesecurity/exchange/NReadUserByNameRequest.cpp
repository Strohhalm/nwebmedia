//
// Created by strohhalm on 27.07.15.
//

#include "NReadUserByNameRequest.h"

namespace nox
{
    namespace service
    {
        namespace exchange
        {
            namespace security
            {
                NReadUserByNameRequest::NReadUserByNameRequest() : INServiceRequest<_NReadUserByNameRequest>()
                {
                    m_Data = new NReadUserByNameParam();
                }

                NReadUserByNameRequest::NReadUserByNameRequest(const NServiceRequestHead & head, const NReadUserByNameParam & data) : INServiceRequest<_NReadUserByNameRequest>(head)
                {
                    m_Data = new NReadUserByNameParam(data);
                }

                NReadUserByNameRequest::NReadUserByNameRequest(const NReadUserByNameRequest & other) : INServiceRequest<_NReadUserByNameRequest>(other)
                {
                    m_Data = new NReadUserByNameParam(*other.m_Data);
                }

                NReadUserByNameRequest::NReadUserByNameRequest(const _NReadUserByNameRequest & from) : INServiceRequest<_NReadUserByNameRequest>(from)
                {
                    m_Data = new NReadUserByNameParam(from.Data);
                }

                NReadUserByNameRequest::~NReadUserByNameRequest()
                {
                    if (m_Data != NULL)
                        delete m_Data;
                }

                NReadUserByNameParam & NReadUserByNameRequest::getData()
                {
                    return *m_Data;
                }

                void NReadUserByNameRequest::toStruct(_NReadUserByNameRequest & input)
                {
                    memset(&input, 0, sizeof(_NReadUserByNameRequest));

                    getHead().toStruct(input.Head);
                    getData().toStruct(input.Data);

                    input.Head.Control.Size = sizeof(_NReadUserByNameRequest);
                }
            }
        }
    }
}