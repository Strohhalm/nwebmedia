//
// Created by strohhalm on 10.06.15.
//

#include <nmodel/NTypedResultSet.h>
#include "NSecGroupModelAccess.h"

namespace nox
{
    namespace security
    {
        namespace model
        {
            NSecGroupModelAccess::NSecGroupModelAccess() : INModelAccess(NCOMPONENT_SERVICE_SECURITY, NXS(NOX_SEC_GROUP))
            {
            }

            NSecGroupModelAccess::~NSecGroupModelAccess()
            {
            }

            void NSecGroupModelAccess::insert(NSecGroupModel * model)
            {
                NAssertNull(model)
                NAssertNull(model->getId())
                NAssertNull(model->getValidFrom())
                NAssertNull(model->getGroupName())
                NAssertNull(model->getActive())

                INIT_SQL_SECTION

                INPreparedStatement * statement = getPreparedStatement("INSERT");

                if (statement->getStatement().length() <= 0)
                {
//@formatter:off
                    INSERT INTO TA(NOX_SEC_GROUP)
                        LEFT_BRACKET
                            FI(ID) COMMA
                            FI(VALID_FROM) COMMA
                            FI(VALID_TO) COMMA
                            FI(GROUP_NAME) COMMA
                            FI(DESCRIPTION) COMMA
                            FI(ACTIVE)
                        RIGHT_BRACKET
                    VALUES
                        LEFT_BRACKET
                            PA(id) COMMA
                            PA(validFrom) COMMA
                            PA(validTo) COMMA
                            PA(groupname) COMMA
                            PA(description) COMMA
                            PA(active)
                        RIGHT_BRACKET
//@formatter:on
                    statement->setStatement(SQL_STRING);
                }

                statement->clearParameters();
                statement->addParameter(CreateNamedParameter(id, NInteger, model->getId()));
                statement->addParameter(CreateNamedParameter(validFrom, NDate, model->getValidFrom()));
                statement->addParameter(CreateNamedParameter(validTo, NDate, model->getValidTo()));
                statement->addParameter(CreateNamedParameter(groupname, NString, model->getGroupName()));
                statement->addParameter(CreateNamedParameter(description, NString, model->getGroupDescription()));
                statement->addParameter(CreateNamedParameter(active, NBool, model->getActive()));

                if (statement->execute() <= 0)
                    throw NRuntimeException("Could not insert a entry");
            }

            void NSecGroupModelAccess::update(NSecGroupModel * model)
            {
                NAssertNull(model)
                NAssertNull(model->getId())
                NAssertNull(model->getValidFrom())
                NAssertNull(model->getGroupName())
                NAssertNull(model->getActive())

                INIT_SQL_SECTION

                INPreparedStatement * statement = getPreparedStatement("UPDATE");

                if (statement->getStatement().length() <= 0)
                {
//@formatter:off
                    UPDATE TA(NOX_SEC_GROUP)
                       SET FI(VALID_FROM) EQ PA(validFrom) COMMA
                           FI(VALID_TO) EQ PA(validTo) COMMA
                           FI(GROUP_NAME) EQ PA(groupname) COMMA
                           FI(DESCRIPTION) EQ PA(description) COMMA
                           FI(ACTIVE) EQ PA(active)
                     WHERE FI(ID) EQ PA(id)
//@formatter:on
                    statement->setStatement(SQL_STRING);
                }

                statement->clearParameters();
                statement->addParameter(CreateNamedParameter(id, NInteger, model->getId()));
                statement->addParameter(CreateNamedParameter(validFrom, NDate, model->getValidFrom()));
                statement->addParameter(CreateNamedParameter(validTo, NDate, model->getValidTo()));
                statement->addParameter(CreateNamedParameter(groupname, NString, model->getGroupName()));
                statement->addParameter(CreateNamedParameter(description, NString, model->getGroupDescription()));
                statement->addParameter(CreateNamedParameter(active, NBool, model->getActive()));

                if (statement->execute() <= 0)
                    throw NRuntimeException("Could not update a entry");
            }

            INTypedResultSet<NSecGroupModel> * NSecGroupModelAccess::read(NInteger * groupId)
            {
                NAssertNull(groupId)

                INIT_SQL_SECTION

                INPreparedStatement * statement = getPreparedStatement("READ");

                if (statement->getStatement().length() <= 0)
                {
//@formatter:off
                    SELECT FI(ID) COMMA
                           FI(VALID_FROM) COMMA
                           FI(VALID_TO) COMMA
                           FI(GROUP_NAME) COMMA
                           FI(DESCRIPTION) COMMA
                           FI(ACTIVE) COMMA
                      FROM TA(NOX_SEC_GROUP)
                     WHERE FI(ID) EQ PA(groupId)
//@formatter:on

                    statement->setStatement(SQL_STRING);
                }
                statement->clearParameters();
                statement->addParameter(CreateNamedParameter(groupId, NInteger, groupId));

                statement->executeQuery();

                return new NTypedResultSet<NSecGroupModel>(statement->getResultSet());
            }

            INTypedResultSet<NSecGroupModel> * NSecGroupModelAccess::readGroupByName(NString * groupname, NBool * active,
                                                                                NDate * date)
            {
                NAssertNull(groupname)

                INIT_SQL_SECTION

                NString statementName = "READ_BY_GROUPNAME";
                if (active != NULL)
                    statementName += "_ACTIVE";
                if (date != NULL)
                    statementName += "_DUE_DATE";

                INPreparedStatement * statement = getPreparedStatement(statementName);

                if (statement->getStatement().length() <= 0)
                {
//@formatter:off
                    SELECT FI(ID) COMMA
                           FI(VALID_FROM) COMMA
                           FI(VALID_TO) COMMA
                           FI(GROUP_NAME) COMMA
                           FI(DESCRIPTION) COMMA
                           FI(ACTIVE)
                      FROM TA(NOX_SEC_GROUP)
                     WHERE FI(GROUP_NAME) EQ PA(groupname)
                    if (date != NULL)
                    {
                       AND FI(VALID_FROM) LT_OR_EQ PA(date)
                       AND LEFT_BRACKET PA(VALID_TO) GT_OR_EQ PA(date) OR
                                        PA(VALID_TO) IS_NULL RIGHT_BRACKET
                    }
                    if (active != NULL)
                    {
                       AND FI(ACTIVE) EQ PA(active)
                    }
//@formatter:on

                    statement->setStatement(SQL_STRING);
                }
                statement->clearParameters();
                statement->addParameter(CreateNamedParameter(groupname, NString, groupname));
                if (date != NULL)
                    statement->addParameter(CreateNamedParameter(date, NDate, date));
                if (active != NULL)
                    statement->addParameter(CreateNamedParameter(active, NBool, active));

                statement->executeQuery();

                return new NTypedResultSet<NSecGroupModel>(statement->getResultSet());
            }

            INTypedResultSet<NSecGroupModel> * NSecGroupModelAccess::readGroupByUserName(NString * username, NBool * active,
                                                                                    NDate * date)
            {
                NAssertNull(username)

                INIT_SQL_SECTION

                NString statementName = "READ_BY_USERNAME";
                if (active != NULL)
                    statementName += "_ACTIVE";
                if (date != NULL)
                    statementName += "_DUE_DATE";

                INPreparedStatement * statement = getPreparedStatement(statementName);

                if (statement->getStatement().length() <= 0)
                {
//@formatter:off
                    SELECT FI(G.ID) COMMA
                           FI(G.VALID_FROM) COMMA
                           FI(G.VALID_TO) COMMA
                           FI(G.GROUP_NAME) COMMA
                           FI(G.DESCRIPTION) COMMA
                           FI(G.ACTIVE)
                      FROM TA(NOX_SEC_GROUP) TA(G)
                     WHERE FI(G.ID) IN LEFT_BRACKET
                                        SELECT FI(UG.GROUP_ID)
                                          FROM TA(NOX_SEC_USR_GRP) TA(UG)
                                         WHERE FI(UG.USER_ID) IN LEFT_BRACKET
                                                                    SELECT FI(U.ID)
                                                                      FROM TA(NOX_SEC_USER) TA(U)
                                                                     WHERE FI(U.USER_NAME) EQ PA(username)
                    if (date != NULL)
                    {
                                                                       AND FI(U.VALID_FROM) LT_OR_EQ PA(date)
                                                                       AND LEFT_BRACKET PA(U.VALID_TO) GT_OR_EQ PA(date) OR
                                                                                        PA(U.VALID_TO) IS_NULL RIGHT_BRACKET
                    }
                    if (active != NULL)
                    {
                                                                       AND FI(ACTIVE) EQ PA(active)
                    }
                                                                RIGHT_BRACKET
                    if (date != NULL)
                    {
                                           AND FI(UG.VALID_FROM) LT_OR_EQ PA(date)
                                           AND LEFT_BRACKET FI(UG.VALID_TO) GT_OR_EQ PA(date)
                                                            FI(UG.VALID_TO) IS_NULL RIGHT_BRACKET
                    }
                    if (active != NULL)
                    {
                                           AND FI(UG.ACTIVE) EQ PA(active)
                    }
                                    RIGHT_BRACKET
                    if (date != NULL)
                    {
                       AND FI(G.VALID_FROM) LT_OR_EQ PA(date)
                       AND LEFT_BRACKET PA(G.VALID_TO) GT_OR_EQ PA(date) OR
                                        PA(G.VALID_TO) IS_NULL RIGHT_BRACKET
                    }
                    if (active != NULL)
                    {
                       AND FI(G.ACTIVE) EQ PA(active)
                    }
//@formatter:on
                    statement->setStatement(SQL_STRING);
                }
                statement->clearParameters();
                statement->addParameter(CreateNamedParameter(username, NString, username));
                if (date != NULL)
                    statement->addParameter(CreateNamedParameter(dueDate, NDate, date));
                if (active != NULL)
                    statement->addParameter(CreateNamedParameter(active, NBool, active));

                statement->executeQuery();

                return new NTypedResultSet<NSecGroupModel>(statement->getResultSet());
            }
        }
    }
}