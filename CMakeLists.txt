cmake_minimum_required(VERSION 3.19)
project(KUTILS LANGUAGES C)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)

add_subdirectory(math)
add_subdirectory(str)

add_library(kutil INTERFACE)

target_link_libraries(kutil INTERFACE str math)
