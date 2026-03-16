#include "Building.h"

#include <iostream>
#include <print>

Building::Building(string n, int f, double s) {
    name = n;
    floor = f;
    square = s;
    currentPhase = 0;
}

Building::~Building() {
}

string Building::getName() { return name; }

int Building::getFloor() { return floor; }

double Building::getSquare() { return square; }

int Building::getCurrentPhase() { return currentPhase; }

void Building::setCurrentPhase(int phase) { currentPhase = phase; }

void Building::showCurrentPhase() {
    if (currentPhase == 0) {
        cout << ("Архтектурная Фаза") << endl;
    } else if (currentPhase == 1) {
        cout << ("Инженерная Фаза") << endl;
    } else if (currentPhase == 2) {
        cout << ("Строительная Фаза") << endl;
    } else {
        cout << ("Строительство Успешно Закончено") << endl;
    }
}

bool Building::countCurrentPhase(double countPower, int currentWeek) {
    if (currentPhase >= 3) return false;

    double phaseRequirement = (floor * square) / 3;
    double powerInWeek = countPower * (currentWeek * 5);

    if (powerInWeek >= phaseRequirement) {
        currentPhase += 1;
        return true;
    }
    return false;
}

// int Building::countCurrentPhase(int phase) {
//     currentPhase
// }
