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

CObjectList CGame::findObject(const SObjectDesc& desc, std::shared_ptr<CRoom> room) {
  // Look in global list first
  auto objects = CGame::m_globalObjects.findobject(desc);

  // Look in room if object wasn't found
  if (objects.empty() && room) {
    objects = room->findObject(desc); 
  }
  return objects;
}

std::shared_ptr<CRoom> CGame::currentRoom() { return CGame::m_currentRoom; }

void CGame::setRoom(std::shared_ptr<CRoom> room) { CGame::m_currentRoom = room; }

std::shared_ptr<CRoom> CGame::findRoom(std::string name) {
  for(auto rm : CGame::m_allRooms) {
    if (rm->getName() == name) {
      return rm;
    }
  }
  return nullptr;
}

void CGame::handleCommand(const SCommandDesc& command) {
  // Pass keyword to game state to handle it
  if (command.m_flagKeyword) {
    CGame::m_state->handleKeyword(command.m_action);
    return;
  }
  
  // Find objects
  auto objects = findObject(command.m_subject);
  if (objects.size() > 1) { 
    std::cout << "Error: There are " << objects.size() << " objects that match (" 
              << command.m_subject.serialize() << ")!" << std::endl;
    return;
  }
  else if (objects.size() == 0) {
    std::cout << "Error: Could not find " << command.m_subject.serialize() << "!" << std::endl;
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
std::vector<std::shared_ptr<CRoom>> CGame::m_allRooms;
std::shared_ptr<CRoom> CGame::m_currentRoom = nullptr;
std::shared_ptr<CState> CGame::m_state = nullptr;