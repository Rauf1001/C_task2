#pragma once
#include <string>


namespace BuilderSim {
    class Controller {
    private:
        std::string tempName;
        int tempAge = 0;
        int tempFloor = 0;
        double tempSquare = 0.0;
        int choice = -1;
        int workerChoice = -1;

    public:
        void writeController();

        void clearMemorry();
    };
}
