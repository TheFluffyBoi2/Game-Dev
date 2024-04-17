#include <iostream>
#include <vector>
#include "Game.h"
#pragma once

using namespace std;

class Player {
private:
    vector<Game> games;
    unsigned int money;
public:
    Player();
    Player(unsigned int);
    ~Player();
    int getMoney() const;
    void setMoney(unsigned int);
    vector<Game> getVector() const;
};


