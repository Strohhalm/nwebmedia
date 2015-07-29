//
// Created by strohhalm on 27.05.15.
//

#include <nbase/NException.h>

namespace nox
{
    NException::NException() : INObject() , exception()
    {
        m_Message = new NString("Unknown reason");
    }

    NException::NException(const NString & message) : INObject() , exception()
    {
        m_Message = new NString(message);
    }

    NException::~NException()
    {
        if (m_Message != NULL)
            delete m_Message;
    }

    bool NException::isCritical() const
    {
        return true;
    }

    const NString & NException::getMessage() const
    {
        return *m_Message;
    }

    const char * NException::what() const _GLIBCXX_USE_NOEXCEPT
    {
        return m_Message->c_str();
    }

    nint NException::compareTo(const INObject *other) const
    {
        try
        {
            const NException * obj = dynamic_cast<const NException *>(other);

            if (obj != NULL)
            {
                if (obj == this)
                    return 0;

                if (m_Message != NULL)
                {
                    return m_Message->compare(obj->getMessage());
                }
                else
                {
                    return obj->getMessage().compare(*m_Message) * -1;
                }
            }
            else
            {
                return 1;
            }
        }
        catch (bad_cast &)
        {
            return 1;
        }
    }
}
