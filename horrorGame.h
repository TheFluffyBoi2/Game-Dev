#include <iostream>
#include "Game.h"
#pragma once

using namespace std;

class horrorGame : public Game{
protected:
    unsigned int scareFactor;
public:
    horrorGame();
    horrorGame(unsigned int, unsigned int, unsigned int, unsigned int, string, string);
    ~horrorGame();
    bool isSuccesful();
    int getScareFactor() const;
    void setScareFactor(unsigned int);
};