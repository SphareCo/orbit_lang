cmake_minimum_required(VERSION 3.10)
project(Orbit)
set(CMAKE_CXX_STANDARD 17)

file(GLOB SOURCES "src/*.cpp")
include_directories(include)

add_executable(orbit ${SOURCES})
 
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)
