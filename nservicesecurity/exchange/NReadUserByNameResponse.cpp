//
// Created by strohhalm on 27.07.15.
//

#include "NReadUserByNameResponse.h"

namespace nox
{
    namespace service
    {
        namespace exchange
        {
            namespace security
            {
                NReadUserByNameResponse::NReadUserByNameResponse() : INServiceResponse<_NReadUserByNameResponse>()
                {
                    m_Data = new NUserData();
                }

                NReadUserByNameResponse::NReadUserByNameResponse(const NServiceResponseHead & head, const NUserData & data) : INServiceResponse<_NReadUserByNameResponse>(head)
                {
                    m_Data = new NUserData(data);
                }

                NReadUserByNameResponse::NReadUserByNameResponse(const NReadUserByNameResponse & other) : INServiceResponse<_NReadUserByNameResponse>(other)
                {
                    m_Data = new NUserData(*other.m_Data);
                }

                NReadUserByNameResponse::NReadUserByNameResponse(const _NReadUserByNameResponse & from) : INServiceResponse<_NReadUserByNameResponse>(from)
                {
                    m_Data = new NUserData(from.Data);
                }

                NReadUserByNameResponse::~NReadUserByNameResponse()
                {
                    if (m_Data != NULL)
                        delete m_Data;
                }

                NUserData & NReadUserByNameResponse::getData()
                {
                    return *m_Data;
                }

                void NReadUserByNameResponse::toStruct(_NReadUserByNameResponse & input)
                {
                    memset(&input, 0, sizeof(_NReadUserByNameResponse));

                    getHead().toStruct(input.Head);
                    getData().toStruct(input.Data);

                    input.Head.Control.Size = sizeof(_NReadUserByNameResponse);
                }
            }
        }
    }
}