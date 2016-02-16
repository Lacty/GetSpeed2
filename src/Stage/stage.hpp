
#pragma once
#include "../Vector/vector.hpp"
#include "../Mesh/mesh.hpp"


class Stage {
private:
  Mesh<std::deque<float>> mesh;
  std::vector<float> vtx;
  std::vector<float> col;
  
  float width;
  float depth;

  enum class Type {
    Straight,
    Right,
    Left,
    Down,
    Up
  } type;

  // �ʂ�߂�������������
  void killPolyPassed(const int _index);

  void decideType();
  void createStage();

  // TIPS: ���̃p�����[�^�͋����łȂ���΂Ȃ�Ȃ�
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