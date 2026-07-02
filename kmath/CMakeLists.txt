cmake_minimum_required(VERSION 3.19)
project(KMATH LANGUAGES C)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)

if(CMAKE_C_COMPILER_ID MATCHES "GNU|Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

set(KMATH_SOURCES
  src/vector.c
)


add_library(kmath STATIC ${KMATH_SOURCES})
target_include_directories(kmath PUBLIC include)
