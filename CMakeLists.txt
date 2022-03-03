cmake_minimum_required(VERSION 3.21)
project(aluscattering)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(match)
include_directories(setup)

find_package(AUSALIB REQUIRED)

add_executable(Analyzer Analyse.cpp)
target_link_libraries(Analyzer PRIVATE AUSA::AUSA)