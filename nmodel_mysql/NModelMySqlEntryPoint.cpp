//
// Created by strohhalm on 10.07.15.
//

#include <nmodel/INConnection.h>
#include <nmodel_mysql/NMySqlConnection.h>

using namespace nox;
using namespace nox::model;
using namespace nox::model::mysql;

extern "C"
{
    INConnection * CreateConnection(const NString & host, const NUnsignedShort & port, const NString & username, const NString & password, const NString & database)
    {
        return new NMySqlConnection(host, port, username, password, database);
    }

    void DestroyConnection(INConnection * connection)
    {
        if (connection != NULL)
            delete connection;
    }
}