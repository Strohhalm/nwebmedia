//
// Created by strohhalm on 25.07.15.
//

#include "NCreateUserRequest.h"

namespace nox
{
    namespace service
    {
        namespace exchange
        {
            namespace security
            {
                NCreateUserRequest::NCreateUserRequest() : INServiceRequest<_NCreateUserRequest>()
                {
                    m_Data = new NUserData();
                }

                NCreateUserRequest::NCreateUserRequest(const NServiceRequestHead & head, const NUserData & data) : INServiceRequest<_NCreateUserRequest>(head)
                {
                    m_Data = new NUserData(data);
                }

                NCreateUserRequest::NCreateUserRequest(const NCreateUserRequest & other) : INServiceRequest<_NCreateUserRequest>(other)
                {
                    m_Data = new NUserData(*other.m_Data);
                }

                NCreateUserRequest::NCreateUserRequest(const _NCreateUserRequest & from) : INServiceRequest<_NCreateUserRequest>(from)
                {
                    m_Data = new NUserData(from.Data);
                }

                NCreateUserRequest::~NCreateUserRequest()
                {
                    if (m_Data != NULL)
                        delete m_Data;
                }

                NUserData & NCreateUserRequest::getData()
                {
                    return *m_Data;
                }

                void NCreateUserRequest::toStruct(_NCreateUserRequest & input)
                {
                    memset(&input, 0, sizeof(_NCreateUserRequest));

                    getHead().toStruct(input.Head);
                    getData().toStruct(input.Data);

                    input.Head.Control.Size = sizeof(_NCreateUserRequest);
                }
            }
        }
    }
}