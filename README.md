

[find_package](https://cmake.org/cmake/help/latest/command/find_package.html?highlight=find_package)
- Module
    ```
    自己编写
    ```
- 
- Config

[message](https://cmake.org/cmake/help/latest/command/message.html?highlight=message)
- MODE
- STATUS 记录状态
  - STATUS
  - CHECK_START
  - CHECK_FAIL
  - CHECK_PASS 
  ```

  ```

库带有cmake
已编译库引用
1. 带有<LibName>Config.cmake 或Find<LibName>.cmake

# 设置搜索安装库路径,并查找库
set(CMAKE_MODULE_PATH <LibPath>)
find_package(GLog)
# 判断是否查找到
if(<LibName>_FOUND)
    message(STATUS  "GLOG library found!")
    # 链接头文件 
    # target_include_directories(${PROJECT_NAME} PRIVATE ${GLOG_INCLUDE_DIRS})
    target_link_libraries(${PROJECT_NAME} PRIVATE glog::glog)
else(GLOG_FOUND)
    message(FATAL_ERROR  "GLOG library not found!")
endif(GLOG_FOUND)

  

  fetch 
  https://www.cnblogs.com/pandamohist/p/13699911.html