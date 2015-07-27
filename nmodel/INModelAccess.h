//
// Created by strohhalm on 03.06.15.
//

#ifndef INMODELACCESS_H
#define INMODELACCESS_H

#include <nbase/INObject.h>
#include <nbase/collection/NList.h>
#include <nbase/NBaseType.h>
#include <nbase/NRuntimeException.h>
#include <nbase/collection/NMap.h>
#include <nmodel/INTransaction.h>
#include <nmodel/NTransactionPool.h>
#include <nmodel/INModelColumn.h>
#include <nmodel/INTypedResultSet.h>
#include <nmodel/NModelColumn.h>
#include <nmodel/INParameter.h>
#include <nmodel/NParameter.h>
#include <nmodel/INPreparedStatement.h>
#include <nmodel/NSqlBuilder.h>
#include <nbase/NAssert.h>
#include <nbase/NTime.h>
#include "INConnection.h"

using namespace nox::collection;

#define CreateParameter(TYPE, VALUE)                                        \
    new NParameter<TYPE>("", VALUE)
#define CreateNamedParameter(NAME, TYPE, VALUE)                             \
    new NParameter<TYPE>(NXS(NAME), VALUE)

namespace nox
{
    namespace model
    {
        class INModelAccess : public INObject
        {
        protected:
            NString * m_Component;
            NString * m_TableName;
            INMap<NString, INPreparedStatement *> * m_StatementMap;
        public:
            INModelAccess(const NString & componentName, const NString & tableName);
            virtual ~INModelAccess();
        protected:
            virtual INPreparedStatement * getPreparedStatement(const NString & name);
            virtual INPreparedStatement * getPreparedStatement(const NString & name, const NString & statement);
        };
    }
}

#endif //INMODELACCESS_H
