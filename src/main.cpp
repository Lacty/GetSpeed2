
#include <iostream>
#include <GLFW/glfw3.h>

#include "header/debugIO.hpp"


int main() {
  if (!glfwInit()) return -1;

  GLFWwindow* window = glfwCreateWindow(640, 480, "HELLO", nullptr, nullptr);
  if (!window) {
    glfwTerminate();
    return -1;
  }

  glfwMakeContextCurrent(window);

  while (!glfwWindowShouldClose(window)) {
    glClearColor(0.4f, 0.4f, 0.4f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    glfwSwapBuffers(window);
    glfwPollEvents();
  }

  glfwTerminate();
  return 0;
}
