#include "../include/Interfaces/Builder.h"
using namespace std;

namespace BuilderSim {
    Builder::Builder(string name, int age) : IWorker(name, age) {
    }

    double Builder::getCoefficient() {
        return 1.2;
    }
}
