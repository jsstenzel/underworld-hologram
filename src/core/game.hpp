#pragma once
/*
 High level game logic processing class.
 Holds a list of all rooms, list of global game objects, and passes down
 commands to the correct objects.
 */
#include "common.hpp"
#include "objectList.hpp"
#include "roomList.hpp"

class CObject;
class CRoom;
class CState;

class CGame {
public:
  static void addObject(std::shared_ptr<CObject> object, std::shared_ptr<CRoom> room = nullptr);
  static bool removeObject(std::shared_ptr<CObject> object, std::shared_ptr<CRoom> room = nullptr);
  static CObjectList findObject(const std::string& name, std::shared_ptr<CRoom> room = nullptr);
  static void addRoom(std::shared_ptr<CRoom> room);
  static bool removeRoom(std::shared_ptr<CRoom> room);
  static CRoomList findRoom(const std::string& name);
  static std::shared_ptr<CRoom> currentRoom();
  static void setRoom(std::shared_ptr<CRoom> room);
  const CRoomList& getAllRooms();
  
  static int run(std::shared_ptr<CState> state);
  static std::shared_ptr<CState> getState();
  
private:
  static void handleCommand(const SCommandDesc& command);

  static CObjectList m_globalObjects;
  static CRoomList m_allRooms;
  static std::shared_ptr<CRoom> m_currentRoom;
  static std::shared_ptr<CState> m_state;
};