#include <iostream>
#include "Game.h"
#include <memory>
using namespace std;

class gameCreator {
public:
    static shared_ptr<Game> createGame(int type);
};

