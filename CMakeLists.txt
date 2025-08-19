cmake_minimum_required(VERSION 3.10)

# Project
project(OpenGL LANGUAGES CXX)

# Set CXX Standard
set(CMAKE_CXX_STANDARD 17)

# GLOBAL VARIABLES
set(SOURCES
    src/Main.cpp
    src/App.cpp
    src/Shader.cpp
    src/Mesh.cpp
    src/Camera2D.cpp
    src/Camera3D.cpp
)
include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)



# Find Libraries
find_package(SDL REQUIRED)
find_package(GLEW REQUIRED)
find_package(spdlog REQUIRED)

# Add executable
add_executable(${PROJECT_NAME} ${SOURCES})
target_link_libraries(${PROJECT_NAME} SDL2 GLEW GL)