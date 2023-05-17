#include <iostream>
#include "Game.h"

int main()
{
    std::shared_ptr<GameBase> game(new Game);
    game->start();
}