#include <iostream>
#include "Game.h"
#include "Player.h"
#include "horrorGame.h"
#include "Simulator.h"
#include "storyGame.h"

using namespace std;

int main() {
    Game* game = new storyGame;
    storyGame game2;
    game2.setStoryQuality(50);
    cout << game2.getStoryQuality();
    delete game;
    return 0;
}
