cmake_minimum_required(VERSION 3.16)

set(CMAKE_CXX_STANDARD 11)

# 必须添加到project之前
# IF(CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
# SET(CMAKE_INSTALL_PREFIX ${CMAKE_BINARY_DIR}/install CACHE PATH "install path" FORCE)
# ENDIF(CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)

# 将可执行目录统一起来
# set (CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
# set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
project(cmake-template VERSION 1.0.0)
message("--------------主模块：cmake-template--------------")

# 预编译宏

# 预编译选项 抑制开发警告
# add_compile_definitions("-Wno-dev")


# 添加第三方库
add_subdirectory(3rdparty)
# 添加cmake
# set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake)

include(${CMAKE_SOURCE_DIR}/cmake/utils.cmake)
include(${CMAKE_SOURCE_DIR}/cmake/json.cmake)

# 添加模块
add_subdirectory(modules)

# 添加测试模块








# IF(CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
# SET(CMAKE_INSTALL_PREFIX ${CMAKE_BINARY_DIR}/install CACHE PATH "install path" FORCE)
# ENDIF(CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)

# message("hhhhhhhhhhhhhhhh${CMAKE_INSTALL_PREFIX}")


# include(FetchContent)
# FetchContent_Declare(
#     glog
#     GIT_REPOSITORY  https://github.com/google/glog.git
#     GIT_TAG         v0.5.0
#     GIT_SHALLOW     TRUE
#     SOURCE_DIR      ${CMAKE_SOURCE_DIR}/3rdparty/glog
# )
# FetchContent_MakeAvailable(glog)

# add_executable(cmake-template main.cpp)
# target_link_libraries(cmake-template PRIVATE glog)

