#include <iostream>
#include "../headers/Player.h"
#include "../headers/Game.h"
#include "../headers/Achievements.h"

using namespace std;

Player::Player():
    money(0),
    goodGames(0),
    badGames(0)
{
//    cout << "Player created";
}

Player::Player(unsigned int _money):
    money(_money),
    goodGames(0),
    badGames(0)
{
//    cout << "Player created";
}

Player::~Player()
{
//    cout << "Deconstructor";
}

double Player::getMoney() const {
    return money;
}

void Player::setMoney(int _money) {
    money = _money;
}

vector<shared_ptr<Game>>& Player::getVector() {
    return games;
}

vector<string>& Player::getAch() {
    return ach.getAchievements();
}

Achievements& Player::getClassAch() {
    return ach;
}

void Player::setGoodGames() {
    goodGames++;
}

void Player::setBadGames() {
    badGames++;
}

unsigned int Player::getGoodGames() const {
    return goodGames;
}

unsigned int Player::getBadGames() const {
    return badGames;
}