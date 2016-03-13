
#pragma once
#include <memory>
#include "../AppNative/appNative.hpp"


class SceneBase {
protected:
  AppNative* app_;
  bool       is_finish_;

public:
  SceneBase(AppNative* app) :
    app_(app),
    is_finish_(false) {}
  virtual ~SceneBase() = default;

  virtual void update() = 0;
  virtual void draw() = 0;

  bool shouldClose() { return is_finish_; }
};