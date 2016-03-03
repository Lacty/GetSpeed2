
#pragma once
#include <set>
#include "../Noncopyable/noncopyable.hpp"
#include "../Vector/vector.hpp"


class Mouse : public Noncopyable {
private:
  Vec2d _pos;

  std::set<int> _push;
  std::set<int> _pull;
  std::set<int> _press;

public:
  Mouse() :_pos(0, 0) {};

  void setButtonPush(int button) { _push.emplace(button); }
  void setButtonPull(int button) { _pull.emplace(button); }
  void setButtonPress(int button) { _press.emplace(button); }

  void popButtonPress(int button) { _press.erase(_press.find(button)); }

  bool isPush(int button) {
    if (_push.find(button) == _push.end()) return false;
    _push.erase(_push.find(button));
    return true;
  }

  bool isPull(int button) {
    if (_pull.find(button) == _pull.end()) return false;
    _pull.erase(_pull.find(button));
    return true;
  }

  bool isPress(int button) {
    if (_press.find(button) == _press.end()) return false;
    return true;
  }

  Vec2d pos() const {
    return _pos;
  }

  void setPos(const double x, const double y) {
    _pos.x = x;
    _pos.y = y;
  } 
};
