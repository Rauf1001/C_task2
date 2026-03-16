#pragma once
#include "IWorker.h"

class Builder: public IWorker {
public:
    Builder(string name, int age);

    double getCoefficient() override;
};

