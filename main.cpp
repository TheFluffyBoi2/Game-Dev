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
//    vector<unique_ptr<Game>> vector;
//    unique_ptr<Game> game1 = make_unique<horrorGame>();
//    unique_ptr<Game> game2 = make_unique<Simulator>();
//    unique_ptr<Game> game3 = make_unique<Game>();
//    vector.push_back(std::move(game1));
//    vector.push_back(std::move(game2));
//    vector.push_back(std::move(game3));
//    for (auto& it : vector)
//    {
//        cout << it->isSuccesful() << "\n";
//    }
//    cout << vector.size();
    return 0;
}
