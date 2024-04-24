#include <iostream>
#include "Player.h"
#include "gameManager.h"
#include "horrorGame.h"
#include "Simulator.h"
#include "storyGame.h"
#include <memory>
#include <vector>
#include <string>
#include <random>
#include <thread>

using namespace std;

void gameManager::start() {
    unique_ptr<Player> player = make_unique<Player>(500);

    vector<int> note_mici = {0,1,2,3,4,5};
    vector<int> note_mari = {11,10,9,8,7,6};
    vector<string> reviews_mici = {"Worst game of the year!", "I'd rather watch grass grow...", "I want my money back!!", "You call this a game?", "My grandma could make a better game!", "Don't let him make games ever again!"};
    vector<string> reviews_mari = {"GOTY right here!", "Masterpiece...", "I'm at a loss of words...", "Can't wait to play more games like this!", "Future classic!", "Pretty good!"};

    while (true)
    {
        int money = player->getMoney();
        if (money < 0)
            player->getClassAch().achievement1();
        if (money >= 1000)
            player->getClassAch().achievement5();

        int choice;
        cout << "\nWhat would you like to do? :\n";
        cout << "Create a new game (cost 100$) (1)\n";
        cout << "Quit (2)\n";
        cout << "Show my achievements (3)\n";
        cout << "Show all achievements (4)\n";
        cout << "Show all games (5)\n";
        cout << "Current balance: " << player->getMoney() << "$ \n";
        cout << "Choice: ";
        cin >> choice;

        if (choice == 1)
        {
            player->setMoney(player->getMoney() - 100);
            createGame(player);

            auto it = (player->getVector()).end() - 1;

            random_device random;
            mt19937 mt(random());
            uniform_int_distribution<int> dist(0,5);
            random_device random2;
            mt19937 mt2(random2());
            uniform_int_distribution<int> dist2(0,5);
            random_device random3;
            mt19937 mt3(random3());
            uniform_int_distribution<int> dist3(1,6);

            if ((*it)->isSuccesful())
            {
                player->setGoodGames();
                cout << "Reviews are in... : \n";
                std::chrono::seconds duration(3);
                std::this_thread::sleep_for(duration);
                cout << reviews_mari[dist(mt)] << " " << note_mari[dist(mt)] << "\n" << std::flush;
                std::this_thread::sleep_for(duration);
                cout << reviews_mari[dist(mt2)] << " " << note_mari[dist(mt2)] <<"\n" << std::flush;
                std::this_thread::sleep_for(duration);
                cout << reviews_mari[dist(mt3)] << " " << note_mari[dist(mt3)] << "\n" << std::flush;
                unsigned int finalScore = (note_mari[dist(mt)] + note_mari[dist(mt2)] + note_mari[dist(mt3)]) / 3;
                cout << "Final score: " << finalScore << "\n";
                cout << "Money earned: " << finalScore * (*it)->getPrice() * 100 << "$\n";
                player->setMoney(player->getMoney() + finalScore * (*it)->getPrice() * 100);
                (*it)->setScore(finalScore);
                (*it)->setSales(finalScore * (*it)->getPrice() * 100);
                if (player->getGoodGames() == 1)
                    player->getClassAch().achievement3();
                if (finalScore * (*it)->getPrice() * 100 >= 11000)
                    player->getClassAch().achievement2();
            }

            else
            {
                player->setBadGames();
                cout << "Reviews are in... : \n";
                std::chrono::seconds duration(3);
                std::this_thread::sleep_for(duration);
                cout << reviews_mici[dist(mt)] << " " << note_mici[dist(mt)] << "\n" << std::flush;
                std::this_thread::sleep_for(duration);
                cout << reviews_mici[dist(mt2)] << " " << note_mici[dist(mt2)] <<"\n" << std::flush;
                std::this_thread::sleep_for(duration);
                cout << reviews_mici[dist(mt3)] << " " << note_mici[dist(mt3)] << "\n" << std::flush;
                unsigned int finalScore = (note_mici[dist(mt)] + note_mici[dist(mt2)] + note_mici[dist(mt3)]) / 3;
                cout << "Final score: " << finalScore << "\n";
                cout << "Money earned: " << finalScore * (*it)->getPrice() << "\n";
                player->setMoney(player->getMoney() + finalScore * (*it)->getPrice());
                (*it)->setScore(finalScore);
                (*it)->setSales(finalScore * (*it)->getPrice());
                if (player->getBadGames() == 1)
                    player->getClassAch().achievement4();
            }
        }

        if (choice == 2)
            break;

        if (choice == 3)
        {
            cout << "Achievements " << player->getAch().size() << "/5: \n";
            for (const auto &it : player->getAch())
                cout << it << "\n";
        }

        if (choice == 4)
        {
            Achievements::showAllAchievements();
        }

        if (choice == 5)
        {
            cout << "Games: \n";
            for (const auto &it : player->getVector())
                cout << (*it) << "\n";
        }
    }
}

void gameManager::createGame(unique_ptr<Player>& player) {
    unsigned int gameCap = 10;
    shared_ptr<Game> game;
    int choice;
    cout << "What kind of game would you like to create? :\n";
    cout << "Horror game (1)\n";
    cout << "Simulator (2)\n";
    cout << "Story Game (3):\n";
    cout << "Choice: ";
    cin >> choice;

    if (choice == 1){
        cout << "Horror game chosen\n";
        cout << "How would you like to name the game?:\n";
        cin.ignore(10000, '\n');
        string name;
        getline(cin, name);
        cout << "Chose how long will your game be (1-9 hrs):\n";
        unsigned int length;
        cin >> length;
        gameCap -= length;
        cout << "Chose how scary do you want to make your game (1-" << gameCap << "):\n";
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
            cout << "Over price, auto 1\n";
            price = 1;
        }
        cout << "Chose difficulty (Easy, Medium, Hard):\n";
        string difficulty;
        cin >> difficulty;
        cout << "Chose rating (+3 +7 +12 +16 +18):\n";
        cout << "+";
        unsigned int rating;
        cin >> rating;
        shared_ptr<horrorGame> horror = make_shared<horrorGame>(scareFactor, length, price, rating, name, difficulty);
        game = dynamic_pointer_cast<Game>(horror);
        player->getVector().push_back(game);

    }
    if (choice == 2){
        cout << "Simulator chosen\n";
        cout << "How would you like to name the game?:\n";
        cin.ignore(10000, '\n');
        string name;
        getline(cin, name);
        cout << "Chose how long will your game be (1-9 hrs):\n";
        unsigned int length;
        cin >> length;
        gameCap -= length;
        cout << "Chose how realistic do you want to make your game (1-" << gameCap << "):\n";
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
        string difficulty;
        cin >> difficulty;
        cout << "Chose rating (+3 +7 +12 +16 +18):\n";
        cout << "+";
        unsigned int rating;
        cin >> rating;
        shared_ptr<Simulator> simulator = make_shared<Simulator>(simulation, length, price, rating, name, difficulty);
        game = dynamic_pointer_cast<Game>(simulator);
        player->getVector().push_back(game);
    }
    if (choice == 3){
        cout << "Story game chosen\n";
        cout << "How would you like to name the game?:\n";
        cin.ignore(10000, '\n');
        string name;
        getline(cin, name);
        cout << "Chose how long will your game be (1-9 hrs):\n";
        unsigned int length;
        cin >> length;
        gameCap -= length;
        cout << "Chose how good do you want to make your game's story (1-" << gameCap << "):\n";
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
            cout << "Over price, auto 1\n";
            price = 1;
        }
        cout << "Chose difficulty (Easy, Medium, Hard):\n";
        string difficulty;
        cin >> difficulty;
        cout << "Chose rating (+3 +7 +12 +16 +18):\n";
        cout << "+";
        unsigned int rating;
        cin >> rating;
        shared_ptr<storyGame> _story = make_shared<storyGame>(story, length, price, rating, name, difficulty);
        game = dynamic_pointer_cast<Game>(_story);
        player->getVector().push_back(game);
    }
}