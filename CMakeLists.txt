cmake_minimum_required(VERSION 3.17)
project(OpenGL_Practice2)

set(CMAKE_CXX_STANDARD 20)

set(GLFW_INCLUDE_DIRS ${PROJECT_SOURCE_DIR}/dependencies/glfw-3.3.2/include)
set(GLFW_LIBRARY ${PROJECT_SOURCE_DIR}/dependencies/glfw-3.3.2/lib/libglfw3.a)
set(GLFW_DEPENDENCIES GL dl X11 pthread)

add_executable(OpenGL_Practice2 src/main.cpp)

target_include_directories(${PROJECT_NAME} PRIVATE ${GLFW_INCLUDE_DIRS})

target_link_libraries(${PROJECT_NAME} PRIVATE ${GLFW_LIBRARY} ${GLFW_DEPENDENCIES})