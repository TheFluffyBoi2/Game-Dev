#pragma once
#include <iostream>
#include <vector>
#include <memory>

using namespace std;

class Game {
protected:
    unsigned int length, price, sales, rating, id;
    int score;
    string name, difficulty;
    static unsigned int constanta;
public:
    Game();
    Game(unsigned int, unsigned int, unsigned int, string, string);
    ~Game();
    string getName() const;
    int getLength() const;
    int getPrice() const;
    int getScore() const;
    int getSales() const;
    string getDifficulty() const;
    int getRating() const;
    void setScore(unsigned int);
    void setSales(unsigned int);
    int getId() const;
    virtual bool isSuccesful() = 0;
    friend ostream& operator<<(ostream& os, const Game& game);
    bool operator>(shared_ptr<Game> &g) {return this->getScore() > g->getScore();};
    Game& operator=(const Game&);
};
