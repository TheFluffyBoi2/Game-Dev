#include <iostream>
#include <vector>
#include <string>
#pragma once

using namespace std;

class Achievements {
private:
    static vector<string> achievements;
public:
    ~Achievements();
    static void showAllAchievements();
    static vector<string>& getAchievements();
    static void achievement1();
    static void achievement2();
    static void achievement3();
    static void achievement4();
    static void achievement5();
};