#include "room.hpp"
#include "object.hpp"

CRoom::CRoom(std::string name, std::string description) :
  m_name(name), m_description(description) {}

const std::string& CRoom::getName() { return m_name; }

const std::string& CRoom::getDescription() { return m_description; }

void CRoom::addObject(std::shared_ptr<CObject> object) { m_allObjects.addObject(object); }

bool CRoom::removeObject(std::shared_ptr<CObject> object) { return m_allObjects.removeObject(object); }

CObjectList CRoom::findObject(const std::string& name) { return m_allObjects.findObject(name); }

const CObjectList& CRoom::getAllObjects() { return m_allObjects; }