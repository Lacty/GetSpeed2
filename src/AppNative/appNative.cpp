
#include "appNative.hpp"
#include <iostream>


AppNative::AppNative(int width, int height, const char* title) :
window_size(width, height),
fade(Fade::Type::In)
{
  if(!glfwInit()) exit(1);

  window = glfwCreateWindow(width, height, title, nullptr, nullptr);
  if(!window) {
    glfwTerminate();
    exit(1);
  }

  // set pointer to glfw
  glfwSetWindowUserPointer(window, this);

  // make window
  glfwMakeContextCurrent(window);

  // set Viewport
  std::cout << "window size\n" << window_size << std::endl;
  glViewport(0, 0, window_size.x(), window_size.y());

  // set callback func
  glfwSetKeyCallback        (window, keyCallBack);
  glfwSetCursorPosCallback  (window, mousePositionCallBack);
  glfwSetMouseButtonCallback(window, mouseButtonCallBack);
  glfwSetWindowSizeCallback (window, windowSizeCallback);

  glfwSetScrollCallback     (window, (GLFWscrollfun)TwEventMouseWheelGLFW3);
  glfwSetCharCallback       (window, (GLFWcharfun)TwEventCharGLFW3);
  TwInit(TW_OPENGL, nullptr);
  TwWindowSize(window_size.x(), window_size.y());

  // init camera
  camera = Camera(vec3f(0, 0, 0), vec3f(0, 0, -1));
  camera.setWindowSize(window_size);
  camera.registerTw();
}

AppNative::~AppNative() {
  TwTerminate();
  glfwTerminate();
}

bool AppNative::isOpen() {
  return !glfwWindowShouldClose(window);
}

void AppNative::clearWindowBuff() {
  glClear(GL_COLOR_BUFFER_BIT);
  camera.update();
}

void AppNative::updateEvent() {
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  fade.draw(this);
  
  key_event.clear();
  mouse_event.clear();
  glfwSwapBuffers(window);
  glfwPollEvents();
}


void AppNative::setClearColor(const Color& color) {
  glClearColor(color.r, color.g, color.b, color.a);
}

const vec2i& AppNative::windowSize() const {
  return window_size;
}

const vec2f AppNative::windowSizef() const {
  return vec2f(window_size.x(), window_size.y());
}

const vec2i AppNative::windowHalf() const {
  return vec2i(window_size.x() * 0.5f, window_size.y() * 0.5f);
}

const vec2f AppNative::windowHalff() const {
  return vec2f(window_size.x() * 0.5f, window_size.y() * 0.5f);
}


bool AppNative::isPushKey(int key) { return key_event.isPush(key); }
bool AppNative::isPullKey(int key) { return key_event.isPull(key); }
bool AppNative::isPressKey(int key) { return key_event.isPress(key); }

bool AppNative::isPushButton(int button) { return mouse_event.isPush(button); }
bool AppNative::isPullButton(int button) { return mouse_event.isPull(button); }
bool AppNative::isPressButton(int button) { return mouse_event.isPress(button); }

const vec2d& AppNative::mousePos() { return mouse_event.getPos(window); }
void AppNative::setMousePos(const vec2d& pos) { glfwSetCursorPos(window, pos.x(), pos.y()); }


void AppNative::startFade(Fade::Type _type, float _speed) {
  fade = Fade(_type, _speed);
}

bool AppNative::isFinishFade() {
  return fade.isFinish();
}

// Camera
void AppNative::camRotate(const vec3f& dist) {
  camera.rotate(dist);
}

void AppNative::camTranslate(const vec3f& quant) {
  camera.translate(quant);
}


void AppNative::keyCallBack(GLFWwindow* window,
                            const int key, const int scancode,
                            const int action, const int mods)
{
  auto native = (AppNative*)glfwGetWindowUserPointer(window);

  if(action == GLFW_PRESS) {
    native->key_event.setKeyPush(key);
    native->key_event.setKeyPress(key);
  }
  if(action == GLFW_RELEASE) {
    native->key_event.setKeyPull(key);
    native->key_event.popKeyPress(key);
  }
  TwEventKeyGLFW3(window, key, scancode, action, mods);
}

void AppNative::mouseButtonCallBack(GLFWwindow* window,
                                    int button, int action, int mods)
{
  auto native = (AppNative*)glfwGetWindowUserPointer(window);

  if(action == GLFW_PRESS) {
    native->mouse_event.setButtonPush(button);
    native->mouse_event.setButtonPress(button);
  }
  if(action == GLFW_RELEASE) {
    native->mouse_event.setButtonPull(button);
    native->mouse_event.popButtonPress(button);
  }

  TwEventMouseButtonGLFW3(window, button, action, mods);
}

void AppNative::mousePositionCallBack(GLFWwindow* window,
                                      double xpos, double ypos)
{
  TwEventMousePosGLFW3(window, xpos, ypos);
}

void AppNative::windowSizeCallback(GLFWwindow* window, const int width, const int height) {
  auto native = (AppNative*)glfwGetWindowUserPointer(window);

  TwEventWindowSizeGLFW3(window, width, height);

  native->window_size = vec2i(width, height);
  native->camera.setWindowSize(vec2i(width, height));

  glViewport(0, 0, width, height);
  glLoadIdentity();
  glOrtho(-width * 0.5f, width * 0.5f,
          -height * 0.5f, height * 0.5f,
          0.0f, 1.0f);
}
