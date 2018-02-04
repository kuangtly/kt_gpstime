cmake_minimum_required (VERSION 2.6)

project (kt_gpstime)
# The version number.
set (${PROJECT_NAME}_VERSION_MAJOR 1)
set (${PROJECT_NAME}_VERSION_MINOR 0)

# c++11
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

# add include
include_directories ("${PROJECT_SOURCE_DIR}/include")

# add library
add_library ( ktl ${PROJECT_SOURCE_DIR}/src/ktl_gpstime.cpp )
 
# add the executable
set (${PROJECT_NAME}_SRC ${PROJECT_NAME}.cpp )
add_executable (${PROJECT_NAME} ${${PROJECT_NAME}_SRC})

target_link_libraries( ${PROJECT_NAME} ktl )
