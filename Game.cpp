#include <iostream>
#include <memory>
#include "Game.h"
#include "horrorGame.h"
#include "Simulator.h"
#include "storyGame.h"

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

Game::Game(unsigned int _length, unsigned int _price, string _name, string _difficulty, string _rating):
    length(_length),
    price(_price),
    name(_name),
    difficulty(_difficulty),
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

//unique_ptr<Game> Game::makeGame(){
//    int choice;
//    cout << "What kind of game would you like to create? : ";
//    cout << "Horror game (1)";
//    cout << "Simulator (2)";
//    cout << "Story Game (3)";
//    cin >> choice;
//
//    if (choice == 1)
//    {
//        unique_ptr<Game> game = make_unique<Game>(0, 0, 0, 0, "a", "a", "a");
//        cout << game->isSuccesful();
//        game = make_unique<horrorGame>();
//        cout << game->isSuccesful();
//        return game;
//    }
//
//}