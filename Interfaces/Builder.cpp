#include "Builder.h"

using namespace std;
class Builder: public IWorker {
public:
    Builder(string name, int age) : IWorker(name(name),) {
    }

    double getCoefficient(double coeff) override {
        return coeff = 1.2;
    }

};


// Builder(std::string name, int age) : IWorker(name), IWorker(age) {};
// int koeff_return(float koeff) override;
// int koef_return() override {
//     return koef = 1.2;
// }