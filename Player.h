#include <iostream>
#include <vector>
#include "Game.h"
#include "horrorGame.h"
#include "Simulator.h"
#include "storyGame.h"
#include "Achievements.h"
#include <memory>
#pragma once

using namespace std;

class Player {
private:
    vector<shared_ptr<Game>> games;
    double money;
    Achievements ach;
    unsigned int goodGames, badGames;
public:
    Player();
    Player(unsigned int);
    ~Player();
    double getMoney() const;
    void setMoney(int);
    void setGoodGames();
    void setBadGames();
    unsigned int getGoodGames() const;
    unsigned int getBadGames() const;
    vector<shared_ptr<Game>>& getVector();
    vector<string>& getAch();
    Achievements& getClassAch();
};


