#include <iostream>
#include <memory>
#include "Game.h"
#include "horrorGame.h"
#include "Simulator.h"
#include "storyGame.h"

using namespace std;

unsigned int Game::constanta = 0;

Game::Game():
    length(0),
    score(0),
    price(0),
    sales(0),
    rating(0),
    name("None"),
    difficulty("None")
{
    constanta++;
    id = constanta;
//    cout << "Game created!";
}

Game::Game(unsigned int _length, unsigned int _price, unsigned int _rating, string _name, string _difficulty):
    length(_length),
    price(_price),
    name(_name),
    difficulty(_difficulty),
    rating(_rating),
    score(0),
    sales(0)
{
    constanta++;
    id = constanta;
//    cout << "Game created!";
}

Game::~Game(){
//    cout << "Destructor";
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

int Game::getRating() const {
    return rating;
}

int Game::getSales() const {
    return sales;
}

void Game::setScore(unsigned int _score) {
    score = _score;
}

void Game::setSales(unsigned int _sales) {
    sales = _sales;
}

int Game::getId() const {
    return id;
}

ostream& operator<<(ostream& os, const Game& game)
{
    os << "The game with the id " << game.id << " called " << game.name << " with the score of " << game.score << " made a total amount of " << game.sales << "$";
    return os;
}

Game& Game::operator=(const Game& game)
{
    length = game.length;
    price = game.price;
    name = game.name;
    difficulty = game.difficulty;
    rating = game.rating;
    score = game.score;
    sales = game.sales;
    return *this;
}

