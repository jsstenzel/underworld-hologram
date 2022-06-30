#include "game.hpp"
#include "object.hpp"
#include "room.hpp"
#include "state.hpp"

void CGame::addObject(std::shared_ptr<CObject> object, std::shared_ptr<CRoom> room) {
  if (room) { room->addObject(object); }
  else { CGame::m_globalObjects.addObject(object); }
}

bool CGame::removeObject(std::shared_ptr<CObject> object, std::shared_ptr<CRoom> room) {
  if (room) { return room->removeObject(object); }
  else { return CGame::m_globalObjects.removeObject(object); }
}

CObjectList CGame::findObject(const std::string& name, std::shared_ptr<CRoom> room) {
  // Look in global list first
  auto objects = CGame::m_globalObjects.findObject(name);

  // Look in room if object wasn't found
  if (objects.empty() && room) {
    objects = room->findObject(name); 
  }
  return objects;
}

void CGame::addRoom(std::shared_ptr<CRoom> room) { CGame::m_allRooms.addRoom(room); }

bool CGame::removeRoom(std::shared_ptr<CRoom> room) { return CGame::m_allRooms.removeRoom(room); }

CRoomList CGame::findRoom(const std::string& name) { return CGame::m_allRooms.findRoom(name); }

std::shared_ptr<CRoom> CGame::currentRoom() { return CGame::m_currentRoom; }

void CGame::setRoom(std::shared_ptr<CRoom> room) { CGame::m_currentRoom = room; }

const CRoomList& CGame::getAllRooms() { return CGame::m_allRooms; }

void CGame::handleCommand(const SCommandDesc& command) {
  // Pass keyword to game state to handle it
  if (command.m_flagKeyword) {
    CGame::m_state->handleKeyword(command.m_action);
    return;
  }
  
  // Find objects
  auto objects = findObject(command.m_subject, CGame::m_currentRoom);
  if (objects.size() > 1) { 
    std::cout << "Error: There are " << objects.size() << " objects that match (" 
              << command.m_subject << ")!" << std::endl;
    return;
  }
  else if (objects.size() == 0) {
    std::cout << "Error: Could not find (" << command.m_subject << ")!" << std::endl;
    return;
  }
  
  // Attempt action on object
  objects[0]->handleCommand(command);
}

int CGame::run(std::shared_ptr<CState> state) {
  // Register state
  if (!state) {
    std::cout << "Fatal Error: Invalid state pointer!" << std::endl;
    return -1;
  }
  CGame::m_state = state;

  // Default to first room
  if (CGame::m_allRooms.empty()) {
    std::cout << "Fatal Error: No rooms defined!" << std::endl;
    return -1;
  }
  else if (!CGame::m_currentRoom) {
    CGame::m_currentRoom = CGame::m_allRooms[0];
  }

  // Print header
  std::cout << CGame::m_state->getHeader() << std::endl;

  // Run command loop
  while(CGame::m_state->isRunning()) {
    SCommandDesc command;
    if (!get_command(command)) {
      std::cout << "Error: Parser could not understand that!" << std::endl;
    }
    else {
      CGame::handleCommand(command);
    }
  }
  return 0;
}

std::shared_ptr<CState> CGame::getState() { return CGame::m_state; }


CObjectList CGame::m_globalObjects;
CRoomList CGame::m_allRooms;
std::shared_ptr<CRoom> CGame::m_currentRoom = nullptr;
std::shared_ptr<CState> CGame::m_state = nullptr;