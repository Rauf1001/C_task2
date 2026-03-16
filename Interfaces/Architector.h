#pragma once
#include "IWorker.h"


class Architector : public IWorker {
public:
    Architector(string name, int age);

    double getCoefficient() override;

};