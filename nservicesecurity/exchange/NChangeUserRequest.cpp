//
// Created by strohhalm on 25.07.15.
//

#include "NChangeUserRequest.h"

namespace nox
{
    namespace service
    {
        namespace exchange
        {
            namespace security
            {
                NChangeUserRequest::NChangeUserRequest() : INServiceRequest<_NChangeUserRequest>()
                {
                    m_Data = new NUserData();
                }

                NChangeUserRequest::NChangeUserRequest(const NServiceRequestHead & head, const NUserData & data) : INServiceRequest<_NChangeUserRequest>(head)
                {
                    m_Data = new NUserData(data);
                }

                NChangeUserRequest::NChangeUserRequest(const NChangeUserRequest & other) : INServiceRequest<_NChangeUserRequest>(other)
                {
                    m_Data = new NUserData(*other.m_Data);
                }

                NChangeUserRequest::NChangeUserRequest(const _NChangeUserRequest & from) : INServiceRequest<_NChangeUserRequest>(from)
                {
                    m_Data = new NUserData(from.Data);
                }

                NChangeUserRequest::~NChangeUserRequest()
                {
                    if (m_Data != NULL)
                        delete m_Data;
                }

                NUserData & NChangeUserRequest::getData()
                {
                    return *m_Data;
                }

                void NChangeUserRequest::toStruct(_NChangeUserRequest & input)
                {
                    memset(&input, 0, sizeof(_NChangeUserRequest));

                    getHead().toStruct(input.Head);
                    getData().toStruct(input.Data);

                    input.Head.Control.Size = sizeof(_NChangeUserRequest);
                }
            }
        }
    }
}