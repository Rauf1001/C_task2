#include "Architector.h"


Architector::Architector(string name, int age): IWorker(name,age) {

}

double Architector::getCoefficient() {
    return 1.7;
}
