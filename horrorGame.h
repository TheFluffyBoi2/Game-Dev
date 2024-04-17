#include <iostream>
#include "Game.h"
#pragma once

using namespace std;

class horrorGame : public Game{
private:
    unsigned int scareFactor;
public:
    horrorGame();
    horrorGame(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, string, string, string);
    ~horrorGame();
    bool isSuccesful() const;
    int getScareFactor() const;
    void setScareFactor(unsigned int);
};