#include <iostream>
#include "../headers/Player.h"
#include "../headers/gameManager.h"
#include "../headers/horrorGame.h"
#include "../headers/Simulator.h"
#include "../headers/storyGame.h"
#include "../headers/gameCreator.h"
#include "../headers/Profit.h"
#include "../headers/Game.h"
#include "../headers/Achievements.h"
#include <memory>
#include <vector>
#include <string>
#include <random>
#include <thread>

using namespace std;

gameManager gameManager::instance;

gameManager& gameManager::Get() {
    return instance;
}

template <class T>
bool better(shared_ptr<Game> &g, T c) {
    if (g->getScore() > c)
        return true;
    else
        return false;
}

template <>
bool better<shared_ptr<Game>&>(shared_ptr<Game> &g1, shared_ptr<Game> &g2) {
    if (g1 > g2)
        return true;
    else
        return false;
}

template<class T> bool better() {
    return true;
}

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
        cout << "Compare a game (6)\n";
        cout << "Profit calculator (7)\n";
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
            uniform_int_distribution<int> dist3(0,5);

            if ((*it)->isSuccesful())
            {
                player->setGoodGames();
                cout << "Reviews are in... : \n";
//                std::chrono::seconds duration(3);
//                std::this_thread::sleep_for(duration);
                cout << reviews_mari[dist(mt)] << " " << note_mari[dist(mt)] << "\n" << std::flush;
//                std::this_thread::sleep_for(duration);
                cout << reviews_mari[dist(mt2)] << " " << note_mari[dist(mt2)] <<"\n" << std::flush;
//                std::this_thread::sleep_for(duration);
                cout << reviews_mari[dist(mt3)] << " " << note_mari[dist(mt3)] << "\n" << std::flush;
                unsigned int finalScore = (note_mari[dist(mt)] + note_mari[dist(mt2)] + note_mari[dist(mt3)]) / 3;
                cout << "Final score: " << finalScore << "\n";
                cout << "Money earned: " << finalScore * (*it)->getPrice() * 100 << "$\n";
                player->setMoney(player->getMoney() + finalScore * (*it)->getPrice() * 100);
                (*it)->setScore(finalScore);
                (*it)->setSales(finalScore * (*it)->getPrice() * 100);
//                cout << better<int>(*(it), 5) << "____________________________________";
//                if (player->getVector().size() > 1)
//                    cout << better<shared_ptr<Game>&>(*(it), *(it-1));
                if (player->getGoodGames() == 1)
                    player->getClassAch().achievement3();
                if (finalScore * (*it)->getPrice() * 100 >= 11000)
                    player->getClassAch().achievement2();
            }

            else
            {
                player->setBadGames();
                cout << "Reviews are in... : \n";
//                std::chrono::seconds duration(3);
//                std::this_thread::sleep_for(duration);
                cout << reviews_mici[dist(mt)] << " " << note_mici[dist(mt)] << "\n" << std::flush;
//                std::this_thread::sleep_for(duration);
                cout << reviews_mici[dist(mt2)] << " " << note_mici[dist(mt2)] <<"\n" << std::flush;
//                std::this_thread::sleep_for(duration);
                cout << reviews_mici[dist(mt3)] << " " << note_mici[dist(mt3)] << "\n" << std::flush;
                unsigned int finalScore = (note_mici[dist(mt)] + note_mici[dist(mt2)] + note_mici[dist(mt3)]) / 3;
                cout << "Final score: " << finalScore << "\n";
                cout << "Money earned: " << finalScore * (*it)->getPrice() << "\n";
                player->setMoney(player->getMoney() + finalScore * (*it)->getPrice());
                (*it)->setScore(finalScore);
                (*it)->setSales(finalScore * (*it)->getPrice());
//                cout << better(*(it), 5) << "____________________________________";
//                if (player->getVector().size() > 1)
//                    cout << better<shared_ptr<Game>&>(*(it), *(it-1));
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

        if (choice == 6)
        {
            cout << "Which game do you want to compare? (0- " << player->getVector().size()-1 << "): ";
            int game1;
            cin >> game1;
            cout << "Do you want to compare it with a game (1)\n";
            cout << "Do you want to compare it with a number (2)\n";
            int choice;
            cin >> choice;
            if (choice == 1) {
                cout << "Which game do you want to compare? (0- " << player->getVector().size()-1 << "): ";
                int game2;
                cin >> game2;
                if (better<shared_ptr<Game>&>(player->getVector()[game1], player->getVector()[game2]))
                    cout << "The first game is better\n";
                else
                    cout << "The second game is better\n";
            }
            if (choice == 2) {
                cout << "What type of number?\n";
                cout << "Int (1)\n";
                cout << "Double (2)\n";
                cout << "Float (3)\n";
                int numberType;
                cin >> numberType;
                if (numberType == 1)
                {
                    cout << "Number: ";
                    int number;
                    cin >> number;
                    if (better<int>(player->getVector()[game1], number))
                        cout << "The game is better\n";
                    else
                        cout << "The game is worse\n";
                }
                if (numberType == 2)
                {
                    cout << "Number: ";
                    double number;
                    cin >> number;
                    if (better<double>(player->getVector()[game1], number))
                        cout << "The game is better\n";
                    else
                        cout << "The game is worse\n";
                }
                if (numberType == 3)
                {
                    cout << "Number: ";
                    float number;
                    cin >> number;
                    if (better<float>(player->getVector()[game1], number))
                        cout << "The game is better\n";
                    else
                        cout << "The game is worse\n";
                }
            }
        }

        if (choice == 7)
        {
            cout << "What type of number?\n";
            cout << "Int (1)\n";
            cout << "Double (2)\n";
            cout << "Float (3)\n";
            int numberType;
            cin >> numberType;
            if (numberType == 1)
            {
                cout << "Starting sum: ";
                int startingSum;
                cin >> startingSum;
                int cost;
                cout << "Costul jocului: ";
                cin >> cost;
                cout << endl;
                int n1, n2, n3;
                cout << "First grade: ";
                cin >> n1;
                cout << endl;
                cout << "Second grade: ";
                cin >> n2;
                cout << endl;
                cout << "Third grade: ";
                cin >> n3;
                cout << endl;
                vector<int> v = {n1,n2,n3};
                winnings<int> w(startingSum, cost, v);
                cout << "Final sum: " << w.calculateProfit() << endl;
            }
            if (numberType == 2)
            {
                cout << "Starting sum: ";
                double startingSum;
                cin >> startingSum;
                double cost;
                cout << "Costul jocului: ";
                cin >> cost;
                cout << endl;
                double n1, n2, n3;
                cout << "First grade: ";
                cin >> n1;
                cout << endl;
                cout << "Second grade: ";
                cin >> n2;
                cout << endl;
                cout << "Third grade: ";
                cin >> n3;
                cout << endl;
                vector<double> v = {n1,n2,n3};
                winnings<double> w(startingSum, cost, v);
                cout << "Final sum: " << w.calculateProfit() << endl;
            }
            if (numberType == 3)
            {
                cout << "Starting sum: ";
                float startingSum;
                cin >> startingSum;
                float cost;
                cout << "Costul jocului: ";
                cin >> cost;
                cout << endl;
                float n1, n2, n3;
                cout << "First grade: ";
                cin >> n1;
                cout << endl;
                cout << "Second grade: ";
                cin >> n2;
                cout << endl;
                cout << "Third grade: ";
                cin >> n3;
                cout << endl;
                vector<float> v = {n1,n2,n3};
                winnings<float> w(startingSum, cost, v);
                cout << "Final sum: " << w.calculateProfit() << endl;
            }
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
    game = gameCreator::createGame(choice);
    player->getVector().push_back(game);
    //
}