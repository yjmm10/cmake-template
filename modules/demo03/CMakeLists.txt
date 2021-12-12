cmake_minimum_required(VERSION 3.14)
project(demo02)

message("----------------${PROJECT_NAME}----------------")


aux_source_directory(. SRCS)

# glog调用方式奇特
# ref:
# set(CMAKE_PREFIX_PATH ${CMAKE_SOURCE_DIR}/3rdparty/target/glog)
# find_package(Glog)
# 或
set(hello_cmake_DIR ${CMAKE_SOURCE_DIR}/cmake)
# include(${CMAKE_SOURCE_DIR}/cmake)
# list(APPEND )
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake;${CMAKE_MODULE_PATH}")
find_package(hello_cmake )
# find_package(hello_cmake)

add_executable(${PROJECT_NAME} ${SRCS})

if(hello_cmake_FOUND)
    target_include_directories(${PROJECT_NAME} PRIVATE ${hello_cmake_INCLUDE_DIR})
    target_link_libraries(${PROJECT_NAME} ${hello_cmake_LIBRARY})


    # ref：https://qastack.cn/programming/10671916/how-to-copy-dll-files-into-the-same-folder-as-the-executable-using-cmake
    add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD        # Adds a post-build event to MyTest
    COMMAND ${CMAKE_COMMAND} -E copy_if_different  # which executes "cmake - E copy_if_different..."
        "${CMAKE_SOURCE_DIR}/3rdparty/target/hello_cmake/bin/hello_library.dll"      # <--this is in-file
        $<TARGET_FILE_DIR:${PROJECT_NAME}>)                 # <--this is out-file path
else(hello_cmake_FOUND)
    message(FATAL_ERROR "cmake  library not found")
endif(hello_cmake_FOUND)
