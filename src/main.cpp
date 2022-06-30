#include "core/include.hpp"
#include "myGame.hpp"

int main() {
  std::shared_ptr<CState> game(new myGame);
  CGame::run(game);
  return 0;
}