add_library(kutils_str STATIC src/str.c)
target_include_directories(kutils_str PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>
)
