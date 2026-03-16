#pragma once
#include "IWorker.h"


class Architector : public IWorker {
    Architector(string name, int age);

    double getCoefficient() override;

};