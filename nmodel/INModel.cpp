//
// Created by strohhalm on 03.06.15.
//

#include "INModel.h"
#include <nbase/collection/NMap.h>

namespace nox
{
    namespace model
    {
        INModel::INModel(const NString &tableName) : INObject()
        {
            m_TableName = new NString(tableName);
            m_Columns   = new NMap<NString, INModelColumn *>();
        }

        INModel::INModel(const INModel & other) : INObject()
        {
            m_TableName = new NString(*other.m_TableName);
            m_Columns   = new NMap<NString, INModelColumn *>();
        }

        INModel::~INModel()
        {
            if (m_TableName != NULL)
                delete m_TableName;
            if (m_Columns != NULL)
            {
                INList<NString> * keyList = m_Columns->getKeyList();
                for (nlong i = 0; i < keyList->getSize(); i++)
                {
                    if (m_Columns->get(keyList->get(i)) != NULL)
                        delete m_Columns->get(keyList->get(i));
                }
                delete m_Columns;
            }
        }
    }
}