add_library(kutils_math STATIC src/vector.c)
target_include_directories(kutils_math PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>
)
