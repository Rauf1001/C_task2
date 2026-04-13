#pragma once
#include <string>

namespace BuilderSim {
    class IWorker {
    protected:
        std::string name;
        int age;

    public:
        IWorker(std::string name, int age);

        virtual ~IWorker();

        std::string getName();

        int getAge();

        virtual double getCoefficient() = 0;
    };
}
