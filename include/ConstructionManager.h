#pragma once
#include <map>
#include <string>
#include <vector>
#include "Building.h"
#include "Interfaces/IWorker.h"


namespace BuilderSim {
    class ConstructionManager {
    private:
        Building *myBuilding = nullptr;
        IWorker *currentWorker = nullptr;

        // std::multimap<std::string,double> workers;
        // struct WorkerRecord {
        //     std::string name;
        //     double power;
        //
        // };
        std::vector<IWorker*> workers;

        // std::vector<WorkerRecord> workers;


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
        int getWorkersCount() const { return workers.size(); }
    };
}
