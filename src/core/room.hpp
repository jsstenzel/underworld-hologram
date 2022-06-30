#pragma once
/*
 Base class for game room. Contains a list of game objects.
 */
#include "common.hpp"
#include "objectList.hpp"

class CObject;

class CRoom : public std::enable_shared_from_this<CRoom> {
public:
  CRoom(std::string name);

  std::string getName();
  void addObject(std::shared_ptr<CObject> object);
  bool removeObject(std::shared_ptr<CObject> object);
  CObjectList findObject(const SObjectDesc& desc);

private:
  std::string m_name;
  CObjectList m_objects;
};