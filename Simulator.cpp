#include <iostream>
#include "Simulator.h"

using namespace std;

Simulator::Simulator():
    simulationLevel(0),
    Game(0, 0, 0, "None", "None")
{
//    cout << "Simulator creat";
}

Simulator::Simulator(unsigned int simulation, unsigned int _length, unsigned int _price, unsigned int _rating, string _name, string _difficulty):
    simulationLevel(simulation),
    Game(_length, _price, _rating, _name, _difficulty)
{
//    cout << "Simulator creat";
}

Simulator::~Simulator()
{
//    cout << "Deconstructor";
}

int Simulator::getSimulationLevel() const {
    return simulationLevel;
}

void Simulator::setSimulationLevel(unsigned int simulator) {
    simulationLevel = simulator;
}

bool Simulator::isSuccesful() {
    score = 0;
    if (simulationLevel > length)
        score = simulationLevel + length;
    else
        score = simulationLevel;
    if (rating <= 12)
        score++;
    else
        score--;
    if (price <= 5)
        score++;
    else
        score--;
    if (difficulty == "Medium" or difficulty == "Hard")
        score++;
    else
        score--;
    if (score >= 7)
        return true;
    else
        return false;
}