#include "game.hpp"
#include "object.hpp"

CObject::CObject(std::string name) {
  m_desc.m_name = name;
}

CObject::CObject(std::string name, const std::vector<std::string>& adjectives) {
  m_desc.m_name = name;
  m_desc.m_adjectives = adjectives;
}

std::string CObject::getName() { return m_desc.m_name; }

const std::vector<std::string>& CObject::getAdjectives() { return m_desc.m_adjectives; }

void CObject::handleCommand(const SCommandDesc& command) { return; }