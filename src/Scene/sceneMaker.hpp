
#pragma once
#include <memory>
#include "../AppNative/appNative.hpp"
#include "../Scene/sceneBase.hpp"


template<class Scene>
std::shared_ptr<SceneBase> sceneCreate(AppNative* app)
{
  return std::make_shared<Scene>(app);
}