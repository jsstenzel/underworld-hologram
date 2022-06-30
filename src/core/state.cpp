#include "state.hpp"

CState::CState(std::string header) :
  m_header(header) {}

void CState::quitGame() { m_runGame = false; }

bool CState::isRunning() { return m_runGame; }

std::string CState::getHeader() { return m_header; }