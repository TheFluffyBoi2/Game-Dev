#include <iostream>
#include "Game.h"

using namespace std;

Game::Game():
    length(0),
    score(0),
    price(0),
    sales(0),
    name("None"),
    difficulty("None"),
    rating("None")
{
    cout << "Game created!";
}

Game::Game(unsigned int _length, unsigned int _score, unsigned int _price, unsigned int _sales, string _name, string _difficulty, string _rating):
    length(_length),
    score(_score),
    price(_price),
    name(_name),
    difficulty(_difficulty),
    sales(_sales),
    rating(_rating)
{
    cout << "Game created!";
}

Game::~Game(){
    cout << "Destructor";
}

string Game::getName() const {
    return name;
}

int Game::getPrice() const {
    return price;
}

int Game::getLength() const {
    return length;
}

int Game::getScore() const {
    return score;
}

string Game::getDifficulty() const {
    return difficulty;
}

string Game::getRating() const {
    return rating;
}

bool Game::isSuccesful() const {
    return false;
}

int Game::getSales() const {
    return sales;
}