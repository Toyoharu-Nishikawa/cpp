cmake_minimum_required(VERSION 4.2)


# CMake 4.2.x の import std 用 experimental gate
# 必ず project() より前に置く
set(CMAKE_EXPERIMENTAL_CXX_IMPORT_STD
    "d0edc3af-4c50-42ea-a356-e2862fe7a444"
)

project(
    SM 
    VERSION 1.0
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
#set(CMAKE_CXX_EXTENSIONS OFF)

# import std を使用する
set(CMAKE_CXX_MODULE_STD ON)

add_library(simulator)

# モジュールファイルと通常ソースファイルの登録
file(GLOB_RECURSE SIMULATOR_SOURCES "src/*.cpp")

target_include_directories(simulator
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src
)

target_sources(simulator
    PRIVATE
       ${SIMULATOR_SOURCES} 
)


add_executable(run examples/main2.cpp)

#target_sources(run
#    PRIVATE
#      examples/main.cpp
#)

target_link_libraries(run
    PRIVATE
      simulator
)

#include(CTest)
#
#if(BUILD_TESTING)
#
#    find_package(GTest REQUIRED)
#
#    add_executable(geometry_tests
#        tests/rectangle_test.cpp
#    )
#
#    target_link_libraries(geometry_tests
#        PRIVATE
#            simulator
#            GTest::gtest_main
#    )
#
#    include(GoogleTest)
#
#    gtest_discover_tests(geometry_tests)
#
#endif()
