#include <iostream>
#include "Player.h"
#include "gameManager.h"
#include "horrorGame.h"
#include "Simulator.h"
#include "storyGame.h"
#include <memory>
#include <vector>

using namespace std;

void gameManager::start() {
    unique_ptr<Player> player = make_unique<Player>(500);

    vector<int> note_mici = {1,2,3,4,5};
    vector<int> note_mari = {6,7,8,9,10};
    vector<string> reviews_mici = {"Worst game of the year!", "I'd rather watch grass grow...", "I want my money back!!", "You call this a game?", "My grandma could make a better game!", "Don't let bro cook ever again."};
    vector<string> reviews_mari = {"GOTY right here!", "Masterpiece", "I'm at a loss of words...", "Can't wait to play more games like this!", "Future classic!", "Pretty good!"};

    while (true)
    {
        int choice;
        cout << "What would you like to do? :\n";
        cout << "Create a new game (1)\n";
        cout << "Quit (2)\n";
        cin >> choice;

        if (choice == 1)
            createGame();
        if (choice == 2)
            break;
    }
}

void gameManager::createGame() {
    unsigned int gameCap = 10;
    unique_ptr<Game> game = make_unique<Game>();
    int choice;
    cout << "What kind of game would you like to create? :\n";
    cout << "Horror game (1)\n";
    cout << "Simulator (2)\n";
    cout << "Story Game (3):\n";
    cin >> choice;

    if (choice == 1){
        cout << "Horror game chosen\n";
        cout << "How would you like to name the game?:\n";
        string name;
        cin >> name;
        cout << "Chose how long will your game be (1-9 hrs):\n";
        unsigned int length;
        cin >> length;
        gameCap -= length;
        cout << "Chose how scary do you want to make your game (1-" << gameCap << "):\n";
        int scareFactor;
        cin >> scareFactor;
        if (scareFactor > gameCap)
        {
            cout << "Over budget, auto 1";
            scareFactor = 1;
        }
        gameCap -= scareFactor;
        cout << "Chose the price:\n";
        unsigned int price;
        cin >> price;
        unique_ptr<horrorGame> horror = make_unique<horrorGame>(scareFactor, length, price, name, "a", "a");
    }
    if (choice == 2){

    }
    if (choice == 3){

    }
}