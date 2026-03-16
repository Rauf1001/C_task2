#pragma once
#include <string>

using namespace std;

class Building {
private:
    string name;
    int floor;
    double square;
    int currentPhase;
public:
    Building(string name, int floor,double square);

    ~Building();

    string getName();
    int getFloor();
    double getSquare();

    int getCurrentPhase();
    void setCurrentPhase(int phase);
    // int countCurrentPhase(int phase);
    // void count()
    void showCurrentPhase();
    bool countCurrentPhase(double countPower, int currentWeek);
};



