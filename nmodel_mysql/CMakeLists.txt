


add_library(NModel_MySql SHARED NModelMySql.h NMySqlConnection.cpp NMySqlConnection.h NMySqlPreparedStatement.cpp NMySqlPreparedStatement.h NMySqlResultSet.cpp NMySqlResultSet.h NModelMySqlEntryPoint.cpp)

target_link_libraries(NModel_MySql PUBLIC NBase NModel ${LIBRARIES} mysqlcppconn)