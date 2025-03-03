#include <iostream>
#include <vector>
#include <memory>
#include "Game.h"
#include "Player.h"
#include "horrorGame.h"
#include "Simulator.h"
#include "storyGame.h"
#include "gameManager.h"
#include "Placeholder.h"

using namespace std;

int main() {
    gameManager::Get().start();
    return 0;
}
