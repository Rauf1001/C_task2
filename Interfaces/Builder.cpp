#include "Builder.h"

Builder::Builder(string name, int age) : IWorker(name,age) {

}

double Builder::getCoefficient() {
    return 1.2;
}
