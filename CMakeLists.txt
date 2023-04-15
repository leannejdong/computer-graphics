cmake_minimum_required(VERSION 3.16)
project(opengl-exercise1)

set(CMAKE_CXX_STANDARD 20)

find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)
find_package(glfw3 REQUIRED)

# Add include directories
include_directories(${OPENGL_INCLUDE_DIRS} ${GLEW_INCLUDE_DIRS} ${GLFW_INCLUDE_DIRS})


add_executable(${PROJECT_NAME} 3dtheme.cpp)
target_link_libraries(${PROJECT_NAME} PRIVATE OpenGL::GL GLEW::GLEW glfw glut)
