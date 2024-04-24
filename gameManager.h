#include <iostream>
#pragma once
#include <memory>

using namespace std;

class gameManager {
private:
    static void createGame(unique_ptr <Player>& player);
public:
    void start();
};
