#include "../include/Interfaces/Ingener.h"
using namespace std;
namespace BuilderSim {
    Ingener::Ingener(string name, int age) : IWorker(name,age){

    }

    double Ingener::getCoefficient() {
        return 1.5;
    }
}

