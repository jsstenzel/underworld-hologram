#pragma once
#include "core/include.hpp"

class objRedPotion : public CObject {
public:
  objRedPotion() : CObject("red potion") {}
protected:
  void handleCommand(const SCommandDesc& command) {
    if (command.m_action == "look") {
      std::cout << "It appears to be a thick red liquid that clings to the glass vial it's contained in." << std::endl;
    }
    if (command.m_action == "use" | command.m_action == "drink") {
      std::cout << "Tastes like fake cherries dipped in laundry detergent." << std::endl;
    }
  }
};

class objRustyKey : public CObject {
public:
  objRustyKey() : CObject("rusty key") {}
protected:
  void handleCommand(const SCommandDesc& command) {
    if (command.m_action == "look") {
      std::cout << "Gnarled and tarnished, you'd be surprised if it even fit in its mating lock anymore." << std::endl;
    }
    if (command.m_action == "smell") {
      std::cout << "Beneath the stingent smell of old coins is a hint of forest moss." << std::endl;
    }
  }
};