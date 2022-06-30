#include "roomList.hpp"
#include "room.hpp"

CRoomList::CRoomList() {}

CRoomList::CRoomList(const std::vector<std::shared_ptr<CRoom>>& vec) :
  m_rooms(vec) {}

void CRoomList::addRoom(std::shared_ptr<CRoom> room) { 
  m_rooms.push_back(room); 
}

bool CRoomList::removeRoom(std::shared_ptr<CRoom> room) {
  for(auto it = m_rooms.begin(); it != m_rooms.end(); ++it) {
    if ((*it) == room) {
      m_rooms.erase(it);
      return true;
    }
  }
  return false;
}

CRoomList CRoomList::findRoom(const std::string& name) {
  // Find all rooms with matching name
  std::vector<std::shared_ptr<CRoom>> rooms;
  for(auto room : m_rooms) {
    if (room->getName() == name) {
      rooms.push_back(room);
    }
  }
  
  return CRoomList(rooms);
}

bool CRoomList::empty() { return m_rooms.empty(); }

size_t CRoomList::size() { return m_rooms.size(); }

void CRoomList::clear() { m_rooms.clear(); }

std::shared_ptr<CRoom> CRoomList::at(const size_t& index) { return m_rooms.at(index); }

std::shared_ptr<CRoom>& CRoomList::operator[](size_t index) { return m_rooms[index]; }

std::vector<std::shared_ptr<CRoom>>::iterator CRoomList::begin() { return m_rooms.begin(); }

std::vector<std::shared_ptr<CRoom>>::iterator CRoomList::end() { return m_rooms.end(); }

std::vector<std::shared_ptr<CRoom>>::reverse_iterator CRoomList::rbegin() { return m_rooms.rbegin(); }

std::vector<std::shared_ptr<CRoom>>::reverse_iterator CRoomList::rend() { return m_rooms.rend(); }