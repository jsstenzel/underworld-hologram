#include "core/include.hpp" // Core functionality
#include "myGame.hpp"       // Game state
#include "myRooms.hpp"      // Game rooms
#include "myObjects.hpp"    // Game objects

int main() {
  // Create rooms
  std::shared_ptr<CRoom> _roomField(new roomField());
  std::shared_ptr<CRoom> _roomMountain(new roomMountain());
  CGame::addRoom(_roomField);
  CGame::addRoom(_roomMountain);

  // Create objects
  std::shared_ptr<CObject> _objRedPotion(new objRedPotion());
  std::shared_ptr<CObject> _objRustyKey(new objRustyKey());
  CGame::addObject(_objRedPotion, _roomField);
  CGame::addObject(_objRustyKey, _roomMountain);

  // Create game state
  std::shared_ptr<CState> game(new myGame);

  // Run game loop
  CGame::run(game);
  return 0;
}