#pragma once
#include <iostream>
#include <memory>
#include "Player.h"

using namespace std;

class gameManager {
private:
    static void createGame(unique_ptr <Player>& player);
    static gameManager instance;
    gameManager() {};
public:
    void start();
    gameManager(const gameManager&) = delete;
    static gameManager& Get();
};
