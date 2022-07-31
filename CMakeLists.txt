# 规定需要的cmake最低版本是 3.1
cmake_minimum_required (VERSION 3.1)
SET(CMAKE_C_COMPILER /usr/local/bin/gcc)
SET(CMAKE_CXX_COMPILER /usr/local/bin/g++)
# 设置项目的 C++ 标准
set(CMAKE_CXX_STANDARD 17)

# 不要构建 mirai 自带的 examples
set(MIRAI_CPP_BUILD_EXAMPLES OFF CACHE BOOL "Build examples" FORCE)
# 添加子模块 mirai
add_subdirectory(mirai-cpp)
# 工程名称
project(robot_common)

# 要添加.cpp源文件，请修改这一行
# 例如：add_executable(${PROJECT_NAME} src/main.cpp src/a.cpp src/b.cpp)
add_executable(${PROJECT_NAME} src/main.cpp)
# 设置头文件目录
include_directories(include)
include_directories(mirai-cpp/include)
# 链接 mirai-cpp
target_link_libraries(${PROJECT_NAME} PRIVATE mirai-cpp)
# 使用 mirai-cpp 静态库
target_compile_definitions(${PROJECT_NAME} PRIVATE MIRAICPP_STATICLIB)

if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    # 链接 pthread
    target_link_libraries(${PROJECT_NAME} PRIVATE pthread)
    # 静态链接 libgcc 和 libstdc++
    target_link_libraries(${PROJECT_NAME} PRIVATE -static-libgcc -static-libstdc++)
endif()
# 向工程添加存放源文件的子目录 src
# 子文件夹可以有CMakeLists.txt
add_subdirectory(src)
