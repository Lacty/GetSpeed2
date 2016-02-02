
#pragma once
#include <memory>
#include "appNative.hpp"
#include "sceneBase.hpp"

#include "title.hpp"
#include "game.hpp"


template<class Scene>
std::shared_ptr<SceneBase> sceneCreate(AppNative* app)
{
  return std::make_shared<Scene>(app);
}
