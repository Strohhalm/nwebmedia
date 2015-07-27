//
// Created by strohhalm on 05.06.15.
//

#ifndef INPREPAREDSTATEMENT_H
#define INPREPAREDSTATEMENT_H

#include <nbase/INObject.h>
#include <nbase/collection/NList.h>
#include <nmodel/INStatement.h>
#include <nmodel/INParameter.h>

using namespace nox::collection;

namespace nox
{
    namespace model
    {
        class INPreparedStatement : public INStatement
        {
        protected:
            INList<INParameter *> * m_ParameterList;
            NString               * m_Name;
            NString               * m_PreparedSqlStatement;
        public:
            INPreparedStatement(const NString & name);
            INPreparedStatement(const NString & name, const NString & statement);
            virtual ~INPreparedStatement();
            virtual const NString & getName() const;
            virtual void addParameter(INParameter * param);
            virtual void clearParameters();
            virtual void prepare() = 0;
        };
    }
}

#endif //INSTATEMENT_H
