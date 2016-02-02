
#pragma once
#include <FTGL/ftgl.h>
#include "vector.hpp"


class Font {
private:
  FTPixmapFont font;

public:
  Font(const std::string& path);

  void setSize(int _size);
  void draw(const std::string& str, const vec2f& pos);
  void drawCenter(const std::string& str, const vec2f& pos);
};
