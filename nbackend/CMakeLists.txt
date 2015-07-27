
add_executable(NBackend NEntryPoint.cpp NBackend.h NBackendApplication.cpp NBackendApplication.h)

target_link_libraries(NBackend PUBLIC NBase NModel NService NServiceSecurity ${LIBRARIES})

add_custom_command(TARGET NBackend POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy_directory "${PROJECT_SOURCE_DIR}/nbackend/resources" "${PROJECT_SOURCE_DIR}/target/Debug/resources")

