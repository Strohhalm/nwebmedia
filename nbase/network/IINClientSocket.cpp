//
// Created by strohhalm on 27.06.15.
//

#include "IINClientSocket.h"

namespace nox
{
    namespace network
    {
        IINClientSocket::IINClientSocket(const NString & service)
        {
            m_Host = NULL;
            m_Service = new NString(service);
        }

        IINClientSocket::IINClientSocket(const NString & host, const NString & service)
        {
            m_Host = new NString(host);
            m_Service = new NString(service);
        }

        IINClientSocket::~IINClientSocket()
        {
            if (m_Host != NULL)
                delete m_Host;
            if (m_Service != NULL)
                delete m_Service;
        }
    }
}