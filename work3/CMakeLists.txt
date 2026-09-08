cmake_minimum_required(VERSION 4.2)


# CMake 4.2.x の import std 用 experimental gate
# 必ず project() より前に置く
set(CMAKE_EXPERIMENTAL_CXX_IMPORT_STD
    "d0edc3af-4c50-42ea-a356-e2862fe7a444"
)

project(
    RECTANGLE 
    VERSION 1.0
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
#set(CMAKE_CXX_EXTENSIONS OFF)

# import std を使用する
set(CMAKE_CXX_MODULE_STD ON)

add_library(geometry)

# モジュールファイルと通常ソースファイルの登録
target_sources(geometry
    PRIVATE
        src/geometry/rectangle.cpp

    # モジュールインターフェースとして公開するファイルセット
    PUBLIC 
    FILE_SET CXX_MODULES TYPE CXX_MODULES FILES
        src/geometry/rectangle.cppm
)


add_executable(run examples/main.cpp)

#target_sources(run
#    PRIVATE
#      examples/main.cpp
#)

target_link_libraries(run
    PRIVATE
      geometry
)

include(CTest)

if(BUILD_TESTING)

    find_package(GTest REQUIRED)

    add_executable(geometry_tests
        tests/rectangle_test.cpp
    )

    target_link_libraries(geometry_tests
        PRIVATE
            geometry
            GTest::gtest_main
    )

    include(GoogleTest)

    gtest_discover_tests(geometry_tests)

endif()
