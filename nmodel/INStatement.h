//
// Created by strohhalm on 09.07.15.
//

#ifndef NWEBMEDIA_INSTATEMENT_H
#define NWEBMEDIA_INSTATEMENT_H

#include <nbase/INObject.h>
#include <nmodel/INResultSet.h>

namespace nox
{
    namespace model
    {
        class INStatement : public INObject
        {
        protected:
            NString               * m_SqlStatement;
        public:
            INStatement();
            INStatement(const NString & statement);
            virtual ~INStatement();
            virtual void setStatement(const NString & statement);
            virtual const NString & getStatement() const;
            virtual nlong execute() = 0;
            virtual nbool executeQuery() = 0;
            virtual INResultSet * getResultSet() = 0;
            virtual void close() = 0;
        };
    }
}

#endif //NWEBMEDIA_INSTATEMENT_H
