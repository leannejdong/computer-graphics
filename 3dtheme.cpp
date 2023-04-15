#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <GL/freeglut.h>

using namespace std;

constexpr int WIDTH = 800;
constexpr int HEIGHT = 600;

int main(int argc, char** argv) {
    glutInit(&argc, argv);

    // Initialize GLFW
    if (!glfwInit()) {
        cout << "Failed to initialize GLFW" << endl;
        return -1;
    }

    // Create a window
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "Exercise 1", nullptr, nullptr);
    if (!window) {
        cout << "Failed to create GLFW window" << endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);

    // Initialize GLEW
    glewExperimental = GL_TRUE;
    if (glewInit() != GLEW_OK) {
        cout << "Failed to initialize GLEW" << endl;
        glfwTerminate();
        return -1;
    }

    // Set up viewport
    glViewport(0, 0, WIDTH, HEIGHT);

    // Clear color
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);

    // Main loop
    while (!glfwWindowShouldClose(window)) {
        // Clear screen
        glClear(GL_COLOR_BUFFER_BIT);

        // Add text
        glColor3f(1.0f, 1.0f, 1.0f);
        glRasterPos2i(200, 200);
        const char* text = "Hello, OpenGL!";
        glutBitmapString(GLUT_BITMAP_9_BY_15, (const unsigned char*)text);

        // Swap buffers
        glfwSwapBuffers(window);

        // Poll events
        glfwPollEvents();
    }

    // Clean up
    glfwTerminate();
    return 0;
}
