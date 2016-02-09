
#include <iostream>
#include <GLFW/glfw3.h>

#include "TwBar/twBar.hpp"


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

  glfwSetMouseButtonCallback(window, TwEventMouseButtonGLFW3);
  glfwSetCursorPosCallback(window, TwEventMousePosGLFW3);
  glfwSetScrollCallback(window, TwEventMouseWheelGLFW3);
  glfwSetKeyCallback(window, TwEventKeyGLFW3);
  glfwSetCharCallback(window, (GLFWcharfun)TwEventCharGLFW3);
  glfwSetWindowSizeCallback(window, TwEventWindowSizeGLFW3);


  float angle = 0;
  TwBar* twb;
  twb = TwNewBar("Test");

  TwAddVarRW(twb, "angle", TW_TYPE_FLOAT, &angle, "");

  while(!glfwWindowShouldClose(window)) {
    glClearColor(0.4f, 0.4f, 0.4f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    GLfloat pos[] = {
      0.0f, 0.433f,
      -0.5f, -0.433f,
      0.5f, -0.433f
    };

    glVertexPointer(2, GL_FLOAT, 0, pos);

    glPushMatrix();
    glRotatef(angle, 0, 0, 1);
    glEnableClientState(GL_VERTEX_ARRAY);
    glDrawArrays(GL_TRIANGLES, 0, 3);
    glDisableClientState(GL_VERTEX_ARRAY);
    glPopMatrix();

    TwDraw();

    glfwSwapBuffers(window);
    glfwPollEvents();
  }
  
  // hoge

  glfwTerminate();
  return 0;
}
