//
// Created by strohhalm on 16.06.15.
//

#ifndef NSQLBUILDER_H
#define NSQLBUILDER_H

#include <nbase/NBase.h>
#include <nbase/collection/NList.h>

using namespace nox::collection;

namespace nox
{
    namespace model
    {
        class NSqlBuilder
        {
        protected:
            NString * m_Statement;
        public:
            NSqlBuilder();
            NSqlBuilder(const NSqlBuilder & other);
            virtual ~NSqlBuilder();
            virtual NSqlBuilder & append(const NString & value);
            virtual const NString & asString();
        };
    }
}

#define INIT_SQL_SECTION NSqlBuilder builder;

#define SELECT builder.append(" SELECT ");
#define FROM   builder.append(" FROM ");
#define INSERT builder.append(" INSERT ");
#define INTO builder.append(" INTO ");
#define VALUES builder.append(" VALUES ");
#define UPDATE builder.append(" UPDATE ");
#define SET builder.append(" SET ");
#define COMMA builder.append(" , ");
#define WHERE builder.append(" WHERE ");
#define AND builder.append(" AND ");
#define OR builder.append(" OR ");
#define LEFT_BRACKET builder.append(" ( ");
#define RIGHT_BRACKET builder.append(" ) ");
#define IN builder.append(" IN ");
#define LIKE builder.append(" LIKE ");
#define EQ builder.append(" = ");
#define NOT_EQ builder.append(" <> ");
#define GT builder.append(" > ");
#define GT_OR_EQ builder.append(" >= ");
#define LT builder.append(" < ");
#define LT_OR_EQ builder.append(" <= ");
#define IS builder.append(" IS ");
#define NOT builder.append(" NOT ");
#define IS_NULL IS builder.append(" NULL ");
#define IS_NOT_NULL IS NOT builder.append(" NULL ");
#define RIGHT builder.append(" RIGHT ");
#define LEFT builder.append(" LEFT ");
#define JOIN builder.append(" JOIN ");
#define ON builder.append(" ON ");
#define FI(X) builder.append(" "); builder.append(NXS(X)); builder.append(" ");
#define QU(X) builder.append(" "); builder.append(NXS(X)); builder.append(" ");
#define TA(X) builder.append(" "); builder.append(NXS(X)); builder.append(" ");
#define TS(S, X) builder.append(" ");  builder.append(NXS(S)); builder.append("."); builder.append(NXS(X)); builder.append(" ");
#define PA(X) builder.append(":"); builder.append(NXS(X));
#define AS builder.append(" AS ");
#define BETWEEN builder.append(" BETWEEN ");
#define WITH builder.append(" WITH ");
#define ORDER builder.append(" ORDER ");
#define GROUP builder.append(" GROUP ");
#define HAVING builder.append("HAVING");
#define BY builder.append(" BY ");
#define ASC builder.append(" ASC ");
#define DESC builder.append(" DESC ");
#define ROW_NUMBER builder.append(" ROW_NUMBER() ");
#define OVER builder.append(" OVER ");
#define LIMIT builder.append(" LIMIT ");
#define OFFSET builder.append(" OFFSET ");
#define SEMICOLON builder.append(" ; ");

#define SQL_STRING builder.asString()

#endif //NSQLBUILDER_H
