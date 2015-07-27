//
// Created by strohhalm on 10.06.15.
//

#include <nmodel/NTypedResultSet.h>
#include "NSecUserGroupModelAccess.h"

namespace nox
{
    namespace security
    {
        namespace model
        {
            NSecUserGroupModelAccess::NSecUserGroupModelAccess() : INModelAccess(NCOMPONENT_SERVICE_SECURITY, NXS(NOX_SEC_USR_GRP))
            {
            }

            NSecUserGroupModelAccess::~NSecUserGroupModelAccess()
            {
            }

            void NSecUserGroupModelAccess::insert(NSecUserGroupModel * model)
            {
                NAssertNull(model)
                NAssertNull(model->getUserId())
                NAssertNull(model->getGroupId())
                NAssertNull(model->getValidFrom())
                NAssertNull(model->getValidTo())
                NAssertNull(model->getActive())

                INIT_SQL_SECTION

                INPreparedStatement * statement = getPreparedStatement("INSERT");
                if (statement->getStatement().length() <= 0)
                {
//@formatter:off
                    INSERT INTO TA(NOX_SEC_USR_GRP)
                        LEFT_BRACKET
                            FI(USER_ID) COMMA
                            FI(GROUP_ID) COMMA
                            FI(VALID_FROM) COMMA
                            FI(VALID_TO) COMMA
                            FI(ACTIVE)
                        RIGHT_BRACKET
                    VALUES
                        LEFT_BRACKET
                            PA(userId) COMMA
                            PA(groupId) COMMA
                            PA(validFrom) COMMA
                            PA(validTo) COMMA
                            PA(active)
                        RIGHT_BRACKET
//@formatter:on
                    statement->setStatement(SQL_STRING);
                }

                statement->clearParameters();
                statement->addParameter(CreateNamedParameter(userId, NInteger, model->getUserId()));
                statement->addParameter(CreateNamedParameter(groupId, NInteger, model->getGroupId()));
                statement->addParameter(CreateNamedParameter(validFrom, NDate, model->getValidFrom()));
                statement->addParameter(CreateNamedParameter(validTo, NDate, model->getValidTo()));
                statement->addParameter(CreateNamedParameter(active, NBool, model->getActive()));

                if (statement->execute() <= 0)
                    throw NRuntimeException("Could not insert a entry");
            }

            void NSecUserGroupModelAccess::update(NSecUserGroupModel * model)
            {
                NAssertNull(model)
                NAssertNull(model->getUserId())
                NAssertNull(model->getGroupId())
                NAssertNull(model->getValidFrom())
                NAssertNull(model->getValidTo())
                NAssertNull(model->getActive())

                INIT_SQL_SECTION

                INPreparedStatement * statement = getPreparedStatement("UPDATE");

                if (statement->getStatement().length() <= 0)
                {
//@formatter:off
                    UPDATE TA(NOX_SEC_USR_GRP)
                       SET FI(VALID_FROM) EQ PA(validFrom) COMMA
                           FI(VALID_TO) EQ PA(validTo) COMMA
                           FI(ACTIVE) EQ PA(active)
                     WHERE FI(USER_ID) EQ PA(userId)
                       AND FI(GROUP_ID) EQ PA(groupId)
//@formatter:on
                    statement->setStatement(SQL_STRING);
                }

                statement->clearParameters();
                statement->addParameter(CreateNamedParameter(userId, NInteger, model->getUserId()));
                statement->addParameter(CreateNamedParameter(groupId, NInteger, model->getGroupId()));
                statement->addParameter(CreateNamedParameter(validFrom, NDate, model->getValidFrom()));
                statement->addParameter(CreateNamedParameter(validTo, NDate, model->getValidTo()));
                statement->addParameter(CreateNamedParameter(active, NBool, model->getActive()));

                if (statement->execute() <= 0)
                    throw NRuntimeException("Could not update a entry");
            }

            INTypedResultSet<NSecUserGroupModel> * NSecUserGroupModelAccess::read(NInteger * userId, NInteger * groupId)
            {
                NAssertNull(userId)
                NAssertNull(groupId)

                INIT_SQL_SECTION

                INPreparedStatement * statement = getPreparedStatement("READ");

                if (statement->getStatement().length() <= 0)
                {
//@formatter:off
                    SELECT FI(USER_ID) COMMA
                           FI(GROUP_ID) COMMA
                           FI(VALID_FROM) COMMA
                           FI(VALID_TO) COMMA
                           FI(ACTIVE)
                      FROM TA(NOX_SEC_USR_GRP)
                     WHERE FI(USER_ID) EQ PA(userId)
                       AND FI(GROUP_ID) EQ PA(groupId)
//@formatter:on
                    statement->setStatement(SQL_STRING);
                }

                statement->clearParameters();
                statement->addParameter(CreateNamedParameter(userId, NInteger, userId));
                statement->addParameter(CreateNamedParameter(groupId, NInteger, groupId));

                statement->executeQuery();

                return new NTypedResultSet<NSecUserGroupModel>(statement->getResultSet());
            }
        }
    }
}