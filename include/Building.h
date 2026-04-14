#pragma once
#include <string>

namespace BuilderSim {
    class Building {
    private:
        std::string name;
        int floor = 0;
        double square = 0.0;
        int currentPhase = 0;
        double powerInWeek = 0.0;

    public:
        Building(const std::string &name, int floor, double square);

        ~Building();

        const std::string &getName() const;

        int getFloor() const;

        double getSquare() const;

        int getCurrentPhase() const;

        void showCurrentPhase() const;

        void setCurrentPhase(int phase);

        bool countCurrentPhase(double powerArch, double powerIng, double powerBuild, int currentWeek);
    };
}
