cmake_minimum_required(VERSION 3.14)
project(3rdparty)

message("----------------${PROJECT_NAME}----------------")

if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
endif()
add_subdirectory(spdlog)