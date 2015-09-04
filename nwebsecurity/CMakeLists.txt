


add_library(NWebSecurity SHARED NWebSecurity.h NSecViewLogin.cpp NSecViewLogin.h NViewSecurityFactory.cpp NViewSecurityFactory.h NWebSecurityEntryPoint.cpp NSecViewRegister.cpp NSecViewRegister.h NUserAdministrationView.cpp NUserAdministrationView.h components/NSecComponentUserInfo.cpp components/NSecComponentUserInfo.h)

target_link_libraries(NWebSecurity PUBLIC NBase NServiceClient NServiceClientSecurity NWeb ${LIBRARIES} ${WT_LIBRARIES})