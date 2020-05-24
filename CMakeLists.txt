cmake_minimum_required(VERSION 3.13)
project(main)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "-O0 -Wall")

FIND_PACKAGE( Boost REQUIRED )
INCLUDE_DIRECTORIES( ${Boost_INCLUDE_DIR} )

file(GLOB SOURCE_FILES main.cpp)
add_executable(main ${SOURCE_FILES})