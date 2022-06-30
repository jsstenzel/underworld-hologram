#pragma once
/*
 Thin wrapper around a vector of object pointers that allows
 searching by object properties.
 */
#include "common.hpp"

class CObject;

class CObjectList {
public:
  CObjectList();
  CObjectList(const std::vector<std::shared_ptr<CObject>>& vec);

  void addObject(std::shared_ptr<CObject> object);
  bool removeObject(std::shared_ptr<CObject> object);
  CObjectList findObject(const std::string& name);

  bool empty();
  size_t size();
  void clear();
  std::shared_ptr<CObject> at(const size_t& index);
  std::shared_ptr<CObject>& operator[](size_t index);
  std::vector<std::shared_ptr<CObject>>::iterator begin();
  std::vector<std::shared_ptr<CObject>>::iterator end();
  std::vector<std::shared_ptr<CObject>>::reverse_iterator rbegin();
  std::vector<std::shared_ptr<CObject>>::reverse_iterator rend();

private:
  std::vector<std::shared_ptr<CObject>> m_objects;
};