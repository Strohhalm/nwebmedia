//
// Created by strohhalm on 12.07.15.
//

#include <nmodel/NTypedResultSet.h>
#include "NInfLocalisationModelAccess.h"

namespace nox
{
    namespace infra
    {
        namespace model
        {
            NInfLocalisationModelAccess::NInfLocalisationModelAccess() : INModelAccess(NCOMPONENT_SERVICE_INFRA, NXS(NOX_INF_LOCALISATION))
            {
            }

            NInfLocalisationModelAccess::~NInfLocalisationModelAccess()
            {
            }

            INTypedResultSet<NInfLocalisationModel> * NInfLocalisationModelAccess::read(const NString & name, const NString & locale)
            {
                INIT_SQL_SECTION

                INPreparedStatement * statement = getPreparedStatement("READ");

                if (statement->getStatement().length() <= 0)
                {
//@formatter:off
                    SELECT FI(NAME) COMMA
                           FI(LOCALE) COMMA
                           FI(TEXT)
                      FROM TA(NOX_INF_LOCALISATION)
                     WHERE FI(NAME) EQ PA(name)
                       AND FI(LOCALE) EQ PA(locale)
                     ORDER BY FI(NAME) ASC COMMA
                              FI(LOCALE) ASC
//@formatter:on
                    statement->setStatement(SQL_STRING);
                }
                statement->clearParameters();
                statement->addParameter(CreateNamedParameter(name, NString, name));
                statement->addParameter(CreateNamedParameter(locale, NString, locale));

                statement->prepare();
                if (statement->executeQuery())
                    return new NTypedResultSet<NInfLocalisationModel>(statement->getResultSet());
                return NULL;
            }

            INTypedResultSet<NInfLocalisationModel> * NInfLocalisationModelAccess::readAll(const NUnsignedLong from, const NUnsignedLong count)
            {
                INIT_SQL_SECTION

                INPreparedStatement * statement = getPreparedStatement("READ_ALL");

                if (statement->getStatement().length() <= 0)
                {
//@formatter:off
                    SELECT FI(NAME) COMMA
                           FI(LOCALE) COMMA
                           FI(TEXT)
                      FROM TA(NOX_INF_LOCALISATION)
                     ORDER BY FI(NAME) ASC COMMA
                              FI(LOCALE) ASC
                     LIMIT PA(limit) OFFSET PA(offset)
//@formatter:on
                    statement->setStatement(SQL_STRING);
                }

                statement->addParameter(CreateNamedParameter(offset, NUnsignedLong, from));
                statement->addParameter(CreateNamedParameter(limit, NUnsignedLong, count));

                statement->prepare();
                if (statement->executeQuery())
                    return new NTypedResultSet<NInfLocalisationModel>(statement->getResultSet());
                return NULL;
            }

            nint NInfLocalisationModelAccess::compareTo(const INObject * other) const
            {
                if (this == other)
                    return 0;
                try
                {
                    const NInfLocalisationModelAccess * obj = dynamic_cast<const NInfLocalisationModelAccess *>(other);

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