#include "Building.h"
#include <iostream>




class Building {
public:
    virtual ~Building() = default;

    virtual void building(std::string name, int floor, int square) {}
    virtual int phase(int phase){}

};





