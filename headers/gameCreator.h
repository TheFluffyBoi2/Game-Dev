#pragma once
#include <iostream>
#include <memory>
#include "Game.h"

using namespace std;

class gameCreator {
public:
    static shared_ptr<Game> createGame(int type);
};

