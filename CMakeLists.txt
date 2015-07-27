cmake_minimum_required(VERSION 3.2)
project(nwebmedia)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -DBOOST_ASIO_ENABLE_HANDLER_TRACKING")

include_directories(BEFORE ./)

find_package(Boost 1.55.0 REQUIRED COMPONENTS filesystem system thread)
if (Boost_FOUND)
    message(STATUS "Found Boost")
    message(STATUS "${Boost_LIBRARY_DIRS}")
    message(STATUS "${Boost_LIBRARIES}")
endif()

set(LIBRARIES ${Boost_LIBRARIES} pugixml dl)
set(WT_LIBRARIES wt wthttp)

link_directories("/usr/local/lib64")
link_directories("${PROJECT_SOURCE_DIR}/target/Debug")

add_subdirectory(nbase)
add_subdirectory(nmodel)
add_subdirectory(nmodel_mysql)
add_subdirectory(nmodel_postgresql)
add_subdirectory(nservice)
add_subdirectory(nserviceinfra)
add_subdirectory(nservicesecurity)
add_subdirectory(nbackend)
add_subdirectory(nserviceclient)
add_subdirectory(nserviceclientinfra)
add_subdirectory(nserviceclientsecurity)
add_subdirectory(nweb)
add_subdirectory(nwebsecurity)
add_subdirectory(nwebmedia)
add_subdirectory(nwebfrontend)

