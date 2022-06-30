#include "objectList.hpp"
#include "object.hpp"

CObjectList::CObjectList() {}

CObjectList::CObjectList(const std::vector<std::shared_ptr<CObject>>& vec) :
  m_objects(vec) {}

void CObjectList::addObject(std::shared_ptr<CObject> object) { 
  m_objects.push_back(object); 
}

bool CObjectList::removeObject(std::shared_ptr<CObject> object) {
  for(auto it = m_objects.begin(); it != m_objects.end(); ++it) {
    if ((*it) == object) {
      m_objects.erase(it);
      return true;
    }
  }
  return false;
}

CObjectList CObjectList::findObject(const std::string& name) {
  // Find all objects with matching name
  std::vector<std::shared_ptr<CObject>> objects;
  for(auto object : m_objects) {
    if (object->getName() == name) {
      objects.push_back(object);
    }
  }
  
  return CObjectList(objects);
}

bool CObjectList::empty() { return m_objects.empty(); }

size_t CObjectList::size() { return m_objects.size(); }

void CObjectList::clear() { m_objects.clear(); }

std::shared_ptr<CObject> CObjectList::at(const size_t& index) { return m_objects.at(index); }

std::shared_ptr<CObject>& CObjectList::operator[](size_t index) { return m_objects[index]; }

std::vector<std::shared_ptr<CObject>>::iterator CObjectList::begin() { return m_objects.begin(); }

std::vector<std::shared_ptr<CObject>>::iterator CObjectList::end() { return m_objects.end(); }

std::vector<std::shared_ptr<CObject>>::reverse_iterator CObjectList::rbegin() { return m_objects.rbegin(); }

std::vector<std::shared_ptr<CObject>>::reverse_iterator CObjectList::rend() { return m_objects.rend(); }