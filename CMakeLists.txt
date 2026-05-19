cmake_minimum_required(VERSION 3.24)

project(SDKCPP VERSION 0.0.1 LANGUAGES CXX)

include(deps/all.cmake)

add_library(sdk INTERFACE)
add_library(sdk::sdk ALIAS sdk)

target_compile_features(sdk INTERFACE cxx_std_23)

target_include_directories(sdk INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

target_link_libraries(sdk INTERFACE sdk_dependencies)