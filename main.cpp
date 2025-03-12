#include <iostream>
#include <vector>
#include <memory>
#include "headers/gameManager.h"

using namespace std;

int main() {
    gameManager::Get().start();
    return 0;
}
