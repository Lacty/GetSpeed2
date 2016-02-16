
#pragma once
#include "../Vector/vector.hpp"
#include "../Mesh/mesh.hpp"


class Stage {
private:
  Mesh<std::deque<float>> mesh;
  std::vector<float> vtx;
  std::vector<float> col;
  
  enum class Type {
    Straight,
    Right,
    Left,
    Down,
    Up
  } type;

  // 通り過ぎた部分を消す
  void killPolyPassed(const int _index);

  void decideType();
  void createStage();

  // TIPS: このパラメータは偶数でなければならない
  int shouldCreateCount;
  int createCount;

  vec3f pos;
  vec3f forward;
  vec3f side;
  vec3f rotate;

  void updateData();

public:
  Stage();

  void update(const int _index);
  void draw();

  const std::vector<float>& getVtx() const;
  const std::vector<float>& getCol() const;
};