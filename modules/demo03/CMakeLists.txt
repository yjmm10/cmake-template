cmake_minimum_required(VERSION 3.14)
project(demo03)

message("----------------${PROJECT_NAME}----------------")
message("通过git submodule方式引入外部项目")

aux_source_directory(. SRCS)

# 会在该文件夹下编译spdlog，或
# 在顶层CMakeLists.txt中add_subdirectory(),项目中直接引用库，当前采用这种方式
# add_definitions(-std=c++11)
# add_subdirectory(${CMAKE_SOURCE_DIR}/3rdparty/spdlog spdlog)


add_executable(${PROJECT_NAME} ${SRCS})

target_link_libraries(${PROJECT_NAME} PRIVATE spdlog::spdlog)

# if(hello_cmake_FOUND)
#     target_include_directories(${PROJECT_NAME} PRIVATE ${hello_cmake_INCLUDE_DIR})
#     target_link_libraries(${PROJECT_NAME} ${hello_cmake_LIBRARY})


#     # ref：https://qastack.cn/programming/10671916/how-to-copy-dll-files-into-the-same-folder-as-the-executable-using-cmake
#     add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD        # Adds a post-build event to MyTest
#     COMMAND ${CMAKE_COMMAND} -E copy_if_different  # which executes "cmake - E copy_if_different..."
#         "${CMAKE_SOURCE_DIR}/3rdparty/target/hello_cmake/bin/hello_library.dll"      # <--this is in-file
#         $<TARGET_FILE_DIR:${PROJECT_NAME}>)                 # <--this is out-file path
# else(hello_cmake_FOUND)
#     message(FATAL_ERROR "cmake  library not found")
# endif(hello_cmake_FOUND)
