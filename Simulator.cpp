#include <iostream>
#include "Simulator.h"

using namespace std;

Simulator::Simulator():
    simulationLevel(0),
    Game(0, 0, 0, 0, "None", "None", "None")
{
    cout << "Simulator creat";
}

Simulator::Simulator(unsigned int simulation, unsigned int _length, unsigned int _score, unsigned int _price, unsigned int _sales, string _name, string _difficulty, string _rating):
    simulationLevel(simulation),
    Game(_length, _score, _price, _sales, _name, _difficulty, _rating)
{
    cout << "Simulator creat";
}

Simulator::~Simulator()
{
    cout << "Deconstructor";
}

int Simulator::getSimulationLevel() const {
    return simulationLevel;
}

void Simulator::setSimulationLevel(unsigned int simulator) {
    simulationLevel = simulator;
}

bool Simulator::isSuccesful() const {
    return true;
}