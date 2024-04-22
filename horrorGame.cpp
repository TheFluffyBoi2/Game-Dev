#include <iostream>

using namespace std;

#include "horrorGame.h"

horrorGame::horrorGame():
    Game(0, 0, "None", "None", "None"),
    scareFactor(0)
{
    cout << "Horror game created!";
}

horrorGame::horrorGame(unsigned int _scare, unsigned int _length, unsigned int _price, string _name, string _difficulty, string _rating):
    scareFactor(_scare),
    Game(_length, _price, _name, _difficulty, _rating)
{
    cout << "Horror game created!";
}

horrorGame::~horrorGame() {
    cout << "Destructor horror game";
}

int horrorGame::getScareFactor() const {
    return scareFactor;
}

void horrorGame::setScareFactor(unsigned int _scare) {
    scareFactor = _scare;
}

bool horrorGame::isSuccesful() const {
    return true;
}