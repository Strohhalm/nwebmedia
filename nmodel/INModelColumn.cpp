//
// Created by strohhalm on 03.06.15.
//

#include "INModelColumn.h"

namespace nox
{
    namespace model
    {
        INModelColumn::INModelColumn(const NString &columnName) : INObject()
        {
            m_ColumnName = new NString(columnName);
        }

        INModelColumn::~INModelColumn()
        {
            if (m_ColumnName != NULL)
                delete m_ColumnName;
        }

        const NString & INModelColumn::getColumnName() const
        {
            return *m_ColumnName;
        }
    }
}