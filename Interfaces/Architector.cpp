#include "Architector.h"
using namespace std;

namespace BuilderSim {
    Architector::Architector(string name, int age): IWorker(name,age) {

    }

    double Architector::getCoefficient() {
        return 1.7;
    }
}