# 在指定目录下寻找头文件和动态库文件的位置，可以指定多个目标路径
find_path(hello_cmake_INCLUDE_DIR Hello.h  ${CMAKE_SOURCE_DIR}/3rdparty/target/hello_cmake/include)
find_library(hello_cmake_LIBRARY NAMES hello_library.lib PATHS ${CMAKE_SOURCE_DIR}/3rdparty/target/hello_cmake/lib)

if (hello_cmake_INCLUDE_DIR AND hello_cmake_LIBRARY)
    set(hello_cmake_FOUND TRUE)
endif (hello_cmake_INCLUDE_DIR AND hello_cmake_LIBRARY)