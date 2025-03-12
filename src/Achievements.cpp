#include <iostream>
#include "../headers/Achievements.h"

using namespace std;

vector<string> Achievements::achievements;

Achievements::~Achievements()
{
//    cout << "Deconstructor";
}

void Achievements::showAllAchievements() {
    cout << "All achievements: \n";
    cout << "Go bankrupt\n" << "Make 11000$ with a single game\n" << "Make your first good game\n" << "Make your first bad game\n" << "Reach a total of 1000$\n";

}

vector<string>& Achievements::getAchievements() {
    return achievements;
}

void Achievements::achievement1() {
    int ok = 1;
    for (auto &it : achievements)
        if ("Go bankrupt" == it)
            ok = 0;
    if (ok == 1)
        achievements.push_back("Go bankrupt");
}

void Achievements::achievement2() {
    int ok = 1;
    for (auto &it : achievements)
        if ("Make 11000$ with a single game" == it)
            ok = 0;
    if (ok == 1)
        achievements.push_back("Make 11000$ with a single game");
}

void Achievements::achievement3() {
    achievements.push_back("Make your first good game");
}

void Achievements::achievement4() {
    achievements.push_back("Make your first bad game");
}

void Achievements::achievement5() {
    int ok = 1;
    for (auto &it : achievements)
        if ("Reach a total of 1000$" == it)
            ok = 0;
    if (ok == 1)
        achievements.push_back("Reach a total of 1000$");
}