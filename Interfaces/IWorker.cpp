#include "IWorker.h"


IWorker::IWorker(string n, int a) {
    name = n;
    age = a;
}

IWorker::~IWorker() {}

string IWorker::getName() {
    return name;
}
int IWorker::getAge() {
    return age;
}
