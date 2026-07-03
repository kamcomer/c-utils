cmake_minimum_required(VERSION 3.19)
project(kutils LANGUAGES C)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)

add_subdirectory(math)
add_subdirectory(str)

add_library(kutils INTERFACE)
add_library(kutils::kutils ALIAS kutils)

target_link_libraries(kutils INTERFACE kutils_str kutils_math)
