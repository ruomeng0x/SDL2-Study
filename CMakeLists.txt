cmake_minimum_required(VERSION 3.22)

set(CMAKE_TOOLCHAIN_FILE "$ENV{VCPKG_CMAKE_PATH}"
        CACHE STRING "Vcpkg toolchain file")
project(SDL2_Study)

set(CMAKE_CXX_STANDARD 17)

if(MSVC)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /Zc:__cplusplus /utf-8")
endif(MSVC)

find_package(SDL2 CONFIG REQUIRED)
find_package(sdl2-image CONFIG REQUIRED)

add_subdirectory(01_HelloWorld)
add_subdirectory(02_LoadImage)