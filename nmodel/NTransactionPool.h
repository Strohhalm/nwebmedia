//
// Created by strohhalm on 30.05.15.
//

#ifndef NTRANSACTIONPOOL_H
#define NTRANSACTIONPOOL_H

#include <nbase/INSingleton.h>
#include <nbase/collection/NMap.h>
#include <nbase/plugin/NPlugin.h>
#include <nmodel/INTransaction.h>
#include <nmodel/config/NConnectionConfigCache.h>

using namespace nox::collection;
using namespace nox::model::configuration;
using namespace nox::plugin;

namespace nox
{
    namespace model
    {
        class NTransactionPool : public INSingleton<NTransactionPool>
        {
            friend class INSingleton<NTransactionPool>;

        protected:
            class NTransaction : public INTransaction
            {
            protected:
                INMap<NString, NPlugin      *> * m_ConnectionLoaderMap;
                INMap<NString, INConnection *> * m_ConnectionMap;
            public:
                NTransaction();
                virtual ~NTransaction();
                virtual void commit();
                virtual void commit(const NString & connectionName);
                virtual void rollback();
                virtual void rollback(const NString & connectionName);
                virtual nint compareTo(const INObject * other) const;
            protected:
                virtual INConnection * getConnection(const NString & connectionName);
            };
            friend class NTransaction;
        protected:
            INMap<boost::thread::id, INTransaction *> * m_TransactionMap;
            NConnectionConfigCache                    * m_ConnectionConfigCache;
            boost::mutex                              * m_Mutex;
        protected:
            NTransactionPool();
            virtual ~NTransactionPool();
            virtual NConnectionConfig * getConnectionConfig(const NString & connectionName);
        public:
            virtual INTransaction * createTransaction();
            virtual INTransaction * getCurrentTransaction();
            virtual void destroyCurrentTransaction();
            virtual nint compareTo(const INObject * other) const;
        };
    }
}


#endif //NTRANSACTIONPOOL_H
