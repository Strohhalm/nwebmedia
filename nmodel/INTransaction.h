//
// Created by strohhalm on 30.05.15.
//

#ifndef INTRANSACTION_H
#define INTRANSACTION_H

#include <nbase/INObject.h>
#include <nmodel/enumeration/NConnectionType.h>
#include <nmodel/INConnection.h>

using namespace nox::model::enumeration;

namespace nox
{
    namespace model
    {
        class INTransaction : public INObject
        {
        protected:
            INTransaction();
        public:
            virtual ~INTransaction();
            virtual void commit() = 0;
            virtual void commit(const NString & connectionName) = 0;
            virtual void rollback() = 0;
            virtual void rollback(const NString & connectionName) = 0;
            virtual INConnection * getConnection(const NString & connectionName) = 0;
        };
    }
}


#endif //INTRANSACTION_H
