cmake_minimum_required(VERSION 3.17)
project(OpenGL_Practice2)

set(CMAKE_CXX_STANDARD 20)

set(GLFW_INCLUDE_DIRS ${PROJECT_SOURCE_DIR}/dependencies/glfw-3.3.2/include)
set(GLFW_LIBRARY ${PROJECT_SOURCE_DIR}/dependencies/glfw-3.3.2/lib/libglfw3.a)
set(GLFW_DEPENDENCIES GL dl X11 pthread)

set(GLEW_INCLUDE_DIRS ${PROJECT_SOURCE_DIR}/dependencies/glew-2.2.0/include)
set(GLEW_LIBRARY ${PROJECT_SOURCE_DIR}/dependencies/glew-2.2.0/lib/libGLEW.a)
set(GLEW_DEPENDENCIES )

add_executable(OpenGL_Practice2 src/main.cpp)

target_include_directories(${PROJECT_NAME} PRIVATE ${GLFW_INCLUDE_DIRS} ${GLEW_INCLUDE_DIRS})

#Added -DGLEW_NO_GLU=1 because GL/glu.h is only included for old codebases, new projects don't need it.
    #(see https://github.com/nigels-com/glew/issues/192)
#Added -DGLEW_STATIC because must be defined for all targets compiled as static library.
    #(see https://github.com/nigels-com/glew/issues/161)
target_compile_definitions(${PROJECT_NAME} PRIVATE -DGLEW_NO_GLU=1 -DGLEW_STATIC)

target_link_libraries(${PROJECT_NAME} PRIVATE ${GLFW_LIBRARY} ${GLFW_DEPENDENCIES} ${GLEW_LIBRARY} ${GLEW_DEPENDENCIES})