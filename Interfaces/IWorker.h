#pragma once
#include <string>

using namespace std;

class IWorker {
protected:
    string name;
    int age;
public:
    IWorker(string name, int age);
    virtual ~IWorker();

    string getName();
    int getAge();

    virtual double getCoefficient() = 0;
};
