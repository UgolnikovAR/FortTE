cmake_minimum_required(VERSION 3.0)

project(FortPROG)

#set (FortPROG_VERSION_MAJOR 0)
#set (FortPROG_VERSION_MINOR 2)

#set (FortPROG_VERSION "${FortPROG_VERSION_MAJOR}.${FortPROG_VERSION_MINOR}")


set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y -Wall")


set(CMAKE_CXX_STANDARD 14)

file(GLOB
          CPP_SOURCES "src/*.cpp")

include_directories("${PROJECT_SOURCE_DIR}/include")
include_directories("${PROJECT_SOURCE_DIR}/src")

add_executable(FortPROG main.cpp)
