//
// Created by strohhalm on 16.07.15.
//

#include "NCheckLoginCredentialsResponse.h"

namespace nox
{
    namespace service
    {
        namespace exchange
        {
            namespace security
            {
                NCheckLoginCredentialsResponse::NCheckLoginCredentialsResponse() : INServiceResponse<_NCheckLoginCredentialsResponse>()
                {
                    m_Data = new NLoginCredentialsOk();
                }

                NCheckLoginCredentialsResponse::NCheckLoginCredentialsResponse(const NServiceResponseHead & head, const NLoginCredentialsOk & data) : INServiceResponse<_NCheckLoginCredentialsResponse>(head)
                {
                    m_Data = new NLoginCredentialsOk(data);
                }

                NCheckLoginCredentialsResponse::NCheckLoginCredentialsResponse(const NCheckLoginCredentialsResponse & other) : INServiceResponse<_NCheckLoginCredentialsResponse>(other)
                {
                    m_Data = new NLoginCredentialsOk(*other.m_Data);
                }

                NCheckLoginCredentialsResponse::NCheckLoginCredentialsResponse(const _NCheckLoginCredentialsResponse & from) : INServiceResponse<_NCheckLoginCredentialsResponse>(from)
                {
                    m_Data = new NLoginCredentialsOk(from.Data);
                }

                NCheckLoginCredentialsResponse::~NCheckLoginCredentialsResponse()
                {
                    if (m_Data != NULL)
                        delete m_Data;
                }

                NLoginCredentialsOk & NCheckLoginCredentialsResponse::getData()
                {
                    return *m_Data;
                }

                void NCheckLoginCredentialsResponse::toStruct(_NCheckLoginCredentialsResponse & input)
                {
                    memset(&input, 0, sizeof(_NCheckLoginCredentialsResponse));

                    getHead().toStruct(input.Head);
                    getData().toStruct(input.Data);

                    input.Head.Control.Size = sizeof(_NCheckLoginCredentialsResponse);
                }
            }
        }
    }
}