#include <iostream>
#include <stdlib.h>
#include "../headers/storyGame.h"
#include "../headers/Game.h"

using namespace std;

storyGame::storyGame():
    storyQuality(0),
    Game(0, 0, 0, "None", "None")
{
//    cout << "Story game created";
}

storyGame::storyGame(unsigned int story, unsigned int _length, unsigned int _price, unsigned int _rating, string _name, string _difficulty):
    storyQuality(story),
    Game(_length, _price, _rating,  _name, _difficulty)
{
//    cout << "Story game created";
}

storyGame::~storyGame()
{
//    cout << "Deconstructor";
}

int storyGame::getStoryQuality() const {
    return storyQuality;
}

void storyGame::setStoryQuality(unsigned int story) {
    storyQuality = story;
}

bool storyGame::isSuccesful() {
    score = 0;
    if (storyQuality == length)
        score = storyQuality + length;
    else
        score = 10 - storyQuality - length;
    if (rating >= 12)
        score++;
    else
        score--;
    if (price <= 5)
        score++;
    else
        score--;
    if (difficulty == "Easy")
        score++;
    else
        score--;
    if (score >= 7)
        return true;
    else
        return false;
}