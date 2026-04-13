#pragma once
#include "IWorker.h"
namespace BuilderSim {
    class Ingener : public IWorkerSim::IWorker {
    public:
        Ingener(std::string name, int age);

        double getCoefficient() override;
    };
}