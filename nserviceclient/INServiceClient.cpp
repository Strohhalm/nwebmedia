//
// Created by strohhalm on 27.06.15.
//

#include "INServiceClient.h"

namespace nox
{
    namespace service
    {
        namespace client
        {
            INServiceClient::INServiceClient(IINClientSocket * socket) : IINServiceClient()
            {
                m_Socket = socket;
            }
            INServiceClient::~INServiceClient()
            {
                if (m_Socket != NULL)
                {
                    if (m_Socket->isConnected())
                        m_Socket->disconnect();
                    delete m_Socket;
                }
            }
        }
    }
}