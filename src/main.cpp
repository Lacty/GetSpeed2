
#include <iostream>
#include <GLFW/glfw3.h>


int main() {
  if(!glfwInit()) return 0;

  auto window = glfwCreateWindow(640, 480, "GetSpeed2", nullptr, nullptr);
  if(!window) {
    glfwTerminate();
    return 0;
  }

  glfwMakeContextCurrent(window);

  while(!glfwWindowShouldClose(window)) {
    glClearColor(0.4f, 0.4f, 0.4f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    glfwSwapBuffers(window);
    glfwPollEvents();
  }

  glfwTerminate();
  return 0;
}
