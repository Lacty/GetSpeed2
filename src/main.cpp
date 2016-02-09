
#include <iostream>
#include <GLFW/glfw3.h>
#include <AntTweakBar.h>


int main() {
  if(!glfwInit()) return 0;

  auto window = glfwCreateWindow(640, 480, "GetSpeed2", nullptr, nullptr);
  if(!window) {
    glfwTerminate();
    return 0;
  }

  glfwMakeContextCurrent(window);

  TwInit(TW_OPENGL, NULL);
  TwWindowSize(640, 480);

  float angle = 0;
  TwBar* twb;
  twb = TwNewBar("Test");

  TwAddVarRW(twb, "angle", TW_TYPE_FLOAT, &angle, "");

  while(!glfwWindowShouldClose(window)) {
    glClearColor(0.4f, 0.4f, 0.4f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    TwDraw();

    glfwSwapBuffers(window);
    glfwPollEvents();
  }
  
  // hoge

  glfwTerminate();
  return 0;
}
