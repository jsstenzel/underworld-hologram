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
  CObjectList(std::vector<std::shared_ptr<CObject>> vec);

  void addObject(std::shared_ptr<CObject> object);
  bool removeObject(std::shared_ptr<CObject> object);
  CObjectList findobject(const SObjectDesc& desc);

  bool empty();
  size_t size();
  void clear();
  std::shared_ptr<CObject> at(const size_t& index);
  std::shared_ptr<CObject>& operator[](size_t index);

private:
  std::vector<std::shared_ptr<CObject>> m_objects;
};