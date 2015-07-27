//
// Created by strohhalm on 25.07.15.
//

#include "NCreateUserResponse.h"

namespace nox
{
    namespace service
    {
        namespace exchange
        {
            namespace security
            {
                NCreateUserResponse::NCreateUserResponse() : INServiceResponse<_NCreateUserResponse>()
                {
                    m_Data = new NUserData();
                }

                NCreateUserResponse::NCreateUserResponse(const NServiceResponseHead & head, const NUserData & data) : INServiceResponse<_NCreateUserResponse>(head)
                {
                    m_Data = new NUserData(data);
                }

                NCreateUserResponse::NCreateUserResponse(const NCreateUserResponse & other) : INServiceResponse<_NCreateUserResponse>(other)
                {
                    m_Data = new NUserData(*other.m_Data);
                }

                NCreateUserResponse::NCreateUserResponse(const _NCreateUserResponse & from) : INServiceResponse<_NCreateUserResponse>(from)
                {
                    m_Data = new NUserData(from.Data);
                }

                NCreateUserResponse::~NCreateUserResponse()
                {
                    if (m_Data != NULL)
                        delete m_Data;
                }

                NUserData & NCreateUserResponse::getData()
                {
                    return *m_Data;
                }

                void NCreateUserResponse::toStruct(_NCreateUserResponse & input)
                {
                    memset(&input, 0, sizeof(_NCreateUserResponse));

                    getHead().toStruct(input.Head);
                    getData().toStruct(input.Data);

                    input.Head.Control.Size = sizeof(_NCreateUserResponse);
                }
            }
        }
    }
}