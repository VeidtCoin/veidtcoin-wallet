cmake_minimum_required(VERSION 3.13)
project(VeidtWallet)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5 REQUIRED COMPONENTS Widgets)

include_directories(${PROJECT_SOURCE_DIR}/src)

file(GLOB SOURCES
    src/*.cpp
    src/gui/*.cpp
)

add_executable(veidt-wallet ${SOURCES})

target_link_libraries(veidt-wallet Qt5::Widgets)
