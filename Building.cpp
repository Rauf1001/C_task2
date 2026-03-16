#include "Building.h"

Building::Building(string n, int f, double s) {
    name = n;
    floor = f;
    square = s;
    currentPhase = 0;
}

Building::~Building() {}

string Building::getName() {return name;}

int Building::getFloor() {return floor;}

double Building::getSquare() {return square;}

int Building::getCurrentPhase() {return currentPhase;}

void Building::setCurrentPhase(int phase) {
    currentPhase = phase;
}
