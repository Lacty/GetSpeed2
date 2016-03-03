
#pragma once
#include "../Noncopyable/noncopyable.hpp"
#include <set>


class Key : Noncopyable {
private:
  std::set<int> push;
  std::set<int> pull;
  std::set<int> press;

public:
  void clear() {
    push.clear();
    pull.clear();
  }

  void setKeyPush(int key) { push.emplace(key); }
  void setKeyPull(int key) { pull.emplace(key); }
  void setKeyPress(int key) { press.emplace(key); }

  void popKeyPress(int key) { press.erase(press.find(key)); }

  bool isPush(int key) {
    if (push.find(key) == push.end()) return false;
    push.erase(push.find(key));
    return true;
  }

  bool isPull(int key) {
    if (pull.find(key) == pull.end()) return false;
    pull.erase(pull.find(key));
    return true;
  }

  bool isPress(int key) {
    if (press.find(key) == press.end()) return false;
    return true;
  }
};
