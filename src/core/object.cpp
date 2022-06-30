#include "game.hpp"
#include "object.hpp"

CObject::CObject(std::string name) :
  m_name(name) {}

const std::string& CObject::getName() { return m_name; }