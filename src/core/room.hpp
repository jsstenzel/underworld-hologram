#pragma once
/*
 Base class for game room. Contains a list of game objects.
 */
#include "common.hpp"
#include "objectList.hpp"

class CObject;

class CRoom : public std::enable_shared_from_this<CRoom> {
public:
  CRoom(std::string name, std::string description = "");

  const std::string& getName();
  const std::string& getDescription();
  void addObject(std::shared_ptr<CObject> object);
  bool removeObject(std::shared_ptr<CObject> object);
  CObjectList findObject(const std::string& name);
  const CObjectList& getAllObjects();

private:
  std::string m_name;
  std::string m_description;
  CObjectList m_allObjects;
};