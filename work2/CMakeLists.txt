cmake_minimum_required(VERSION 4.2)


# CMake 4.2.x の import std 用 experimental gate
# 必ず project() より前に置く
set(CMAKE_EXPERIMENTAL_CXX_IMPORT_STD
    "d0edc3af-4c50-42ea-a356-e2862fe7a444"
)

project(
    SimulatorTest
    VERSION 1.0
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
#set(CMAKE_CXX_EXTENSIONS OFF)

# import std を使用する
set(CMAKE_CXX_MODULE_STD ON)

# リンク時も libc++ を使用
#add_link_options(-stdlib=libc++)


add_executable(my_app)

# モジュールファイルと通常ソースファイルの登録
target_sources(my_app
    PRIVATE
        src/main.cpp
        src/modules/math/math_impl.cpp

    # モジュールインターフェースとして公開するファイルセット
    PRIVATE
    FILE_SET CXX_MODULES TYPE CXX_MODULES FILES
        src/modules/math/math.cppm
        src/modules/utils/utils.cppm
)

