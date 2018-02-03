cmake_minimum_required (VERSION 2.6)

project (kt_gpstime)

# The version number.
set (Tutorial_VERSION_MAJOR 1)
set (Tutorial_VERSION_MINOR 0)

 
 
# add the binary tree to the search path for include files
# so that we will find TutorialConfig.h
include_directories("${PROJECT_SOURCE_DIR}/include")
 
# add the executable
add_executable (${PROJECT_NAME} ${PROJECT_NAME}.cpp ${PROJECT_SOURCE_DIR}/src/ktl_gpstime.cpp)
