#pragma once
#include <iostream>
#include "Game.h"

using namespace std;

class Simulator : public Game{
protected:
    unsigned int simulationLevel;
public:
    Simulator();
    Simulator(unsigned int, unsigned int, unsigned int, unsigned int, string, string);
    ~Simulator();
    bool isSuccesful();
    int getSimulationLevel() const;
    void setSimulationLevel(unsigned int);
};
