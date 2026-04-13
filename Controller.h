#pragma once
#include <string>

// using namespace std;

namespace BuilderSim {
    class Controller {
    private:
        std::string tempName;
        int tempAge = 0;
        int tempFloor = 0;
        double tempSquare = 0.0;
        int choice = -1;
        int workerChoice = -1;
        // int currentWeek = 0;
        // double powerInWeek = 0.0;
        // double powerArch = 0.0;
        // double powerIng = 0.0;
        // double powerBuild = 0.0;

    public:
        void writeController();
        void clearMemorry();
    };
}
