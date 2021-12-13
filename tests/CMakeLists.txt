project(tests)

message("--------------${PROJECT_NAME}--------------")
include(${CMAKE_SOURCE_DIR}/cmake/googletest.cmake)
getgtestlib()

SUBDIRNAMELIST_MACRO(subdirnamelist ${CMAKE_CURRENT_SOURCE_DIR})
foreach(sub ${subdirnamelist})
    message("添加${sub}项目")
    add_subdirectory(${sub})
endforeach(sub ${subdirnamelist})


