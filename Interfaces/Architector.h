#pragma once
#include "IWorker.h"

namespace BuilderSim {
    class Architector : public IWorkerSim::IWorker {
    public:
        Architector(std::string name, int age);

        double getCoefficient() override;

    };
}