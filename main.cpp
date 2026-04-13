#include <iostream>
#include <string>

#include "Controller.h"
#include "Interfaces/Builder.h"
#include "Controller.h"

using namespace std;
// namespace BuilderSim;
int main() {
    BuilderSim::Controller myController;
    myController.writeController();
    return 0;
}
