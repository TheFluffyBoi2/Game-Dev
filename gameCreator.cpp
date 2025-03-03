#include <iostream>
#include "gameCreator.h"
#include "horrorGame.h"
#include "Simulator.h"
#include "storyGame.h"
#include <memory>

using namespace std;

shared_ptr<Game> gameCreator::createGame(int type) {
    shared_ptr<Game> g = nullptr;
    unsigned int gameCap = 10;
    if (type == 1){
            cout << "Horror game chosen\n";
            cout << "How would you like to name the game?:\n";
            cout << "Name: ";
            cin.ignore(10000, '\n');
            string name;
            getline(cin, name);
            cout << "Chose how long will your game be (1-9 hrs):\n";
            cout << "Hours: ";
            unsigned int length;
            cin >> length;
            gameCap -= length;
            cout << "Chose how scary do you want to make your game (1-" << gameCap << "):\n";
            cout << "Slider: ";
            int scareFactor;
            cin >> scareFactor;
            if (scareFactor > gameCap)
            {
                cout << "Over budget, auto 1\n";
                scareFactor = 1;
            }
            gameCap -= scareFactor;
            cout << "Chose the price (1-10$):\n";
            cout << "$";
            unsigned int price;
            cin >> price;
            if (price > 10)
            {
                cout << "Over price, auto 1$\n";
                price = 1;
            }
            cout << "Chose difficulty (Easy, Medium, Hard):\n";
            string difficulty;
            cout << "Difficulty: ";
            cin >> difficulty;
            cout << "Chose rating (+3 +7 +12 +16 +18):\n";
            cout << "+";
            unsigned int rating;
            cin >> rating;
            g = make_shared<horrorGame>(scareFactor, length, price, rating, name, difficulty);
        }
    if (type == 2){
            cout << "Simulator chosen\n";
            cout << "How would you like to name the game?:\n";
            cout << "Name: ";
            cin.ignore(10000, '\n');
            string name;
            getline(cin, name);
            cout << "Chose how long will your game be (1-9 hrs):\n";
            cout << "Hours: ";
            unsigned int length;
            cin >> length;
            gameCap -= length;
            cout << "Chose how realistic do you want to make your game (1-" << gameCap << "):\n";
            cout << "Slider: ";
            int simulation;
            cin >> simulation;
            if (simulation > gameCap)
            {
                cout << "Over budget, auto 1\n";
                simulation = 1;
            }
            gameCap -= simulation;
            cout << "Chose the price (1-10$):\n";
            cout << "$";
            unsigned int price;
            cin >> price;
            if (price > 10)
            {
                cout << "Over price, auto 1$\n";
                price = 1;
            }
            cout << "Chose difficulty (Easy, Medium, Hard):\n";
            cout << "Difficulty: ";
            string difficulty;
            cin >> difficulty;
            cout << "Chose rating (+3 +7 +12 +16 +18):\n";
            cout << "+";
            unsigned int rating;
            cin >> rating;
            g = make_shared<Simulator>(simulation, length, price, rating, name, difficulty);
        }
    if (type == 3){
            cout << "Story game chosen\n";
            cout << "How would you like to name the game?:\n";
            cout << "Name: ";
            cin.ignore(10000, '\n');
            string name;
            getline(cin, name);
            cout << "Chose how long will your game be (1-9 hrs):\n";
            cout << "Hours: ";
            unsigned int length;
            cin >> length;
            gameCap -= length;
            cout << "Chose how good do you want to make your game's story (1-" << gameCap << "):\n";
            cout << "Slider: ";
            int story;
            cin >> story;
            if (story > gameCap)
            {
                cout << "Over budget, auto 1\n";
                story = 1;
            }
            gameCap -= story;
            cout << "Chose the price (1-10$):\n";
            cout << "$";
            unsigned int price;
            cin >> price;
            if (price > 10)
            {
                cout << "Over price, auto 1$\n";
                price = 1;
            }
            cout << "Chose difficulty (Easy, Medium, Hard):\n";
            cout << "Difficulty: ";
            string difficulty;
            cin >> difficulty;
            cout << "Chose rating (+3 +7 +12 +16 +18):\n";
            cout << "+";
            unsigned int rating;
            cin >> rating;
            g = make_shared<storyGame>(story, length, price, rating, name, difficulty);
        }
    return g;
}