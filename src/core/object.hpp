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
  CObject(std::string name, const std::vector<std::string>& adjectives);
  virtual ~CObject() = 0;

  std::string getName();
  const std::vector<std::string>& getAdjectives();

protected:
  virtual void handleCommand(const SCommandDesc& command);

private:
  SObjectDesc m_desc;
};