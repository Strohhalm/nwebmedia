
add_subdirectory(exchange)

add_library(NServiceSecurity SHARED NServiceSecurity.h model/NSecUserModel.cpp model/NSecUserModel.h model/NSecUserModelAccess.cpp model/NSecUserModelAccess.h model/NSecGroupModel.cpp model/NSecGroupModel.h model/NSecUserGroupModel.cpp model/NSecUserGroupModel.h model/NSecGroupModelAccess.cpp model/NSecGroupModelAccess.h model/NSecUserGroupModelAccess.cpp model/NSecUserGroupModelAccess.h NServiceUser.cpp NServiceUser.h NServiceSecurityFactory.cpp NServiceSecurityFactory.h NServiceSecurityEntryPoint.cpp)

target_link_libraries(NServiceSecurity PUBLIC NBase NService NServiceSecurityExchange NServiceClient ${LIBRARIES})