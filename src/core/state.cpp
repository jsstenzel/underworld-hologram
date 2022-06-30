#include "state.hpp"

CState::CState() {}

void CState::quitGame() { m_runGame = false; }

bool CState::isRunning() { return m_runGame; }

const std::string& CState::getHeader() { return m_header; }

void CState::setHeader(const std::string& header) { m_header = header; }