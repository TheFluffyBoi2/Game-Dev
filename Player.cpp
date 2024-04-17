#include <iostream>
#include "Player.h"

using namespace std;

Player::Player():
    money(0)
{
    cout << "Player created";
}

Player::Player(unsigned int _money):
    money(_money)
{
    cout << "Player created";
}

Player::~Player()
{
    cout << "Deconstructor";
}

int Player::getMoney() const {
    return money;
}

void Player::setMoney(unsigned int _money) {
    money = _money;
}

vector<Game> Player::getVector() const {
    return games;
}