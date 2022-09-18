#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <stdlib.h>
#include <stdio.h>

#pragma comment(lib,"opengl32")

int main()
{
    GLFWwindow* window;
    if (!glfwInit())
        exit(EXIT_FAILURE);
    window = glfwCreateWindow(500, 500, "3DProgramming", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }
    glfwMakeContextCurrent(window);

    while (!glfwWindowShouldClose(window))
    {
        float ratio;
        int width, height;
        glfwGetFramebufferSize(window, &width, &height);
        ratio = width / (float)height;

        glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        glColor3f(0.0f, 0.0f, 1.0f);

        float rad = 1;

        glBegin(GL_LINE_STRIP);
        for (int i = 0; i < 360; i++)
        {
            float angle, x, y;
            angle = i * 3.141592 / 180;
            x = rad * cos(angle);
            y = rad * sin(angle);
            glVertex2f(x, y);
        }
        glEnd();
        glFinish();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    glfwDestroyWindow(window);
    glfwTerminate();
    exit(EXIT_SUCCESS);
}