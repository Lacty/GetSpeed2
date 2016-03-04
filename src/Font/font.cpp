
#include "font.hpp"


Font::Font(const std::string& str) :
font(str.c_str()) {}


void Font::setSize(int _size) {
  font.FaceSize(_size);
}

void Font::draw(const std::string& str, const Vec2f& pos) {
  font.Render(str.c_str(), (int)str.size(), FTPoint(pos.x, pos.y));
}

void Font::drawCenter(const std::string& str, const Vec2f& pos) {
  float offset_x = (float)font.BBox(str.c_str(), (int)str.size()).Upper().X();
  font.Render(str.c_str(), (int)str.size(), FTPoint(pos.x - offset_x * 0.5f, pos.y));
}
