cmake_minimum_required(VERSION 3.20)

project(
    VehicleSimulator
    VERSION 1.0
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# ============================================================
# Simulator Core
# ============================================================

add_library(
    simulator_core
    STATIC

    src/simulator.cpp
)

target_include_directories(
    simulator_core
    PUBLIC

    ${PROJECT_SOURCE_DIR}/include
)

# ============================================================
# Vehicle models
# ============================================================

add_library(
    vehicle_models
    STATIC

    vehicles/car.cpp
    vehicles/simple_drone.cpp
)

target_include_directories(
    vehicle_models
    PUBLIC

    ${PROJECT_SOURCE_DIR}/include
    ${PROJECT_SOURCE_DIR}/vehicles
)

target_link_libraries(
    vehicle_models
    PUBLIC

    simulator_core
)

# ============================================================
# Application
# ============================================================

add_executable(
    vehicle_simulator

    app/main.cpp
)

target_include_directories(
    vehicle_simulator
    PRIVATE

    ${PROJECT_SOURCE_DIR}/include
    ${PROJECT_SOURCE_DIR}/vehicles
)

target_link_libraries(
    vehicle_simulator
    PRIVATE

    vehicle_models
    simulator_core
)
