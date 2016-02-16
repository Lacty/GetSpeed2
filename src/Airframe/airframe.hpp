
#pragma once
#include "../Vector/vector.hpp"
#include "../Mesh/mesh.hpp"
#include "../CatmullRom/catmullRom.hpp"


class Airframe {
public:
  enum class Type { Normal };
  enum class State { Ready, Active, Dead };
  enum { Left = -1, Right = 1 };

private:
  Type type;
  State state;
  
  Mesh<std::vector<float>> mesh;

  vec3f pos;
  vec3f center;
  vec3f up;
  vec3f side;
  vec3f forward;

  float speedRate;

  // this param should upper "4"
  int controlPointNum;

  CRSpline spline;
  
  // evaluate：求める
  // center nearOnLine nextOnLineを同時に求める
  void evControlPoint(const std::vector<float>& _vtx);
  void evForward();
  vec3f evNextOnLine(const int _index,
                     const float _percent,
                     const std::vector<float>& _vtx);

  std::vector<vec3f> nearOnLine;

  void drawUI();

public:
  Airframe();
  Airframe(Type _type, State _state);

  void accel();
  void handle(const float _rate);

  void update(const std::vector<float>& _vtx);
  void draw();

  const vec3f& getPos() const;
  const vec3f& getCenter() const;
  const vec3f& getSide() const;
  const vec3f& getForward() const;

  void setPos(const vec3f& _pos);
  void setCenter(const vec3f& _center);
  void setSide(const vec3f& _side);
  void setForward(const vec3f& _forward);
};
