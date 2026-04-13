#pragma once
#include "IWorker.h"

namespace BuilderSim {
    class Architector : public IWorker::IWorker {
    public:
        Architector(std::string name, int age);

        double getCoefficient() override;
    };
}
