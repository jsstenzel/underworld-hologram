#pragma once
/*
 Base class for all game objects.
 */
#include "common.hpp"

class CGame;

class CObject : public std::enable_shared_from_this<CObject> {
public:
  friend class CGame;
  CObject(std::string name);

  const std::string& getName();

protected:
  virtual void handleCommand(const SCommandDesc& command) {}

private:
  std::string m_name;
};