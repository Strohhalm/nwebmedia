//
// Created by strohhalm on 25.07.15.
//

#include "NChangeUserResponse.h"

namespace nox
{
    namespace service
    {
        namespace exchange
        {
            namespace security
            {
                NChangeUserResponse::NChangeUserResponse() : INServiceResponse<_NChangeUserResponse>()
                {
                    m_Data = new NUserData();
                }

                NChangeUserResponse::NChangeUserResponse(const NServiceResponseHead & head, const NUserData & data) : INServiceResponse<_NChangeUserResponse>(head)
                {
                    m_Data = new NUserData(data);
                }

                NChangeUserResponse::NChangeUserResponse(const NChangeUserResponse & other) : INServiceResponse<_NChangeUserResponse>(other)
                {
                    m_Data = new NUserData(*other.m_Data);
                }

                NChangeUserResponse::NChangeUserResponse(const _NChangeUserResponse & from) : INServiceResponse<_NChangeUserResponse>(from)
                {
                    m_Data = new NUserData(from.Data);
                }

                NChangeUserResponse::~NChangeUserResponse()
                {
                    if (m_Data != NULL)
                        delete m_Data;
                }

                NUserData & NChangeUserResponse::getData()
                {
                    return *m_Data;
                }

                void NChangeUserResponse::toStruct(_NChangeUserResponse & input)
                {
                    memset(&input, 0, sizeof(_NChangeUserResponse));

                    getHead().toStruct(input.Head);
                    getData().toStruct(input.Data);

                    input.Head.Control.Size = sizeof(_NChangeUserResponse);
                }
            }
        }
    }
}