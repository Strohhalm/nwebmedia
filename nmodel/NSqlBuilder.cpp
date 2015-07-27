//
// Created by strohhalm on 16.06.15.
//

#include "NSqlBuilder.h"

namespace nox
{
    namespace model
    {
        NSqlBuilder::NSqlBuilder()
        {
            m_Statement = new NString();
        }

        NSqlBuilder::NSqlBuilder(const NSqlBuilder &other)
        {
            m_Statement = new NString(*other.m_Statement);
        }

        NSqlBuilder::~NSqlBuilder()
        {
            if (m_Statement != NULL)
                delete m_Statement;
        }

        const NString& NSqlBuilder::asString()
        {
            return *m_Statement;
        }

        NSqlBuilder & NSqlBuilder::append(const NString &value)
        {
            m_Statement->append(value);

            return *this;
        }
    }
}