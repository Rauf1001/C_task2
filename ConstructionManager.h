#pragma once
#include <string>

#include "Building.h"
#include "Interfaces/IWorker.h"


namespace BuilderSim {
    class ConstructionManager {
    private:
        Building *myBuilding = nullptr;
        IWorker *currentWorker = nullptr;


        int choice = -1;
        int workerChoice = -1;
        int currentWeek = 0;
        double powerInWeek = 0.0;
        double powerArch = 0.0;
        double powerIng = 0.0;
        double powerBuild = 0.0;

    public:
        ~ConstructionManager();

        void startProgram(std::string name, int floor, double square);

        void showCurrentPhase();

        bool hireWorker(int type, std::string name, int age);

        void printStatics();

        void phaseChanged();
    };
}
