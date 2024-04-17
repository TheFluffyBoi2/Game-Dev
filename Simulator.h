#include <iostream>
#include "Game.h"
#pragma once

using namespace std;

class Simulator : public Game{
private:
    unsigned int simulationLevel;
public:
    Simulator();
    Simulator(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, string, string, string);
    ~Simulator();
    bool isSuccesful() const;
    int getSimulationLevel() const;
    void setSimulationLevel(unsigned int);
};
