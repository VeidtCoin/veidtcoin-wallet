cmake_minimum_required(VERSION 3.10)
project(veidtcoin-wallet)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(cli)
add_subdirectory(keys)
add_subdirectory(rpc)
add_subdirectory(util)

add_executable(veidtwallet cli/main.cpp)

target_include_directories(veidtwallet PRIVATE
    cli
    keys
    rpc
    util
)

target_link_libraries(veidtwallet
    walletcli
    walletkeys
    walletrpc
    walletutil
)
