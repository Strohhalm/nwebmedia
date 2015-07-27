//
// Created by strohhalm on 25.07.15.
//

#include "NInfKeysModelAccess.h"
#include <nmodel/NTypedResultSet.h>

namespace nox
{
    namespace infra
    {
        namespace model
        {
            NInfKeysModelAccess::NInfKeysModelAccess() : INModelAccess(NCOMPONENT_SERVICE_INFRA, NXS(NOX_INF_KEYS))
            {
            }

            NInfKeysModelAccess::~NInfKeysModelAccess()
            {
            }

            void NInfKeysModelAccess::insert(const NInfKeysModel & model)
            {
                NAssertNull(model.getKeyClass())
                NAssertNull(model.getComponent())
                NAssertNull(model.getKeyValue())

                INIT_SQL_SECTION

                INPreparedStatement * statement = getPreparedStatement("INSERT");

                if (statement->getStatement().length() <= 0)
                {
//@formatter:off
                    INSERT INTO TA(NOX_INF_KEYS)
                            LEFT_BRACKET
                                FI(KEY_CLASS) COMMA
                                FI(COMPONENT) COMMA
                                FI(KEY_VALUE)
                            RIGHT_BRACKET
                        VALUES
                            LEFT_BRACKET
                                PA(keyClass) COMMA
                                PA(component) COMMA
                                PA(keyValue)
                            RIGHT_BRACKET
//@formatter:on
                    statement->setStatement(SQL_STRING);
                }

                statement->clearParameters();
                statement->addParameter(CreateNamedParameter(keyClass, NString, model.getKeyClass()));
                statement->addParameter(CreateNamedParameter(component, NString, model.getComponent()));
                statement->addParameter(CreateNamedParameter(keyValue, NLong, model.getKeyValue()));

                statement->prepare();
                if (statement->execute() <= 0)
                    throw NRuntimeException("Could not insert a entry");
            }

            void NInfKeysModelAccess::update(const NInfKeysModel & model)
            {
                NAssertNull(model.getKeyClass())
                NAssertNull(model.getComponent())
                NAssertNull(model.getKeyValue())

                INIT_SQL_SECTION

                INPreparedStatement * statement = getPreparedStatement("UPDATE");

                if (statement->getStatement().length() <= 0)
                {
//@formatter:off
                    UPDATE TA(NOX_INF_KEYS)
                        SET FI(KEY_VALUE) EQ PA(keyValue)
                     WHERE FI(KEY_CLASS) EQ PA(keyClass)
                       AND FI(COMPONENT) EQ PA(component)
//@formatter:on
                    statement->setStatement(SQL_STRING);
                }

                statement->clearParameters();
                statement->addParameter(CreateNamedParameter(keyClass, NString, model.getKeyClass()));
                statement->addParameter(CreateNamedParameter(component, NString, model.getComponent()));
                statement->addParameter(CreateNamedParameter(keyValue, NLong, model.getKeyValue()));

                statement->prepare();
                if (statement->execute() <= 0)
                    throw NRuntimeException("Could not update a entry");
            }

            INTypedResultSet<NInfKeysModel> * NInfKeysModelAccess::read(const NString & keyClass, const NString & component)
            {
                INIT_SQL_SECTION

                INPreparedStatement * statement = getPreparedStatement("READ");

                if (statement->getStatement().length() <= 0)
                {
//@formatter:off
                    SELECT FI(KEY_CLASS) COMMA
                           FI(COMPONENT) COMMA
                           FI(KEY_VALUE)
                      FROM TA(NOX_INF_KEYS)
                     WHERE FI(KEY_CLASS) EQ PA(keyClass)
                       AND FI(COMPONENT) EQ PA(component)
//@formatter:on
                    statement->setStatement(SQL_STRING);
                }

                statement->clearParameters();
                statement->addParameter(CreateNamedParameter(keyClass, NString, keyClass));
                statement->addParameter(CreateNamedParameter(component, NString, component));

                if (statement->executeQuery())
                    return new NTypedResultSet<NInfKeysModel>(statement->getResultSet());
                return NULL;
            }

            nint NInfKeysModelAccess::compareTo(const INObject * other) const
            {
                if (this == other)
                    return 0;
                try
                {
                    const NInfKeysModelAccess * obj = dynamic_cast<const NInfKeysModelAccess *>(other);

                    if (obj != NULL)
                    {
                        if (this > obj)
                            return 1;
                        return -1;
                    }
                    else
                    {
                        return 1;
                    }
                }
                catch (bad_cast &)
                {
                    return 1;
                }
            }
        }
    }
}