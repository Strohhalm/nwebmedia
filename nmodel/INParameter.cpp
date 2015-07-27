//
// Created by strohhalm on 05.06.15.
//

#include "INParameter.h"

namespace nox
{
    namespace model
    {
        INParameter::INParameter() : INObject()
        {
            m_Name      = new NString();
        }

        INParameter::INParameter(const NString &paramName) : INObject()
        {
            m_Name      = new NString(paramName);
        }

        INParameter::INParameter(const INParameter &other) : INObject()
        {
            m_Name      = new NString(*other.m_Name);
        }

        INParameter::~INParameter()
        {
            if (m_Name != NULL)
                delete m_Name;
        }

        const NString & INParameter::getName() const
        {
            return *m_Name;
        }
    }
}