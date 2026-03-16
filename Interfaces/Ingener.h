#pragma once
#include "IWorker.h"

class Ingener : public IWorker {
public:
    Ingener(string name, int age);

    double getCoefficient() override;
};


