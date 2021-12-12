project(modules)

message("----------------${PROJECT_NAME}----------------")
# message("目录：${CMAKE_CURRENT_SOURCE_DIR}")
SUBDIRNAMELIST_MACRO(subdirnamelist ${CMAKE_CURRENT_SOURCE_DIR})
# message("获取到列表${subdirnamelist}")

foreach(sub ${subdirnamelist})
    message("添加${sub}目录")
    add_subdirectory(${sub})
endforeach(sub ${subdirnamelist})
