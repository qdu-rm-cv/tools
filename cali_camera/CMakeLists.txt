cmake_minimum_required(VERSION 3.0.0)
project(cali_camera
    DESCRIPTION "cali_camera"
    VERSION 0.1.0
    LANGUAGES CXX
)
#---------------------------------------------------------------------------------------
# Compiler Options
#---------------------------------------------------------------------------------------

message(STATUS "-------------------------- Compiler ------------------------------")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_FLAGS "-Wall -Wextra")
set(CMAKE_CXX_FLAGS_DEBUG "-O0 -g")
set(CMAKE_CXX_FLAGS_RELEASE "-Ofast")

find_package(OpenCV REQUIRED)
find_package(spdlog REQUIRED)
find_package(Threads REQUIRED)

# src
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/src)

