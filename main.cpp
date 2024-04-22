#include <iostream>
#include <vector>
#include <memory>
#include "Game.h"
#include "Player.h"
#include "horrorGame.h"
#include "Simulator.h"
#include "storyGame.h"
#include "gameManager.h"

using namespace std;

int main() {
    gameManager game;
    game.start();
    return 0;
}
