//
// Created by strohhalm on 03.06.15.
//

#ifndef INMODELCOLUMN_H
#define INMODELCOLUMN_H

#include <nbase/INObject.h>

using namespace nox;

namespace nox
{
    namespace model
    {
        class INModelColumn : public INObject
        {
        protected:
            NString * m_ColumnName;
        public:
            INModelColumn(const NString & columnName);
            virtual ~INModelColumn();
            virtual const NString & getColumnName() const;
            virtual size_t getType() const = 0;
        };
    }
}

#endif //INMODELCOLUMN_H
