#pragma once
#include <string>

using namespace std;


class Controller {
private:
    string tempName;
    int tempAge;
    int tempFloor;
    double tempSquare;
    int choice = -1;
    int workerChoice = -1;
    int currentWeek = 1;
    double countPower;
public:
    void writeController();
    void clearMemorry();
};