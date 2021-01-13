#include "GL/glew.h"
#include "GLFW/glfw3.h"
#include <iostream>

int main(void)
{
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    /* GLEW must be initialized after a valid OpenGL context is created */
    if (glewInit() != GLEW_OK)
        std::cout << "Error: Failed to initialize";

    std::cout << glGetString(GL_VERSION) << std::endl;

    /* Create a variable to hold x,y positions of triangle vertices */
    float positions [6]
    {
        -0.5f, -0.5f,
         0.0f,  0.5f,
         0.5f, -0.5f
    };

    /* Create a Vertex Buffer*/
    unsigned int buffer {}; /* Creates a memory location to hold the id of the buffer */
    glGenBuffers(1, &buffer); /* Function that creates 1 buffer and gives us back its id at the address of buffer */
    glBindBuffer(GL_ARRAY_BUFFER, buffer); /* Selects, or "binds," the buffer. The first argument is related to its
 * purpose, which in this case, is just an array of memory. */
    glBufferData(GL_ARRAY_BUFFER, 6 * sizeof(float), positions, GL_STATIC_DRAW); /* Passes type of buffer, size of buffer,
 * pointer to source of data, and hint a usage. */

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        /* Testing ability to draw a triangle using legacy OpenGL functions */
        /* glBegin(GL_TRIANGLES);
        glVertex2f(-0.5f, -0.5f);
        glVertex2f(0.0f, 0.5f);
        glVertex2f(0.5f, -0.5f);
        glEnd(); */

        /* Drawing triangle using modern OpenGL functions accessed through GLEW, using last buffer to be bound (see
         * glBindBuffer above).
         * First argument tells OpenGL we are drawing a triangle, second argument tells OpenGL to start at index 0 of
         * our position data, third argument tells OpenGL that there are 3 indices in data array. */
        glDrawArrays(GL_TRIANGLES, 0, 3);

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}