cmake_minimum_required (VERSION 2.6)

project (kt_gpstime)
# The version number.
set (${PROJECT_NAME}_VERSION_MAJOR 1)
set (${PROJECT_NAME}_VERSION_MINOR 0)

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
# add include
include_directories("${PROJECT_SOURCE_DIR}/include")
 
# add the executable
add_executable (${PROJECT_NAME} ${PROJECT_NAME}.cpp ${PROJECT_SOURCE_DIR}/src/ktl_gpstime.cpp)
