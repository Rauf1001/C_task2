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

    virtual int setCurrentPhase(int current_phase);

};



