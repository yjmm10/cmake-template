

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

  
指定生成器以及位数,工具集
cmake .. -G "Visual Studio 16 2019" -A Win32 -T "v140"


## 引入外部源码项目
- git submodule 
  ref:https://zhuanlan.zhihu.com/p/102050750
  该方式是在编译之前引用库
  1. 在根目录下引入调用库
  ```
  git submodule add -b v1.x https://github.com/gabime/spdlog.git 3rdparty/spdlog
  ```
  2. 在项目中添加add_subdirectory
    - 在引用项目CMakeLists.txt中添加
      ```
      # 会在当前项目(demo03)生成过程中编译spdlog项目, 造成重复编译，推荐另一种方式
      add_subdirectory(${CMAKE_SOURCE_DIR}/3rdparty/spdlog spdlog)
      ```
    - 在被引用项目上级目录的CMakeLists.txt添加
      ```
      # 在被引用目录3rdparty添加子目录
      add_subdirectory(spdlog)

      # 在顶层CMakeLists.txt中添加3rdparty子目录
      add_subdirectory(3rdparty)
      ```
  3. 项目链接引用库
    ```
      # 在引用项目中链接库
      target_link_libraries(${PROJECT_NAME} PRIVATE spdlog::spdlog)
    ```

- fetchcontent
  1. 编写fentchcontent模块,并放置在顶层cmake文件夹中
    ```
    # ref: https://www.cnblogs.com/pandamohist/p/13699911.html
      function(getjsonlib) # 封装位函数
      include(fetchcontent)
      fetchcontent_declare(	json	#库名字
                  GIT_REPOSITORY https://github.com/nlohmann/json.git	# 仓库地址
                  GIT_TAG v3.10.4 # 库版本
                  SOURCE_DIR ${CMAKE_SOURCE_DIR}/3rdparty/json # 指定库下载地址
                  )

      fetchcontent_makeavailable(json)	
      endfunction(getjsonlib)
    ``` 
  2. 引用库
    在demo04的CMakeLists.txt中引用库
    ```
    include(${CMAKE_SOURCE_DIR}/cmake/json.cmake)
    getjsonlib() #调用封装的库
    ```
    或在顶层CMakeLists.txt中包含cmake文件，在demo04中引用库
    ```
    # 顶层CMakeLists.txt
    include(${CMAKE_SOURCE_DIR}/cmake/json.cmake)
    # demo04 CMakeLists.txt
    getjsonlib()
    ```
  3. 链接库
    在demo04的CMakeLists.txt中
    ```
    target_link_libraries(${PROJECT_NAME} PRIVATE nlohmann_json)
    ```
  
 1. 

  https://www.cnblogs.com/pandamohist/p/13699911.html