
#if !_DEBUG
  // デバッグ時のみコンソールを表示させる
  #pragma comment(linker, "/subsystem:\"windows\" /entry:\"mainCRTStartup\"")
#endif

#include "appNative.hpp"


AppNative::AppNative(const Vec2i& size,
                     const std::string& title) :
_window(size) {
  _gl_win = createWindow(size, title);
}


GLFWwindow* AppNative::createWindow(const Vec2i& size, const std::string& title) {
  if (!glfwInit()) assert(!"");

  auto window = glfwCreateWindow(size.x, size.y,
                                 title.c_str(), nullptr, nullptr);
  if (!window) {
    glfwTerminate();
    assert(!"create window");
  }

  glfwMakeContextCurrent(window);

  return window;
}

bool AppNative::isOpen() {
  return !glfwWindowShouldClose(_gl_win);
}

AppNative* AppNative::begin() {
  glClear(GL_COLOR_BUFFER_BIT);
  return this;
}

AppNative* AppNative::end() {
  glfwSwapBuffers(_gl_win);
  glfwPollEvents();
  return this;
}

AppNative* AppNative::setClearColor(const ColorA& color) {
  glClearColor(color.r, color.g, color.b, color.a);
  return this;
}