#pragma once
#include "IWorker.h"
namespace BuilderSim {
    class Builder: public IWorkerSim::IWorker {
    public:
        Builder(std::string name, int age);

        double getCoefficient() override;
    };
}