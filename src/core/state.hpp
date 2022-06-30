#pragma once
/*
 Base class for custom game state. Container for global objects and keyword handling.
 */
#include "common.hpp"
#include "objectList.hpp"

class CState : std::enable_shared_from_this<CState> {
public:
  CState(std::string header);

  virtual void handleKeyword(std::string action) {}

  void quitGame();
  bool isRunning();
  std::string getHeader();
private:
  std::string m_header = "";
  bool m_runGame = true;
};