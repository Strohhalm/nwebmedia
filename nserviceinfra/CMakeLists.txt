
add_subdirectory(exchange)

add_library(NServiceInfra SHARED NServiceInfra.h model/NInfLocalisationModel.cpp model/NInfLocalisationModel.h model/NInfLocalisationModelAccess.cpp model/NInfLocalisationModelAccess.h
        NServiceLocalisation.cpp NServiceLocalisation.h NServiceInfraFactory.cpp NServiceInfraFactory.h NServiceInfraEntryPoint.cpp NServiceKeyProvider.cpp NServiceKeyProvider.h model/NInfKeysModel.cpp model/NInfKeysModel.h model/NInfKeysModelAccess.cpp model/NInfKeysModelAccess.h)

target_link_libraries(NServiceInfra PUBLIC NBase NService NServiceInfraExchange NModel ${LIBRARIES})