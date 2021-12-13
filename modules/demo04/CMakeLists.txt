cmake_minimum_required(VERSION 3.14)
project(demo04)

message("----------------${PROJECT_NAME}----------------")
message("通过fetchcontent方式引入外部项目")

aux_source_directory(. SRCS)

# include(${CMAKE_SOURCE_DIR}/cmake/json.cmake)
getjsonlib()

add_executable(${PROJECT_NAME} ${SRCS})


target_link_libraries(${PROJECT_NAME} PRIVATE nlohmann_json::nlohmann_json)


