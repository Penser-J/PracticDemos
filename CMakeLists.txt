cmake_minimum_required(VERSION 3.10)
project(Features)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 设置调试信息
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
endif()
set(CMAKE_CXX_FLAGS_DEBUG "-g3 -O0")
set(CMAKE_C_FLAGS_DEBUG "-g3 -O0")

# 添加源文件
set(SOURCES
    src/main.cpp
)

# 包含目录
include_directories(include)

# 创建可执行文件
add_executable(Features ${SOURCES})

# 编译选项
if(MSVC)
    # Windows MSVC 编译选项
    target_compile_options(Features PRIVATE /W4)
else()
    # GCC/Clang 编译选项
    target_compile_options(Features PRIVATE -Wall -Wextra -Wpedantic)
endif()
