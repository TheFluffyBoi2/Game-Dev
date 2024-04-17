#include <iostream>
#pragma once

using namespace std;

class Game {
private:
    unsigned int length, price, score, sales;
    string name, difficulty, rating;
public:
    Game();
    Game(unsigned int, unsigned int, unsigned int, unsigned int, string, string, string);
    ~Game();
    string getName() const;
    int getLength() const;
    int getPrice() const;
    int getScore() const;
    int getSales() const;
    string getDifficulty() const;
    string getRating() const;
    virtual bool isSuccesful() const;
};
