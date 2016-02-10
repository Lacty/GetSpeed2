
#pragma once
#include <memory>
#include "../AppNative/appNative.hpp"
#include "../Scene/sceneBase.hpp"

#include "../Scene/Title/title.hpp"
#include "../Scene/Game/game.hpp"


template<class Scene>
std::shared_ptr<SceneBase> sceneCreate(AppNative* app)
{
  return std::make_shared<Scene>(app);
}
