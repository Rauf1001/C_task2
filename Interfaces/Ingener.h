#pragma once
#include "IWorker.h"
namespace BuilderSim {
    class Ingener : public IWorker::IWorker {
    public:
        Ingener(std::string name, int age);

        double getCoefficient() override;
    };
}