
#if !_DEBUG
  // デバッグ時のみコンソールを表示させる
  #pragma comment(linker, "/subsystem:\"windows\" /entry:\"mainCRTStartup\"")
#endif

#include "appNative.hpp"


AppNative::AppNative(const Vec2i& size,
                     const std::string& title) :
window_(size),
tweakBar_(size) {
  gl_win_ = createWindow(size, title);
  glfwSetWindowUserPointer(gl_win_, this);
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
    app->mouse_.setButtonPush(button);
    app->mouse_.setButtonPress(button);
  }
  if (action == GLFW_RELEASE) {
    app->mouse_.setButtonPull(button);
    app->mouse_.popButtonPress(button);
  }

  TweakBar::mouseButtonCallBack(window, button, action, mods);
}

void AppNative::mousePosCallBack(GLFWwindow* window, double xpos, double ypos) {
  auto app = static_cast<AppNative*>(glfwGetWindowUserPointer(window));

  app->mouse_.setPos(xpos, ypos);

  TweakBar::mousePosCallBack(window, xpos, ypos);
}

void AppNative::mouseWheelCallBack(GLFWwindow* window, double xoffset, double yoffset) {
  auto app = static_cast<AppNative*>(glfwGetWindowUserPointer(window));

  TweakBar::mouseWheelCallBack(window, xoffset, yoffset);
}

void AppNative::keyCallBack(GLFWwindow* window, int key, int scancode, int action, int mods) {
  auto app = static_cast<AppNative*>(glfwGetWindowUserPointer(window));
  
  if (action == GLFW_PRESS) {
    app->key_.setKeyPush(key);
    app->key_.setKeyPress(key);
  }
  if (action == GLFW_RELEASE) {
    app->key_.setKeyPull(key);
    app->key_.popKeyPress(key);
  }

  TweakBar::keyCallBack(window, key, scancode, action, mods);
}
void AppNative::charCallBack(GLFWwindow* window, uint32_t codepoint) {
  auto app = static_cast<AppNative*>(glfwGetWindowUserPointer(window));

  TweakBar::charCallBack(window, codepoint);
}

void AppNative::windowSizeCallBack(GLFWwindow* window, int width, int height) {
  auto app = static_cast<AppNative*>(glfwGetWindowUserPointer(window));

  TweakBar::windowSizeCallBack(window, width, height);
}

void AppNative::setCallBackFunc() {
  glfwSetMouseButtonCallback(gl_win_, mouseButtomCallback);
  glfwSetCursorPosCallback(gl_win_, mousePosCallBack);
  glfwSetScrollCallback(gl_win_, mouseWheelCallBack);
  glfwSetKeyCallback(gl_win_, keyCallBack);
  glfwSetCharCallback(gl_win_, charCallBack);
  glfwSetWindowSizeCallback(gl_win_, windowSizeCallBack);
}


bool AppNative::isOpen() {
  return !glfwWindowShouldClose(gl_win_);
}

void AppNative::begin() {
  glClear(GL_COLOR_BUFFER_BIT);
}

void AppNative::end() {
  tweakBar_.draw();
  glfwSwapBuffers(gl_win_);
  glfwPollEvents();
}

Vec2i AppNative::windowSize() const {
  return window_.size_;
}

Vec2i AppNative::windowCenter() const {
  return window_.pos_;
}

AppNative* AppNative::setClearColor(const ColorA& color) {
  glClearColor(color.r, color.g, color.b, color.a);
  return this;
}


bool AppNative::isPushKey(int key)  { return key_.isPush(key); }
bool AppNative::isPullKey(int key)  { return key_.isPull(key); }
bool AppNative::isPressKey(int key) { return key_.isPress(key); }

bool AppNative::isPushMouse(int buttom) { return mouse_.isPush(buttom); }
bool AppNative::isPullMouse(int buttom) { return mouse_.isPull(buttom); }
bool AppNative::isPressMouse(int buttom) { return mouse_.isPress(buttom); }

Vec2d AppNative::mousePos() const {
  return mouse_.pos();
}

void AppNative::setMousePos(const Vec2d& pos) {
  glfwSetCursorPos(gl_win_, pos.x, pos.y);
  mouse_.setPos(pos.x, pos.y);
}