
#pragma once
#include <GLFW/glfw3.h>
#include <iostream>

#include "../Vector/vector.hpp"
#include "../Color/color.hpp"
#include "../Key/key.hpp"
#include "../Mouse/mouse.hpp"
#include "../TwBar/twBar.hpp"
#include "../Camera/camera.hpp"
#include "../Font/font.hpp"
#include "../Timer/timer.hpp"
#include "../Utility/utility.hpp"
#include "../LoadPath/loadPath.hpp"
#include "../Fps/fps.hpp"
#include "../Fade/fade.hpp"


class AppNative {
private:
  GLFWwindow* window;
  vec2i window_size;
  vec2i defSize;
  
  Key   key_event;
  Mouse mouse_event;

  Camera camera;

  Fps fps;
  
  Fade fade;

public:
  AppNative(int width, int height, const char* title);
  ~AppNative();

  // this class can't copy
  AppNative() = delete;
  AppNative(const AppNative&) = delete;
  AppNative& operator =(const AppNative&) = delete;

  bool isOpen();
  void clearWindowBuff();
  void updateEvent();

  void setClearColor(const Color& color);

  const vec2i& windowSize()  const;
  const vec2f  windowSizef() const;
  const vec2i  windowHalf()  const;
  const vec2f  windowHalff() const;

  // Key Events
  bool isPushKey(int key);
  bool isPullKey(int key);
  bool isPressKey(int key);

  // Mouse Event
  bool isPushButton(int button);
  bool isPullButton(int button);
  bool isPressButton(int button);

  const vec2d& mousePos();
  void setMousePos(const vec2d& pos);

  void camRotate(const vec3f& dist);
  void camTranslate(const vec3f& quant);

  void setCamPos(const vec3f& _pos) { camera.setPos(_pos); }
  void setCamUp(const vec3f& _up)   { camera.setUp(_up); }
  void setCamTarget(const vec3f& _target) { camera.setTarget(_target); }
  void setCamFovy(float _fovy) { camera.setFovy(_fovy); }
  void setCamNear(float _near) { camera.setNear(_near); }
  void setCamFar(float _far) { camera.setFar(_far); }

  const vec3f& getCamPos()    const { return camera.getPos(); }
  const vec3f& getCamUp()     const { return camera.getUp(); }
  const vec3f& getCamTarget() const { return camera.getTarget(); }
  const vec3f& getCamRot()    const { return camera.getRot(); }

  float getCamFovy() const { return camera.getFovy(); }
  float getCamNear() const { return camera.getNear(); }
  float getCamFar() const { return camera.getFar(); }

  double getFps() { return fps.get(); }
  
  void startFade(Fade::Type type, float speed = 4.0f);
  bool isFinishFade();

  float getWindowScale();

private:
  static void keyCallBack(GLFWwindow* window,
                          const int key,    const int scancode,
                          const int action, const int mods);

  static void mouseButtonCallBack(GLFWwindow* window,
                                  int button, int action, int mods);

  static void mousePositionCallBack(GLFWwindow* window,
                                    double xpos, double ypos);

  static void windowSizeCallback(GLFWwindow* window, const int width, const int height);
};
