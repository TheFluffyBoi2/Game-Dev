#include <iostream>
#include "Game.h"
#pragma once

using namespace std;

class storyGame : public Game{
private:
    unsigned int storyQuality;
public:
    storyGame();
    storyGame(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, string, string, string);
    ~storyGame();
    int getStoryQuality() const;
    void setStoryQuality(unsigned int story);
    bool isSuccesful() const;
};
