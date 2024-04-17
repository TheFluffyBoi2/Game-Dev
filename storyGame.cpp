#include <iostream>
#include "storyGame.h"

using namespace std;

storyGame::storyGame():
    storyQuality(0),
    Game(0, 0, 0, 0, "None", "None", "None")
{
    cout << "Story game created";
}

storyGame::storyGame(unsigned int story, unsigned int _length, unsigned int _score, unsigned int _price, unsigned int _sales, string _name, string _difficulty, string _rating):
    storyQuality(story),
    Game(_length, _score, _price, _sales, _name, _difficulty, _rating)
{
    cout << "Story game created";
}

storyGame::~storyGame()
{
    cout << "Deconstructor";
}

int storyGame::getStoryQuality() const {
    return storyQuality;
}

void storyGame::setStoryQuality(unsigned int story) {
    storyQuality = story;
}

bool storyGame::isSuccesful() const {
    return true;
}