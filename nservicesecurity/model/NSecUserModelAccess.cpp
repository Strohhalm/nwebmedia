//
// Created by strohhalm on 30.05.15.
//

#include <nbase/NAssert.h>
#include <nmodel/NTypedResultSet.h>
#include "NSecUserModelAccess.h"

namespace nox
{
    namespace security
    {
        namespace model
        {
            NSecUserModelAccess::NSecUserModelAccess() : INModelAccess(NCOMPONENT_SERVICE_SECURITY, NXS(NOX_SEC_USER))
            {
            }

            NSecUserModelAccess::~NSecUserModelAccess()
            {
            }

            void NSecUserModelAccess::insert(const NSecUserModel & model)
            {
                NAssertNull(model.getId())
                NAssertNull(model.getValidFrom())
                NAssertNull(model.getUserName())
                NAssertNull(model.getPassword())
                NAssertNull(model.getFirstName())
                NAssertNull(model.getLastName())
                NAssertNull(model.getEMail())
                NAssertNull(model.getActive())

                INIT_SQL_SECTION

                INPreparedStatement * statement = getPreparedStatement("INSERT");

                if (statement->getStatement().length() <= 0)
                {
//@formatter:off
                    INSERT INTO TA(NOX_SEC_USER)
                            LEFT_BRACKET
                                FI(ID) COMMA
                                FI(VALID_FROM) COMMA
                                FI(VALID_TO) COMMA
                                FI(USER_NAME) COMMA
                                FI(PASSWORD) COMMA
                                FI(FIRST_NAME) COMMA
                                FI(LAST_NAME) COMMA
                                FI(EMAIL) COMMA
                                FI(ACTIVE)
                            RIGHT_BRACKET
                        VALUES
                            LEFT_BRACKET
                                PA(id) COMMA
                                PA(validFrom) COMMA
                                PA(validTo) COMMA
                                PA(username) COMMA
                                PA(password) COMMA
                                PA(firstName) COMMA
                                PA(lastName) COMMA
                                PA(email) COMMA
                                PA(active)
                            RIGHT_BRACKET
//@formatter:on
                    statement->setStatement(SQL_STRING);
                }

                statement->clearParameters();
                statement->addParameter(CreateNamedParameter(id, NInteger, model.getId()));
                statement->addParameter(CreateNamedParameter(validFrom, NDate, model.getValidFrom()));
                statement->addParameter(CreateNamedParameter(validTo, NDate, model.getValidTo()));
                statement->addParameter(CreateNamedParameter(username, NString, model.getUserName()));
                statement->addParameter(CreateNamedParameter(password, NString, model.getPassword()));
                statement->addParameter(CreateNamedParameter(firstName, NString, model.getFirstName()));
                statement->addParameter(CreateNamedParameter(lastName, NString, model.getLastName()));
                statement->addParameter(CreateNamedParameter(email, NString, model.getEMail()));
                statement->addParameter(CreateNamedParameter(active, NBool, model.getActive()));

                statement->prepare();
                if (statement->execute() <= 0)
                    throw NRuntimeException("Could not insert a entry");
            }

            void NSecUserModelAccess::update(const NSecUserModel & model)
            {
                NAssertNull(model.getId())
                NAssertNull(model.getValidFrom())
                NAssertNull(model.getUserName())
                NAssertNull(model.getPassword())
                NAssertNull(model.getFirstName())
                NAssertNull(model.getLastName())
                NAssertNull(model.getEMail())
                NAssertNull(model.getActive())

                INIT_SQL_SECTION

                INPreparedStatement * statement = getPreparedStatement("UPDATE");

                if (statement->getStatement().length() <= 0)
                {
//@formatter:off
                    UPDATE TA(NOX_SEC_USER) QU(U)
                       SET FI(U.VALID_FROM) EQ PA(validFrom) COMMA
                           FI(U.VALID_TO) EQ PA(validTo) COMMA
                           FI(U.USER_NAME) EQ PA(username) COMMA
                           FI(U.PASSWORD) EQ PA(password) COMMA
                           FI(U.FIRST_NAME) EQ PA(firstName) COMMA
                           FI(U.LAST_NAME) EQ PA(lastName) COMMA
                           FI(U.EMAIL) EQ PA(email) COMMA
                           FI(U.ACTIVE) EQ PA(active)
                     WHERE FI(U.ID) EQ PA(id)
//@formatter:on
                    statement->setStatement(SQL_STRING);
                }

                statement->clearParameters();
                statement->addParameter(CreateNamedParameter(id, NInteger, model.getId()));
                statement->addParameter(CreateNamedParameter(validFrom, NDate, model.getValidFrom()));
                statement->addParameter(CreateNamedParameter(validTo, NDate, model.getValidTo()));
                statement->addParameter(CreateNamedParameter(username, NString, model.getUserName()));
                statement->addParameter(CreateNamedParameter(password, NString, model.getPassword()));
                statement->addParameter(CreateNamedParameter(firstName, NString, model.getFirstName()));
                statement->addParameter(CreateNamedParameter(lastName, NString, model.getLastName()));
                statement->addParameter(CreateNamedParameter(email, NString, model.getEMail()));
                statement->addParameter(CreateNamedParameter(active, NBool, model.getActive()));

                statement->prepare();
                if (statement->execute() <= 0)
                    throw NRuntimeException("Could not update a entry");
            }

            INTypedResultSet<NSecUserModel> * NSecUserModelAccess::read(const NLong & userId)
            {
                INIT_SQL_SECTION

                INPreparedStatement * statement = getPreparedStatement("READ");

                if (statement->getStatement().length() <= 0)
                {
//@formatter:off
                    SELECT FI(U.ID) COMMA
                           FI(U.VALID_FROM) COMMA
                           FI(U.VALID_TO) COMMA
                           FI(U.USER_NAME) COMMA
                           FI(U.PASSWORD) COMMA
                           FI(U.FIRST_NAME) COMMA
                           FI(U.LAST_NAME) COMMA
                           FI(U.EMAIL) COMMA
                           FI(U.ACTIVE)
                      FROM TA(NOX_SEC_USER) QU(U)
                     WHERE FI(U.ID) EQ PA(userId)
//@formatter:on
                    statement->setStatement(SQL_STRING);
                }

                statement->clearParameters();
                statement->addParameter(CreateNamedParameter(id, NLong, userId));

                statement->prepare();
                statement->executeQuery();

                return new NTypedResultSet<NSecUserModel>(statement->getResultSet());
            }

            INTypedResultSet<NSecUserModel>* NSecUserModelAccess::readUserByName(const NString & username)
            {
                INIT_SQL_SECTION

                INPreparedStatement * statement = getPreparedStatement("READ_BY_USERNAME");

                if (statement->getStatement().length() <= 0)
                {
//@formatter:off
                    SELECT FI(ID) COMMA
                           FI(VALID_FROM) COMMA
                           FI(VALID_TO) COMMA
                           FI(USER_NAME) COMMA
                           FI(PASSWORD) COMMA
                           FI(FIRST_NAME) COMMA
                           FI(LAST_NAME) COMMA
                           FI(EMAIL) COMMA
                           FI(ACTIVE)
                      FROM TA(NOX_SEC_USER)
                     WHERE FI(USER_NAME) EQ PA(username)
//@formatter:on
                    statement->setStatement(SQL_STRING);
                }

                statement->clearParameters();
                statement->addParameter(CreateNamedParameter(username, NString, username));

                statement->prepare();
                statement->executeQuery();

                return new NTypedResultSet<NSecUserModel>(statement->getResultSet());
            }
            
            INTypedResultSet<NSecUserModel> * NSecUserModelAccess::readUserByName(const NString & username, const NBool & active)
            {
                INIT_SQL_SECTION

                INPreparedStatement * statement = getPreparedStatement("READ_BY_USERNAME_ACTIVE_DATE");

                if (statement->getStatement().length() <= 0)
                {
//@formatter:off
                    SELECT FI(U.ID) COMMA
                           FI(U.VALID_FROM) COMMA
                           FI(U.VALID_TO) COMMA
                           FI(U.USER_NAME) COMMA
                           FI(U.PASSWORD) COMMA
                           FI(U.FIRST_NAME) COMMA
                           FI(U.LAST_NAME) COMMA
                           FI(U.EMAIL) COMMA
                           FI(U.ACTIVE)
                      FROM TA(NOX_SEC_USER) QU(U)
                     WHERE FI(U.USER_NAME) EQ PA(username)
                       AND FI(U.ACTIVE) EQ PA(active)
//@formatter:on
                    statement->setStatement(SQL_STRING);
                }

                statement->clearParameters();
                statement->addParameter(CreateNamedParameter(username, NString, username));
                statement->addParameter(CreateNamedParameter(active, NBool, active));

                statement->prepare();
                statement->executeQuery();

                return new NTypedResultSet<NSecUserModel>(statement->getResultSet());
            }
            
            INTypedResultSet<NSecUserModel> * NSecUserModelAccess::readUserByName(const NString & username, const NDate & date)
            {
                INIT_SQL_SECTION

                INPreparedStatement * statement = getPreparedStatement("READ_BY_USERNAME_ACTIVE_DATE");

                if (statement->getStatement().length() <= 0)
                {
//@formatter:off
                    SELECT FI(U.ID) COMMA
                           FI(U.VALID_FROM) COMMA
                           FI(U.VALID_TO) COMMA
                           FI(U.USER_NAME) COMMA
                           FI(U.PASSWORD) COMMA
                           FI(U.FIRST_NAME) COMMA
                           FI(U.LAST_NAME) COMMA
                           FI(U.EMAIL) COMMA
                           FI(U.ACTIVE)
                      FROM TA(NOX_SEC_USER) QU(U)
                     WHERE FI(U.USER_NAME) EQ PA(username)
                       AND FI(U.VALID_FROM) LT_OR_EQ PA(date)
                       AND LEFT_BRACKET FI(U.VALID_TO) GT_OR_EQ PA(date) OR
                                        FI(U.VALID_TO) IS_NULL RIGHT_BRACKET
//@formatter:on
                    statement->setStatement(SQL_STRING);
                }

                statement->clearParameters();
                statement->addParameter(CreateNamedParameter(username, NString, username));
                statement->addParameter(CreateNamedParameter(date, NDate, date));

                statement->prepare();
                statement->executeQuery();

                return new NTypedResultSet<NSecUserModel>(statement->getResultSet());
            }

            INTypedResultSet<NSecUserModel> * NSecUserModelAccess::readUserByName(const NString & username, const NBool & active,
                                                                             const NDate & date)
            {
                INIT_SQL_SECTION

                INPreparedStatement * statement = getPreparedStatement("READ_BY_USERNAME_ACTIVE_DATE");

                if (statement->getStatement().length() <= 0)
                {
//@formatter:off
                    SELECT FI(U.ID) COMMA
                           FI(U.VALID_FROM) COMMA
                           FI(U.VALID_TO) COMMA
                           FI(U.USER_NAME) COMMA
                           FI(U.PASSWORD) COMMA
                           FI(U.FIRST_NAME) COMMA
                           FI(U.LAST_NAME) COMMA
                           FI(U.EMAIL) COMMA
                           FI(U.ACTIVE)
                      FROM TA(NOX_SEC_USER) QU(U)
                     WHERE FI(U.USER_NAME) EQ PA(username)
                       AND FI(U.VALID_FROM) LT_OR_EQ PA(date)
                       AND LEFT_BRACKET FI(U.VALID_TO) GT_OR_EQ PA(date) OR
                                        FI(U.VALID_TO) IS_NULL RIGHT_BRACKET
                       AND FI(U.ACTIVE) EQ PA(active)
//@formatter:on
                    statement->setStatement(SQL_STRING);
                }

                statement->clearParameters();
                statement->addParameter(CreateNamedParameter(username, NString, username));
                statement->addParameter(CreateNamedParameter(date, NDate, date));
                statement->addParameter(CreateNamedParameter(active, NBool, active));

                statement->prepare();
                statement->executeQuery();

                return new NTypedResultSet<NSecUserModel>(statement->getResultSet());
            }

            INTypedResultSet<NSecUserModel> * NSecUserModelAccess::readUserByGroupName(const NString & groupName, const NBool & active,
                                                                                  const NDate & date, nlong from , nlong count)
            {
                INIT_SQL_SECTION;

                NString statementName = "NSECUSER_READ_BY_GROUPNAME";

                INPreparedStatement * statement = getPreparedStatement(statementName);

                if (statement->getStatement().length() <= 0)
                {
//@formatter:off
                    SELECT FI(U.ID) COMMA
                           FI(U.VALID_FROM) COMMA
                           FI(U.VALID_TO) COMMA
                           FI(U.USER_NAME) COMMA
                           FI(U.PASSWORD) COMMA
                           FI(U.FIRST_NAME) COMMA
                           FI(U.LAST_NAME) COMMA
                           FI(U.EMAIL) COMMA
                           FI(U.ACTIVE)
                      FROM TA(NOX_SEC_USER) QU(U)
                     WHERE FI(U.ID) IN LEFT_BRACKET
                                SELECT FI(UG.USER_ID)
                                  FROM TA(NOX_SEC_USR_GRP) QU(UG)
                                 WHERE FI(UG.GROUP_ID) IN LEFT_BRACKET
                                            SELECT FI(G.ID)
                                              FROM TA(NOX_SEC_GROUP) QU(G)
                                             WHERE FI(G.GROUP_NAME) EQ PA(groupname)
                                               AND FI(G.ACTIVE) EQ PA(active)
                                               AND FI(G.VALID_FROM) LT_OR_EQ PA(date)
                                               AND LEFT_BRACKET FI(G.VALID_TO) GT_OR_EQ PA(date) OR
                                                                FI(G.VALID_TO) IS_NULL RIGHT_BRACKET
                                       RIGHT_BRACKET
                                   AND FI(UG.ACTIVE) EQ PA(active)
                                   AND FI(UG.VALID_FROM) LT_OR_EQ PA(date)
                                   AND LEFT_BRACKET FI(G.VALID_TO) GT_OR_EQ PA(date) OR
                                                    FI(G.VALID_TO) IS_NULL RIGHT_BRACKET
                           RIGHT_BRACKET
                       AND FI(U.ACTIVE) EQ PA(active)
                       AND FI(U.VALID_FROM) EQ PA(data)
                       AND LEFT_BRACKET FI(U.VALID_TO) GT_OR_EQ PA(date) OR
                                        FI(U.VALID_TO) IS_NULL RIGHT_BRACKET
                     ORDER BY FI(U.ID) ASC
                     LIMIT PA(limit) OFFSET PA(offset)
//@formatter:on
                    statement->setStatement(SQL_STRING);
                }

                statement->clearParameters();
                statement->addParameter(CreateNamedParameter(groupname, NString, groupName));
                statement->addParameter(CreateNamedParameter(date, NDate, date));
                statement->addParameter(CreateNamedParameter(active, NBool, active));
                statement->addParameter(CreateNamedParameter(offset, NLong, new NLong(from)));
                statement->addParameter(CreateNamedParameter(limit, NLong, new NLong(count)));

                statement->prepare();
                statement->executeQuery();

                return new NTypedResultSet<NSecUserModel>(statement->getResultSet());
            }

            nint NSecUserModelAccess::compareTo(const INObject * other) const
            {
                if (this == other)
                    return 0;
                if (this > other)
                    return 1;
                return -1;
            }
        }
    }
}
