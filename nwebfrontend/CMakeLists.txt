


add_executable(NWebFrontend NEntryPoint.cpp NWebFrontend.h NWebFrontendApplication.cpp NWebFrontendApplication.h NSession.cpp NSession.h)

target_link_libraries(NWebFrontend PUBLIC NBase NServiceClient NWeb ${LIBRARIES} ${WT_LIBRARIES})

add_custom_command(TARGET NWebFrontend POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy_directory "${PROJECT_SOURCE_DIR}/nwebfrontend/resources" "${PROJECT_SOURCE_DIR}/target/Debug/resources")