cmake_minimum_required(VERSION 3.24)

project(SDKCPP VERSION 0.0.1 LANGUAGES CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/deps")

include(all)

add_library(sdk INTERFACE)
add_library(sdk::sdk ALIAS sdk)

target_compile_features(sdk INTERFACE cxx_std_23)

target_include_directories(sdk INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

target_link_libraries(sdk INTERFACE sdk_dependencies)

if(PROJECT_IS_TOP_LEVEL)
    add_subdirectory(examples)
endif()