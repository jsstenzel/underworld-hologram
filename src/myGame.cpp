#include "myGame.hpp"

myGame::myGame() : 
  CState("") {}

void myGame::handleKeyword(std::string action) {
  if (action == "quit") {
    quitGame();
  }
  else {
    std::cout << "You said: " << action << std::endl;
  }
}