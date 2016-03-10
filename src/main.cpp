
#include "AppNative/appNative.hpp"


int main() {
  AppNative app(Vec2i(600, 600), "Test");
  app.setClearColor(Color::gray());

  Vec3f pos;
  Vec3f target(0, 0, -1);

  TwBar* twBar = TwNewBar("Camera");
  TwAddVarRW(twBar, "pos", TW_TYPE_DIR3F, &pos.x, "");
  TwAddVarRW(twBar, "target", TW_TYPE_DIR3F, &target.x, "");

  while (app.isOpen()) {
    app.begin();
    
    app.updateCam()
      .setCamPos(pos)
      .setCamTarget(target);

    drawCircle(Vec3f::zero(), 20, 0.2f, 3, ColorA::blue());

    app.end();
  }
}
