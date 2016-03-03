
#pragma once
#include "../Noncopyable/noncopyable.hpp"
#include <set>


class Key : public Noncopyable {
private:
  std::set<int> _push;
  std::set<int> _pull;
  std::set<int> _press;

public:
  void setKeyPush(int key) { _push.emplace(key); }
  void setKeyPull(int key) { _pull.emplace(key); }
  void setKeyPress(int key) { _press.emplace(key); }

  void popKeyPress(int key) { _press.erase(_press.find(key)); }

  bool isPush(int key) {
    if (_push.find(key) == _push.end()) return false;
    _push.erase(_push.find(key));
    return true;
  }

  bool isPull(int key) {
    if (_pull.find(key) == _pull.end()) return false;
    _pull.erase(_pull.find(key));
    return true;
  }

  bool isPress(int key) {
    if (_press.find(key) == _press.end()) return false;
    return true;
  }
};
