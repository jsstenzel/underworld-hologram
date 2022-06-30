#pragma once
/*
 Thin wrapper around a vector of room pointers that allows
 searching by room properties.
 */
#include "common.hpp"

class CRoom;

class CRoomList {
public:
  CRoomList();
  CRoomList(const std::vector<std::shared_ptr<CRoom>>& vec);

  void addRoom(std::shared_ptr<CRoom> room);
  bool removeRoom(std::shared_ptr<CRoom> room);
  CRoomList findRoom(const std::string& name);

  bool empty();
  size_t size();
  void clear();
  std::shared_ptr<CRoom> at(const size_t& index);
  std::shared_ptr<CRoom>& operator[](size_t index);
  std::vector<std::shared_ptr<CRoom>>::iterator begin();
  std::vector<std::shared_ptr<CRoom>>::iterator end();
  std::vector<std::shared_ptr<CRoom>>::reverse_iterator rbegin();
  std::vector<std::shared_ptr<CRoom>>::reverse_iterator rend();

private:
  std::vector<std::shared_ptr<CRoom>> m_rooms;
};