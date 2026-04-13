#pragma once
#include <string>

#include "Building.h"
#include "Interfaces/IWorker.h"

// using namespace std;

namespace BuilderSim {
    class ConstructionManager {
    private:
        BuilderSim::Building *myBuilding = nullptr;
        IWorker *currentWorker = nullptr;
        // int currentPhase = 0;
        // double square = 0.0;
        // int floor = 0;
        // int tempAge = 0;
        // string tempName;



        // string tempName;
        // int tempAge = 0;
        // int tempFloor = 0;
        // double tempSquare = 0.0;
        int choice = -1;
        int workerChoice = -1;
        int currentWeek = 0;
        double powerInWeek = 0.0;
        double powerArch = 0.0;
        double powerIng = 0.0;
        double powerBuild = 0.0;

    public:
        ~ConstructionManager();
        void startProgram(std::string name ,int floor,double square);
        void showCurrentPhase();
        bool hireWorker(int type, std::string name, int  age);
        void printStatics();
        // void workerChoise();
        void phaseChanged();

        // void clearMemory();
    };
}