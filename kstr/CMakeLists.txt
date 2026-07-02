cmake_minimum_required(VERSION 3.19)
project(KSTR LANGUAGES C)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)

if(CMAKE_C_COMPILER_ID MATCHES "GNU|Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

set(KSTR_SOURCES
  src/str.c
)


add_library(kstr STATIC ${KSTR_SOURCES})
target_include_directories(kstr PUBLIC include)
