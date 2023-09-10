cmake_minimum_required(VERSION 3.20)

project(simpletd)

set(LIB_DIR ${CMAKE_SOURCE_DIR}/deps/lib)

set(SOURCES
  deps/src/glad/glad.c
  src/main.cpp
)

include_directories(deps/include)

add_executable(${PROJECT_NAME} ${SOURCES})

target_link_libraries(${PROJECT_NAME} ${LIB_DIR}/GLFW/glfw3.lib)