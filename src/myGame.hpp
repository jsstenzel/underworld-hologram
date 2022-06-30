#pragma once
#include "core/include.hpp"

class myGame : virtual public CState {
public:
  myGame();
  void handleKeyword(std::string action);
};