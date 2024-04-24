#include <iostream>

using namespace std;

#include "horrorGame.h"

horrorGame::horrorGame():
    Game(0, 0, 0, "None", "None"),
    scareFactor(0)
{
//    cout << "Horror game created!";
}

horrorGame::horrorGame(unsigned int _scare, unsigned int _length, unsigned int _price, unsigned int _rating, string _name, string _difficulty):
    scareFactor(_scare),
    Game(_length, _price, _rating, _name, _difficulty)
{
//    cout << "Horror game created!";
}

horrorGame::~horrorGame() {
//    cout << "Destructor horror game";
}

int horrorGame::getScareFactor() const {
    return scareFactor;
}

void horrorGame::setScareFactor(unsigned int _scare) {
    scareFactor = _scare;
}

bool horrorGame::isSuccesful() {
    score = 0;
    if (scareFactor > length)
        score = scareFactor + length;
    else
        score = scareFactor;
    if (rating >= 16)
        score++;
    else
        score--;
    if (price <= 5)
        score++;
    else
        score--;
    if (score >= 7)
    {
        return true;
    }
    else
    {
        return false;
    }
}
