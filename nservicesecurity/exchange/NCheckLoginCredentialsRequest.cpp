//
// Created by strohhalm on 16.07.15.
//

#include "NCheckLoginCredentialsRequest.h"

namespace nox
{
    namespace service
    {
        namespace exchange
        {
            namespace security
            {
                NCheckLoginCredentialsRequest::NCheckLoginCredentialsRequest() : INServiceRequest<_NCheckLoginCredentialsRequest>()
                {
                    m_Data = new NLoginCredentials();
                }

                NCheckLoginCredentialsRequest::NCheckLoginCredentialsRequest(const NServiceRequestHead & head, const NLoginCredentials & data)  : INServiceRequest<_NCheckLoginCredentialsRequest>(head)
                {
                    m_Data = new NLoginCredentials(data);
                }

                NCheckLoginCredentialsRequest::NCheckLoginCredentialsRequest(const NCheckLoginCredentialsRequest & other) : INServiceRequest<_NCheckLoginCredentialsRequest>(other)
                {
                    m_Data = new NLoginCredentials(*other.m_Data);
                }

                NCheckLoginCredentialsRequest::NCheckLoginCredentialsRequest(const _NCheckLoginCredentialsRequest & from) : INServiceRequest<_NCheckLoginCredentialsRequest>(from)
                {
                    m_Data = new NLoginCredentials(from.Data);
                }

                NCheckLoginCredentialsRequest::~NCheckLoginCredentialsRequest()
                {
                    if (m_Data != NULL)
                        delete m_Data;
                }

                NLoginCredentials & NCheckLoginCredentialsRequest::getData()
                {
                    return *m_Data;
                }

                void NCheckLoginCredentialsRequest::toStruct(_NCheckLoginCredentialsRequest & input)
                {
                    memset(&input, 0, sizeof(_NCheckLoginCredentialsRequest));

                    getHead().toStruct(input.Head);
                    getData().toStruct(input.Data);

                    input.Head.Control.Size = sizeof(_NCheckLoginCredentialsRequest);
                }
            }
        }
    }
}