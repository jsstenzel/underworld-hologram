#pragma once
#include "core/include.hpp"

class myGame : virtual public CState {
public:
  myGame() {
    setHeader("////////////\n// MyGame //\n////////////");
  }

  void handleKeyword(const std::string& action) {
    if (action == "quit") {
      quitGame();
    }
    else if (action == "look") {
      auto room = CGame::currentRoom();
      std::cout << room->getDescription() << std::endl;
    }
    else if (action == "search") {
      auto room = CGame::currentRoom();
      auto objects = room->getAllObjects();
      std::string str = "You see:\n";
      for(auto object : objects) {
        str += ( "  " + object->getName() + "\n" );
      }
      std::cout << str;
    }
    else {
      std::cout << "You said: " << action << std::endl;
    }
  }
};