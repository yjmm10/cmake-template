cmake_minimum_required(VERSION 3.14)
project(demo01)

message("----------------${PROJECT_NAME}----------------")


aux_source_directory(. SRCS)



# glog调用方式奇特
# ref:
# set(CMAKE_PREFIX_PATH ${CMAKE_SOURCE_DIR}/3rdparty/target/glog)
# find_package(Glog)
# 或
find_package(Glog PATHS ${CMAKE_SOURCE_DIR}/3rdparty/target/glog)

add_executable(${PROJECT_NAME} ${SRCS})

if(Glog_FOUND)
    # 由于glog在连接时将头文件直接链接到了库里面，所以这里不用显示调用target_include_directories
    target_link_libraries(${PROJECT_NAME} glog::glog)
    
    # ref：https://qastack.cn/programming/10671916/how-to-copy-dll-files-into-the-same-folder-as-the-executable-using-cmake
    add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD        # Adds a post-build event to MyTest
    COMMAND ${CMAKE_COMMAND} -E copy_if_different  # which executes "cmake - E copy_if_different..."
        "${CMAKE_SOURCE_DIR}/3rdparty/target/glog/bin/glog.dll"      # <--this is in-file
        $<TARGET_FILE_DIR:${PROJECT_NAME}>)                 # <--this is out-file path
else(Glog_FOUND)
    message(FATAL_ERROR "GLOG library not found")
endif(Glog_FOUND)
