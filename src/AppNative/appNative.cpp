
#if !_DEBUG
  // デバッグ時のみコンソールを表示させる
  #pragma comment(linker, "/subsystem:\"windows\" /entry:\"mainCRTStartup\"")
#endif

#include "appNative.hpp"


AppNative::AppNative(const Vec2i& size,
                     const std::string& title) :
_window(size) {
  _gl_win = createWindow(size, title);
  glfwSetWindowUserPointer(_gl_win, this);
  setCallBackFunc();
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

void AppNative::mouseButtomCallback(GLFWwindow* window, int button, int action, int mods) {
  auto app = static_cast<AppNative*>(glfwGetWindowUserPointer(window));

  if (action == GLFW_PRESS) {
    app->_mouse.setButtonPush(button);
    app->_mouse.setButtonPress(button);
  }
  if (action == GLFW_RELEASE) {
    app->_mouse.setButtonPull(button);
    app->_mouse.popButtonPress(button);
  }
}

void AppNative::mousePosCallBack(GLFWwindow* window, double xpos, double ypos) {
  auto app = static_cast<AppNative*>(glfwGetWindowUserPointer(window));

  app->_mouse.setPos(xpos, ypos);
}

void AppNative::mouseWheelCallBack(GLFWwindow* window, double xoffset, double yoffset) {
  auto app = static_cast<AppNative*>(glfwGetWindowUserPointer(window));
}

void AppNative::keyCallBack(GLFWwindow* window, int key, int scancode, int action, int mods) {
  auto app = static_cast<AppNative*>(glfwGetWindowUserPointer(window));
  
  if (action == GLFW_PRESS) {
    app->_key.setKeyPush(key);
    app->_key.setKeyPress(key);
  }
  if (action == GLFW_RELEASE) {
    app->_key.setKeyPull(key);
    app->_key.popKeyPress(key);
  }
}
void AppNative::charCallBack(GLFWwindow* window, uint32_t codepoint) {
  auto app = static_cast<AppNative*>(glfwGetWindowUserPointer(window));
}

void AppNative::windowSizeCallBack(GLFWwindow* window, int width, int height) {
  auto app = static_cast<AppNative*>(glfwGetWindowUserPointer(window));
}

void AppNative::setCallBackFunc() {
  glfwSetMouseButtonCallback(_gl_win, mouseButtomCallback);
  glfwSetCursorPosCallback(_gl_win, mousePosCallBack);
  glfwSetScrollCallback(_gl_win, mouseWheelCallBack);
  glfwSetKeyCallback(_gl_win, keyCallBack);
  glfwSetCharCallback(_gl_win, charCallBack);
  glfwSetWindowSizeCallback(_gl_win, windowSizeCallBack);
}


bool AppNative::isOpen() {
  return !glfwWindowShouldClose(_gl_win);
}

void AppNative::begin() {
  glClear(GL_COLOR_BUFFER_BIT);
}

void AppNative::end() {
  glfwSwapBuffers(_gl_win);
  glfwPollEvents();
}

Vec2i AppNative::windowSize() const {
  return _window.size;
}

Vec2i AppNative::windowCenter() const {
  return _window.pos;
}

AppNative* AppNative::setClearColor(const ColorA& color) {
  glClearColor(color.r, color.g, color.b, color.a);
  return this;
}


bool AppNative::isPushKey(int key)  { return _key.isPush(key); }
bool AppNative::isPullKey(int key)  { return _key.isPull(key); }
bool AppNative::isPressKey(int key) { return _key.isPress(key); }

bool AppNative::isPushMouse(int buttom) { return _mouse.isPush(buttom); }
bool AppNative::isPullMouse(int buttom) { return _mouse.isPull(buttom); }
bool AppNative::isPressMouse(int buttom) { return _mouse.isPress(buttom); }

Vec2d AppNative::mousePos() const {
  return _mouse.pos();
}

void AppNative::setMousePos(const Vec2d& pos) {
  glfwSetCursorPos(_gl_win, pos.x, pos.y);
  _mouse.setPos(pos.x, pos.y);
}