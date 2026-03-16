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


// // virtual void worker(std::string name,int age);
// IWorker(std::string name, int age){}
//
// explicit IWorker(const std::string & name);а;
// virtual int koeff_return(float koeff) {
//     return koeff;
// }