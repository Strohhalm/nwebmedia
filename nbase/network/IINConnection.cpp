//
// Created by strohhalm on 19.06.15.
//

#include "IINConnection.h"


namespace nox
{
    namespace network
    {
        IINConnection::IINConnection() : INThread()
        {
            m_BytesRead = 0;
        }

        IINConnection::~IINConnection()
        {
        }

        void IINConnection::setBytesRead(nsize bytesRead)
        {
            m_BytesRead = bytesRead;
        }

        nsize IINConnection::getBytesRead()
        {
            return m_BytesRead;
        }
    }
}