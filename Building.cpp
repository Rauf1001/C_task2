#include "Building.h"

#include <iostream>
using namespace std;

namespace BuilderSim {
    Building::Building(const std::string &n, int f, double s) {
        this->name = n;
        floor = f;
        square = s;
        currentPhase = 0;
    }


    Building::~Building() {
    }

    const string &Building::getName() const { return name; }

    int Building::getFloor() const { return floor; }

    double Building::getSquare() const { return square; }

    int Building::getCurrentPhase() const { return currentPhase; }

    void Building::setCurrentPhase(int phase) { currentPhase = phase; }

    void Building::showCurrentPhase() const {
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

    bool Building::countCurrentPhase(double powerArch, double powerIng, double powerBuild, int currentWeek) {
        if (currentPhase >= 3)
            return false;

        if (currentPhase == 0) {
            powerInWeek = powerArch * (currentWeek * 5.0);
        } else if (currentPhase == 1) {
            powerInWeek = powerIng * (currentWeek * 5.0);
        } else if (currentPhase == 2) {
            powerInWeek = powerBuild * (currentWeek * 5.0);
        }

        const double phaseRequirement = (floor * square) / 3.0;


        if (powerInWeek >= phaseRequirement) {
            currentPhase += 1;
            return true;
        }
        return false;
    }
}
