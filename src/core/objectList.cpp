#include "objectList.hpp"
#include "object.hpp"

CObjectList::CObjectList() {}

CObjectList::CObjectList(std::vector<std::shared_ptr<CObject>> vec) :
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

CObjectList CObjectList::findobject(const SObjectDesc& desc) {
  // Find all objects with matching name
  std::vector<std::shared_ptr<CObject>> objects;
  for(auto object : m_objects) {
    if (object->getName() == desc.m_name) {
      objects.push_back(object);
    }
  }

  // Filter list if theres more than one match
  if (objects.size() > 1) { 
    // Filter to matching adjectives
    for(auto matchAdjective : desc.m_adjectives) {
      std::vector<std::shared_ptr<CObject>> matchObjects;
      
      // Check each object to see if it has the adjective
      for(auto object : objects) {
        auto objAdjectives = object->getAdjectives();
        for(auto objAdjective : objAdjectives) {
          if (objAdjective == matchAdjective) {
            matchObjects.push_back(object);
            break;
          }
        }
      }

      // Only keep matched objects
      objects.swap(matchObjects);
      if (objects.empty()) { break; }
    }
  }
  
  return CObjectList(objects);
}

bool CObjectList::empty() { return m_objects.empty(); }

size_t CObjectList::size() { return m_objects.size(); }

void CObjectList::clear() { m_objects.clear(); }

std::shared_ptr<CObject> CObjectList::at(const size_t& index) { return m_objects.at(index); }

std::shared_ptr<CObject>& CObjectList::operator[](size_t index) { return m_objects[index]; }