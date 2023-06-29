# 指定CMake编译最低要求版本
cmake_minimum_required(VERSION 3.14)
# 给项目命名
project(test_shudu)

# 收集c/c++文件并赋值给变量SRC_LIST_C
# ${CMAKE_CURRENT_SOURCE_DIR}代表CMakeLists.txt当前项目录
file(GLOB
    SRC_LIST_C
    ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp
)

# 指定.h头文件目录
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include/shudu.h
                    ${CMAKE_CURRENT_SOURCE_DIR}/gtest/include
)

# 指定.dll链接库文件目录
link_directories(${CMAKE_CURRENT_SOURCE_DIR}/gtest/lib)

# 将c文件生成可执行文件sample1.exe
add_executable(test_shudu ${SRC_LIST_C})

# 指定sample1 链接库libgtest.dll、libgtest_main.dll
target_link_libraries(test_shudu
                      libgtest
                      libgtest_main
)
