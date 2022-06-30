#include "room.hpp"
#include "object.hpp"

CRoom::CRoom(std::string name) :
  m_name(name) {}

std::string CRoom::getName() { return m_name; }

void CRoom::addObject(std::shared_ptr<CObject> object) { m_objects.addObject(object); }

bool CRoom::removeObject(std::shared_ptr<CObject> object) { return m_objects.removeObject(object); }

CObjectList CRoom::findObject(const SObjectDesc& desc) { return m_objects.findobject(desc); }